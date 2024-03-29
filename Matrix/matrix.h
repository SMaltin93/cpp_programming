//
// DD1388 - Lab 2: The matrix
//

#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>
using namespace std;

template <typename T>
class Matrix {

     // T must be move-constructible */
     //that needs to verify that the type T is move-constructible.
    static_assert(is_move_constructible<T>::value, "T must be move-constructible");
    // T must be move-assignable */
    // that needs to verify that the type T is move-assignable.
    static_assert(is_move_assignable<T>::value, "T must be move-assignable ");
public:
    // constructors and assignment operators
    /* TODO: Make the appropriate constructor(s) explicit */
    Matrix();
    Matrix(size_t dim);
    Matrix(size_t rows, size_t cols);
    Matrix(const std::initializer_list<T> & list); 
    Matrix(Matrix<T> & other); 
    Matrix(Matrix<T> && other) noexcept; 

    Matrix<T> & operator=(const Matrix<T> & other); 
    Matrix<T> & operator=(Matrix<T> && other) noexcept;

    ~Matrix(); 

    // accessors
    size_t rows() const;
    size_t cols() const;

    T & operator()(size_t row, size_t col);
    const T & operator()(size_t row, size_t col) const;

    // operators
    Matrix<T> operator*(const Matrix<T> & other) const; 
    Matrix<T> operator+(const Matrix<T> & other) const;
    Matrix<T> operator-(const Matrix<T> & other) const;

    void operator*=(const Matrix<T> & other); 
    void operator+=(const Matrix<T> & other);
    void operator-=(const Matrix<T> & other);

    // methods
    void reset(); 

    void insert_row(size_t row);
    void append_row(size_t row);
    void remove_row(size_t row);
    void insert_column(size_t col);
    void append_column(size_t col);
    void remove_column(size_t col);

    // iterators
    typedef T* iterator;  

    iterator begin();
    iterator end();

private:
    size_t m_rows;
    size_t m_cols;
    size_t m_capacity;
    T * m_vec; // pointer to the first element of the matrix
};

// input/output operators
template<typename T>
std::istream & operator>>(std::istream & is, Matrix<T> & m);

template<typename T>
std::ostream & operator<<(std::ostream & os, const Matrix<T> & m);

// functions
template<typename T>
Matrix<T> identity(size_t dim);


//
// Implementations
//

template<typename T>
Matrix<T>::Matrix() : m_rows(0), m_cols(0), m_capacity(0), m_vec(nullptr){} 

template<typename T>
Matrix<T>::Matrix(size_t dim){
    m_rows = dim;
    m_cols = dim;
    m_capacity = dim*dim;
    m_vec = new T[m_capacity];
}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols)
/*:  Initialize members here */ {
    m_rows = rows;
    m_cols = cols;
    m_capacity = rows*cols;
    m_vec = new T[m_capacity];
}

template<typename T>
Matrix<T>::Matrix(const std::initializer_list<T> & list)
/*:  Initialize members here */ {
    //This constructor can only construct square matrices.
    //If the list is not square, throw an exception.
    if (sqrt(list.size()) != (int)sqrt(list.size())){
        throw invalid_argument("The list is not square");
    } else {

        m_rows = sqrt(list.size());
        m_cols = sqrt(list.size());
        m_capacity = list.size();
        m_vec = new T[m_capacity];
        copy(list.begin(), list.end(), m_vec);
    }


}

template<typename T>
Matrix<T>::Matrix(Matrix<T> & other) { // & means lvalue reference (copy constructor)
 // that is helpful when you want to copy the data from one object to another.
    m_rows = other.rows();
    m_cols = other.cols();
    m_capacity = other.m_capacity;
    m_vec = new T[m_capacity];
    copy(other.m_vec, other.m_vec + m_capacity, m_vec); // Copy the elements from other.m_vec to m_vec  
}

template<typename T>
Matrix<T>::Matrix(Matrix<T> && other) noexcept { // && means rvalue reference (move constructor) 
// that is helpful when you want to move the data from one object to another without copying it.
//noexcept means that the function will not throw any exceptions.
    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_capacity = other.m_capacity;
    m_vec = other.m_vec;
    other.m_rows = 0;
    other.m_cols = 0;
    other.m_capacity = 0;
    other.m_vec = nullptr;
}

template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix<T> & other) {
    m_rows = other.rows();
    m_cols = other.cols();
    m_capacity = other.m_capacity;
    m_vec = new T[m_capacity];
    copy(other.m_vec, other.m_vec + m_capacity, m_vec); // Copy the elements from other.m_vec to m_vec
    return *this;
}

template<typename T>
Matrix<T> & Matrix<T>::operator=(Matrix<T> && other) noexcept {
    m_rows = other.rows();
    m_cols = other.cols();
    m_capacity = other.m_capacity;
    m_vec = other.m_vec;
    other.m_vec = nullptr; // Set other.m_vec to nullptr to avoid double deletion
    other.m_rows = 0; // Set other.m_rows to 0
    other.m_cols = 0; // Set other.m_cols to 0
    other.m_capacity = 0; // Set other.m_capacity to 0
    return *this;
}

template<typename T>
Matrix<T>::~Matrix() {
    delete[] m_vec; // Delete the array
    m_vec = nullptr; // Set m_vec to nullptr to avoid double deletion
    m_cols = 0; // Set m_cols to 0
    m_rows = 0; // Set m_rows to 0
    m_capacity = 0; // Set m_capacity to 0                                                                                                              
}

template<typename T>
size_t Matrix<T>::rows() const {
    return m_rows; // return the number of rows
}

template<typename T>
size_t Matrix<T>::cols() const {
    return m_cols; // return the number of columns
}

template<typename T>
T & Matrix<T>::operator()(size_t row, size_t col) {
    if (row >= m_rows){
        throw out_of_range("The row out of range");
    }
    if (col >= m_cols){
        throw out_of_range("The column out of range");
    }
    return m_vec[row*m_cols + col]; // return the element at matrix(row, col)

}

template<typename T>
const T & Matrix<T>::operator()(size_t row, size_t col) const {
    return m_vec[row*m_cols + col]; // return the element at matrix(row, col)
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> & other) const {
    if (m_cols != other.m_rows) {
        throw invalid_argument("Wrong dimensions for multiplication");
    }

    Matrix<T> result(m_rows, other.m_cols); // Create a matrix with the correct dimensions

    for (int row = 0; row < m_rows; row++) {
        for (int col = 0; col < other.m_cols; col++) {
            for (int j = 0; j < m_cols; j++) {
                result.m_vec[row * result.m_cols + col] += m_vec[row * m_cols + j] * other.m_vec[j * other.m_cols + col];
            }
        }
    }
    return result;

}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & other) const {
    // addition of two matrices
    if (m_rows != other.m_rows && m_cols != other.m_cols) {
        throw invalid_argument("wrong dimensions");
    }   
    
    Matrix<T> result(m_rows, m_cols);
    for (int i = 0; i < m_capacity; i++) {
        result.m_vec[i] = m_vec[i] + other.m_vec[i];
    }
    return result;
    
    
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> & other) const {
    // subtraction of two matrices
    if (m_rows != other.m_rows && m_cols != other.m_cols) {
        throw invalid_argument("wrong dimensions");
    }   
    
    Matrix<T> result(m_rows, m_cols);
    for (int i = 0; i < m_capacity; i++) {
        result.m_vec[i] = m_vec[i] - other.m_vec[i];
    }
    return result;
}

template<typename T>
void Matrix<T>::operator*=(const Matrix<T> & other) {
   if (m_cols != other.m_rows) {
        throw invalid_argument("Wrong dimensions for multiplication");
    }
    // we nedd do m = m * m1;
    Matrix<T> result(m_rows, other.m_cols); // Create a matrix with the correct dimensions
    for (int row = 0; row < m_rows; row++) {
        for (int col = 0; col < other.m_cols; col++) {
            for (int j = 0; j < m_cols; j++) {
                result.m_vec[row * result.m_cols + col] += m_vec[row * m_cols + j] * other.m_vec[j * other.m_cols + col];
                // that mean m1(row, col) += m1(row, j) * m2(j, col);
            }
        }
    }
    // we need to move the result to m1
    *this = result; // that mean m = result 


   
}

template<typename T>
void Matrix<T>::operator+=(const Matrix<T> & other) {

    // addition of two matrices
    if (m_rows != other.m_rows && m_cols != other.m_cols) {
        throw invalid_argument("wrong dimensions");
    }   
    // we nedd do m = m + m1;
    Matrix<T> result(m_rows, m_cols);
    for (int i = 0; i < m_capacity; i++) {
        result.m_vec[i] = m_vec[i] + other.m_vec[i];
    }
    *this = result; // that mean m = result
    
}

template<typename T>
void Matrix<T>::operator-=(const Matrix<T> & other) {
    // subtraction of two matrices
    if (m_rows != other.m_rows && m_cols != other.m_cols) {
        throw invalid_argument("wrong dimensions");
    }   
    Matrix<T> result(m_rows, m_cols);
    for (int i = 0; i < m_capacity; i++) {
        result.m_vec[i] = m_vec[i] - other.m_vec[i];
    }
    *this = result; // that mean m = result
}

template<typename T>
void Matrix<T>::reset() {
    // we need to reset the matrix to zero
    *this = Matrix<T>();
}

template<typename T>
void Matrix<T>::insert_row(size_t row) {
    //Implement insert_row which inserts a row of zeroes before a given row number.
    if (row > m_rows || row < 0) {
        throw invalid_argument("out of the rang");
    }

    Matrix<T> result(m_rows + 1, m_cols);
    int newRow =0;
    for (int i = 0; i < m_rows; i++, newRow++) {
        if(row == i) {
            for (int j = 0; j < m_cols; j++) {
                result(row, j) = 0; 
            } 
            newRow = row + 1;
        }
        for(int j = 0; j < m_cols; j++) {
            result(newRow, j) = (*this)(i,j);
        }       
    }
    *this = result;
}

template<typename T>
void Matrix<T>::append_row(size_t row) {
     //we need to Implement append_row which inserts a row of zeroes after a given row number.   
    if (row > m_rows || row < 0) {
        throw invalid_argument("out of the rang");
    }
    Matrix<T> result(m_rows + 1, m_cols);
    int newRow =0;
    for (int i = 0; i < m_rows; i++, newRow++) {

        for(int j = 0; j < m_cols; j++) {
            result(newRow, j) = (*this)(i,j);
        } 
        if(row == i) {
            for (int j = 0; j < m_cols; j++) {
                result(row + 1, j) = 0; 
            } 
            newRow = row + 2;
        }      
    }
    *this = result; 
}

template<typename T>
void Matrix<T>::remove_row(size_t row) {
    // erases the entire row at a given row number.
    if (row > m_rows) {
        throw invalid_argument("Out of range");
    }
    int startRow = 0;
    for(int i = 0; i < m_rows; i++) {
        if (i != row) {
            for (int j = 0; j < m_cols; j++) {
               (*this)(startRow, j) = (*this)(i, j);
            }
            startRow++;
        }  
    }
    m_rows--;
}

template<typename T>
void Matrix<T>::insert_column(size_t col) {
    // Implement insert_column which inserts a column of zeroes before a given column number.
    if (col > m_cols || col < 0) {
        throw invalid_argument("out of the rang");
    }
    Matrix<T> result(m_rows, m_cols + 1);
    int newCol =0;
    //add the column before the given column
    for (int i = 0; i < m_cols; i++, newCol++) {
        if(col == i) {
            for (int j = 0; j < m_rows; j++) {
                result(j, col) = 0; 
            } 
            newCol = col + 1;
        }
        for(int j = 0; j < m_rows; j++) {
            result(j, newCol) = (*this)(j,i);
        }       
    }
    *this = result;
}

template<typename T>
void Matrix<T>::append_column(size_t col) {
   //Implement append_column which inserts a column of zeroes after a given column number.
     if (col > m_cols || col < 0) {
        throw invalid_argument("out of the rang");
    }
    Matrix<T> result(m_rows, m_cols + 1);
    int newCol =0;
    for (int i = 0; i < m_cols; i++, newCol++) {
         for(int j = 0; j < m_rows; j++) {
            result(j, newCol) = (*this)(j,i);
        } 
        if(col == i) {
            for (int j = 0; j < m_rows; j++) {
                result(j, col + 1 ) = 0; 
            } 
            newCol = col + 2;
        }      
    }
    *this = result;
}

template<typename T>
void Matrix<T>::remove_column(size_t col) {
    // Check if the column value is within range
    if (col >= m_cols) {
        throw invalid_argument("Out of range");
    }
    // Create a new matrix with updated number of columns
    Matrix<T> newMatrix(m_rows, m_cols - 1);
    // Copy all elements from the matrix excluding the specified column
    for (int i = 0; i < m_rows; i++) {
        int newCol = 0;
        for (int j = 0; j < m_cols; j++) {
            if (j == col) {
                continue;
            }
            newMatrix(i, newCol) = (*this)(i, j);
            newCol++;
        }
    }
    // Replace the old matrix with the new matrix
    *this = newMatrix;
}

template<typename T>
typename Matrix<T>::iterator Matrix<T>::begin() {
   //returns the pointer to the first element of the matrix.
    return m_vec; // return the iterator to the first element
}

template<typename T>
typename Matrix<T>::iterator Matrix<T>::end() {
    //returns the pointer to the element after the last element 
    return m_vec + m_rows * m_cols; // 
}

template<typename T>
std::istream & operator>>(std::istream & is, Matrix<T> & m) {
    // implement operator >> to read a matrix from an input stream, that is like when we use cin >> m; 
    int rows, cols;
    is >> rows >> cols; // read the number of rows and columns from the input stream
    m = Matrix<T>(rows, cols); //  set the matrix to the correct size
    for (int i = 0; i < rows; i++) { // loop through the rows
        for (int j = 0; j < cols; j++) { // loop through the columns
            is >> m(i, j); // read the value from the input stream
        }
    }
    return is;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, const Matrix<T> & m) {
    // implement operator << to print a matrix to an output stream, that is like when we use cout << m;
    os << m.rows() << " " << m.cols() << endl; // print the number of rows and columns to the output stream
    for (int i = 0; i < m.rows(); i++) { // loop through the rows
        for (int j = 0; j < m.cols(); j++) { // loop through the columns
            os << m(i, j) << " "; // print the value to the output stream
        }
        os << endl; // print a new line
    }
    return os;
}

template<typename T>
Matrix<T> identity(size_t dim) {
    Matrix<T> result(dim, dim);
    for (int i = 0; i < dim; i++) {
        result(i, i) = 1;
    }
    return result;
}

#endif //MATRIX_H