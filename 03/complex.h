
#include <bits/stdc++.h>

using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H


template <typename T>
class Complex {
    
    public: 
      Complex();
      Complex(double  real); //not : make it non explicit
      Complex(double  real, double imag);
      Complex(const Complex &rhs); // copy constructor
      Complex(Complex && rhs) noexcept; // move constructor
      
      // assignment operators
      Complex<T> & operator=(const Complex<T> &rhs);
      Complex<T> & operator=(Complex<T> &&rhs) noexcept;

      
      // unary operators
      Complex<T> operator-() const;
      Complex<T> operator+() const;

      // arithmetic operators
      Complex<T> operator+(const Complex<T> &rhs) const;
      Complex<T> operator-(const Complex<T> &rhs) const;
      Complex<T> operator*(const Complex<T> &rhs) const;
      Complex<T> operator/(const Complex<T> &rhs) const;

      void operator+=(const Complex<T> &rhs);
      void operator-=(const Complex<T> &rhs);
      void operator*=(const Complex<T> &rhs);
      void operator/=(const Complex<T> &rhs);



      // comparison operators
      Complex<T> operator==(const Complex<T> &rhs) const;
      Complex<T> operator!=(const Complex<T> &rhs) const;

      double  getReal() const;
      double  getImag() const;

      // return magnitude of complex number
      double magnitude() const;
      
      
      bool operator<(const Complex<T> &rhs) const;

      // 	Writes to output stream the complex number in the form (real,imaginary)
      // 	Reads from input stream the complex number in the form (real,imaginary)
      istream & operator>>(istream &in, Complex<T> &rhs);
      ostream & operator<<(ostream &out, const Complex<T> &rhs);

      // Forms a complex literal representing an imaginary number (note the underscore)

      Complex<T> operator"" _i(long double imag);

    private:
        double  real;
        double  imag;

};
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
double  Complex<T>::getReal() const{
    return this->real;
}

template <typename T>
double  Complex<T>::getImag() const{
    return this->imag;
}
#endif 


