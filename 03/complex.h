
#include <bits/stdc++.h>

using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H


template <typename T>
class Complex {
    
    public: 
      Complex();
      Complex(double real); //not : make it non explicit
      Complex(double real, double imag);
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
      // handel Complex k = 1 + 5_i;
      // // friend means that this function can access private members of the class, for example, Complex::real and Complex::imag in this case.
    

      Complex<T> operator-(const Complex<T> &rhs) const;
      Complex<T> operator*(const Complex<T> &rhs) const;
      //multiplication operator for scalar multiplication
      Complex<T> operator*(const double &scalar ) const;
      Complex<T> operator/(const Complex<T> &rhs) const;

      void operator+=(const Complex<T> &rhs);
      void operator-=(const Complex<T> &rhs);
      void operator*=(const Complex<T> &rhs);
      //multiplication operator for scalar multiplication
      void operator*=(const double &scalar);

      void operator/=(const Complex<T> &rhs);



      // comparison operators
      bool operator==(const Complex<T> &rhs) const;
      bool operator!=(const Complex<T> &rhs) const;

      double  getReal() const;
      double  getImag() const;

      // return magnitude of complex number
      double abs() const;
      
      bool operator<(const Complex<T> &rhs) const;

    private:
        double real;
        double imag;

};

#endif 


