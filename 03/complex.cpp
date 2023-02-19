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

//getter 
template <typename T>
double Complex<T>::getReal() const{
    return this->real;
}

template <typename T>
double Complex<T>::getImag() const{
    return this->imag;
}
