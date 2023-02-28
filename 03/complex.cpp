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

//unary operators

template <typename T>
Complex<T> Complex<T>::operator-() const{
    Complex<T> temp;
    temp.real = -this->real;
    temp.imag = -this->imag;
    return temp;
}

template <typename T>
Complex<T> Complex<T>::operator+() const{
    Complex<T> temp;
    temp.real = this->real;
    temp.imag = this->imag;
    return temp;
}

//arithmetic operators
template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T> &rhs) const{
    Complex<T> temp;
    temp.real = this->real + rhs.real;
    temp.imag = this->imag + rhs.imag;
    return temp;
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

 
 

// void operator-=(const Complex<T> &rhs);
template <typename T>
void Complex<T>::operator-=(const Complex<T> &rhs) {
    this->real = this->real - rhs.real; 
    this->imag = this->imag - rhs.imag;

}

// void operator*=(const Complex<T> &rhs);
template <typename T>
void Complex<T>::operator*=(const Complex<T> &rhs) {
    Complex<T> temp;
    temp.real = this->real * rhs.real - this->imag * rhs.imag;
    temp.imag = this->real * rhs.imag + this->imag * rhs.real;
    *this = temp; 
}

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
Complex<T> Complex<T>::operator==(const Complex<T> &rhs) const {
    return (this->real == rhs.real && this->imag == rhs.imag);
}

// Complex<T> operator!=(const Complex<T> &rhs) const;
template <typename T>
Complex<T> Complex<T>::operator!=(const Complex<T> &rhs) const {
    return (this->real != rhs.real && this->imag != rhs.imag);
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
double Complex<T>::magnitude() const{
    return sqrt( pow(this->real, 2.0) + pow(this->imag, 2.0) );
}

// comparison operators
template <typename T>
bool Complex<T>::operator<(const Complex<T> &rhs) const { // the formula is if |a+bi| < |c+di| then a^2+b^2 < c^2+d^2
    return (this->magnitude() < rhs.magnitude()); 
}
