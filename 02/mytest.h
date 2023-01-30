// mytest.h
#include <cxxtest/TestSuite.h>
#include "matrix.h"

class MyTestSuite : public CxxTest::TestSuite {
   
public: 
    void testDefaultConstructor() {  //  Matrix() 1
        Matrix<int> m;
        TS_ASSERT_EQUALS(m.rows(), 0);
        TS_ASSERT_EQUALS(m.cols(), 0);
    }
    void testDimensionConstructor() { // Matrix(size_t dim); 2
        Matrix<int> m(2, 3);
        TS_ASSERT_EQUALS(m.rows(), 2);
        TS_ASSERT_EQUALS(m.cols(), 3);
    }

    void testRowColumnConstructor() { // Matrix(size_t rows, size_t cols); 3
        Matrix<int> m(2);
        TS_ASSERT_EQUALS(m.rows(), 2);
        TS_ASSERT_EQUALS(m.cols(), 2);
    }
    void testInitializerListConstructor() { // Matrix(const std::initializer_list<T> & list); 4
        Matrix<int> m = {1, 2, 3, 4};
        TS_ASSERT_EQUALS(m.rows(), 2);
        TS_ASSERT_EQUALS(m.cols(), 2);
        TS_ASSERT_EQUALS(m(0, 0), 1);
        TS_ASSERT_EQUALS(m(0, 1), 2);
        TS_ASSERT_EQUALS(m(1, 0), 3);
        TS_ASSERT_EQUALS(m(1, 1), 4);
    }

    void testCopyConstructor() { // Matrix(Matrix<T> & other); 5
        Matrix<int> m1({1, 2, 3, 4});
        Matrix<int> m2(m1);
        TS_ASSERT_EQUALS(m1.rows(), m2.rows());
        TS_ASSERT_EQUALS(m1.cols(), m2.cols());
        for (int i = 0; i < m1.rows(); i++){
            for (int j = 0; j < m1.cols(); j++){
                TS_ASSERT_EQUALS(m1(i, j), m2(i, j));
            }
        }
    }


    void testMoveConstructor() { // Matrix(Matrix<T> && other) noexcept; 6
        Matrix<int> m1(1, 2); // 1 row, 2 columns
        Matrix<int> m2(std::move(m1)); // move constructor
        TS_ASSERT_EQUALS(m1.rows(), 0);
        TS_ASSERT_EQUALS(m1.cols(), 0);
        TS_ASSERT_EQUALS(m2.rows(), 1);
        TS_ASSERT_EQUALS(m2.cols(), 2);
    }
    
    void testOperatorEqual() { // Matrix<T> & operator=(const Matrix<T> & other); 7
        Matrix<int> m1({1, 2, 3, 4});
        Matrix<int> m2 = m1;
        TS_ASSERT_EQUALS(m1.rows(), m2.rows());
        TS_ASSERT_EQUALS(m1.cols(), m2.cols());
        for (int i = 0; i < m1.rows(); i++){
            for (int j = 0; j < m1.cols(); j++){
                TS_ASSERT_EQUALS(m1(i, j), m2(i, j));
            }
        }
    }

    void testOperatorEqualMove() { // Matrix<T> & operator=(Matrix<T> && other) noexcept; 8
        Matrix<int> m1(1, 2); // 1 row, 2 columns
        Matrix<int> m2 = std::move(m1); // move constructor
        TS_ASSERT_EQUALS(m1.rows(), 0);
        TS_ASSERT_EQUALS(m1.cols(), 0);
        TS_ASSERT_EQUALS(m2.rows(), 1);
        TS_ASSERT_EQUALS(m2.cols(), 2);
    }
    // ~Matrix();   
    void testDestructor() { // ~Matrix(); 9
        Matrix<int> *m = new Matrix<int>(1, 2);
        delete m;
        // the program should not crash or produce any memory errors if the destructor is implemented correctly
    }

    // accessors###########################accessors ######################accessors#########

    void testRows() { // size_t rows() const; 10
        Matrix<int> m(1, 2);
        TS_ASSERT_EQUALS(m.rows(), 1);
    }
    void testCols() { // size_t cols() const; 11
        Matrix<int> m(1, 2);
        TS_ASSERT_EQUALS(m.cols(), 2);
    }
    
    void testOperatorParenthesis() { // T & operator()(size_t row, size_t col); 12
        Matrix<int> m(10, 20);
        m(5, 5) = 1;
        m(0, 1) = 2;
        TS_ASSERT_EQUALS(m(5, 5), 1);
        TS_ASSERT_EQUALS(m(0, 1), 2);
    }
    // const T & operator()(size_t row, size_t col) const;
    void testOperatorParenthesisConst() { // const T & operator()(size_t row, size_t col) const; 13
        Matrix<int> m(10, 20);
        m(0, 0) = 1;
        m(0, 1) = 2;
        const Matrix<int> &m2 = m; // const reference to m
        TS_ASSERT_EQUALS(m2(0, 0), 1);
        TS_ASSERT_EQUALS(m2(0, 1), 2);
    }

    
    // operators###########################operators######################operators#########
    
    
    void testMultiplicationOperator () {   // Matrix<T> operator*(const Matrix<T> & other) const; 14
        // 1 2  1 2   =   3 6 
        // 1 2  1 2       3 6
        
        Matrix<int> m1({1, 2, 1, 2});
        Matrix<int> m2({1, 2, 1, 2});
        Matrix<int> m3 = m2 * m1;
        TS_ASSERT_EQUALS(m3.rows(), 2);
        TS_ASSERT_EQUALS(m3.cols(), 2);
        TS_ASSERT_EQUALS(m3(0, 0), 3);
        TS_ASSERT_EQUALS(m3(0, 1), 6);
        TS_ASSERT_EQUALS(m3(1, 0), 3);
        TS_ASSERT_EQUALS(m3(1, 1), 6);
    }
    // Matrix<T> operator+(const Matrix<T> & other) const;
    void testAdditionOperator () {   // Matrix<T> operator+(const Matrix<T> & other) const; 15
        // 1 2  1 2   =   2 4 
        // 1 2  1 2       2 4
        Matrix<int> m1({1, 2, 1, 2});
        Matrix<int> m2({1, 2, 1, 2});
        Matrix<int> m3 = m1 + m2;
        TS_ASSERT_EQUALS(m3.rows(), 2);
        TS_ASSERT_EQUALS(m3.cols(), 2);
    }
    // Matrix<T> operator-(const Matrix<T> & other) const;

    // void operator*=(const Matrix<T> & other); 
    // void operator+=(const Matrix<T> & other);
    // void operator-=(const Matrix<T> & other);


};