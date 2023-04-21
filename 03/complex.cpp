#include <bits/stdc++.h>

#include "complex.h"


using namespace std; 

template <typename T>
Complex<T>::Complex(){
    this->real = 0;
    this->imag = 0;
}

template <typename T>
Complex<T>::Complex(double real){
    this->real = real;
    this->imag = 0;
}

template <typename T>
Complex<T>::Complex(double  real, double imag){
    this->real = real;
    this->imag = imag;
}

//copy constructor
template <typename T>
Complex<T>::Complex(const Complex &rhs){
    this->real = rhs.real;
    this->imag = rhs.imag;
}

//move constructor

template <typename T>
Complex<T>::Complex(Complex && rhs) noexcept{ 
    this->real = rhs.real;
    this->imag = rhs.imag;
    rhs.real = 0;
    rhs.imag = 0;
}

//assignment operators



template <typename T>
Complex<T> & Complex<T>::operator=(const Complex<T> &rhs){
    this->real = rhs.real;
    this->imag = rhs.imag;
    return *this;
}

template <typename T>
Complex<T> & Complex<T>::operator=(Complex<T> &&rhs) noexcept{
    this->real = rhs.real;
    this->imag = rhs.imag;
    rhs.real = 0;
    rhs.imag = 0;
    return *this;
}

// 


//unary operators

template <typename T>
Complex<T> Complex<T>::operator-() const{
    -this->real;
    -this->imag;
}

template <typename T>
Complex<T> Complex<T>::operator+() const{
    this->real;
    this->imag;
}




//arithmetic operators
template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T> &rhs) const{
    Complex<T> temp;
    temp.real = this->real + rhs.real;
    temp.imag = this->imag + rhs.imag;
    return temp;
}
// handel Complex k = 1 + 5_i;

template <typename T>
Complex<T> operator+(const double &lhs, const Complex<T> &rhs){
    return Complex<T>(lhs + rhs.getReal(), rhs.getImag());
}

template <typename T>
Complex<T> Complex<T>::operator-(const Complex<T> &rhs) const{
    Complex<T> temp; 
    temp.real = this->real - rhs.real; 
    temp.imag = this->imag - rhs.imag;
    return temp;
}

template <typename T>
Complex<T> Complex<T>::operator*(const Complex<T> &rhs) const{ // the formula is (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    Complex<T> temp;
    temp.real = this->real * rhs.real - this->imag * rhs.imag;
    temp.imag = this->real * rhs.imag + this->imag * rhs.real;
    return temp;
}

// multiplikation for scalar
template <typename T>
Complex<T> Complex<T>::operator*(const double &scal) const{ //
    return Complex<T>(this->real * scal, this->imag * scal);
}

template <typename T>
Complex<T> Complex<T>::operator/(const Complex<T> &rhs) const{ // the formula is (a+bi)/(c+di) = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i
    Complex<T> temp;
    temp.real = (this->real * rhs.real + this->imag * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    temp.imag = (this->imag * rhs.real - this->real * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    return temp; 
}

// void operator+=(const Complex<T> &rhs);
template <typename T>
void Complex<T>::operator+=(const Complex<T> &rhs) {
    this->real = this->real + rhs.real ;
    this->imag = this->imag + rhs.imag;
} 

 
 
// example Examples of things that should work.

template <typename T>
void Complex<T>::operator-=(const Complex<T> &rhs) {
    this->real -= rhs.real ;
    this->imag -= rhs.imag;
}

// void operator*=(const Complex<T> &rhs);
template <typename T>
void Complex<T>::operator*=(const Complex<T> &rhs) {
    Complex<T> temp;
    temp.real = this->real * rhs.real - this->imag * rhs.imag;
    temp.imag = this->real * rhs.imag + this->imag * rhs.real;
    *this = temp;
}

// multiplication operator with scalar
// Complex<T> operator*(const Complex<T> &scal) const; // scalar multiplication
template <typename T>
void Complex<T>::operator*=(const double &scalar){
    this->real *= scalar;
    this->imag *= scalar;
}
// vod operator *=(const Complex<T> &scal); // scalar multiplication


// void operator/=(const Complex<T> &rhs);
template <typename T>
void Complex<T>::operator/=(const Complex<T> &rhs) {
    Complex<T> temp;
    temp.real = (this->real * rhs.real + this->imag * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    temp.imag = (this->imag * rhs.real - this->real * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    *this = temp; 
}


// // comparison operators
template <typename T>
bool Complex<T>::operator==(const Complex<T> &rhs) const {
    return (this->real == rhs.real && this->imag == rhs.imag);
}

template <typename T>
bool Complex<T>::operator!=(const Complex<T> &rhs) const {
    return !(this->real == rhs.real && this->imag == rhs.imag);
}



//getter 
template <typename T>
double Complex<T>::getReal() const{
    return this->real;
}

template <typename T>
double Complex<T>::getImag() const{
    return this->imag;
}


// // return magnitude of complex number

// double magnitude() const;
template <typename T>
double Complex<T>::abs()  const{
    return sqrt( pow(this->real, 2) + pow(this->imag, 2) );
}

// comparison operators
template <typename T>
bool Complex<T>::operator<(const Complex<T> &rhs) const { // the formula is  |a+bi| < |c+di| 
    return (this->abs() < rhs.abs() ); 
}

// input and output operators
// Writes to output stream the complex number in the form (real,imaginary)

template <typename T>
ostream & operator<<(ostream & os, const Complex<T> &rhs){
    os << "(" << rhs.getReal() << "," << rhs.getImag() << ")";
    return os;
}

// 	Reads a complex number from is. The supported formats are real, (real) and (real,imaginary) Where the input must be convertible to Double

template <typename T>
istream & operator>>(istream & is, Complex<T> &rhs) {
    char c; // for the brackets
    double real, imag; 
    is >> c;
    if (c == '(') {
        is >> real >> c;
        if (c == ',') {
            is >> imag >> c;
            rhs = Complex<T>(real, imag);
        } else {
            imag = 0;
            rhs = Complex<T>(real, imag);
        }
    } else {
        is >> real;
        imag = 0;
        rhs = Complex<T>(real, imag);
    }
    return is; 
} 

// insperations from https://en.cppreference.com/w/cpp/numeric/complex/operator%22%22i
 Complex<double> operator""_i(unsigned long long imag) {
    return Complex<double>(0, imag);
}

 