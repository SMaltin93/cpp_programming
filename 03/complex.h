
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

      // // return magnitude of complex number
      // double magnitude() const;
      
      
      // bool operator<(const Complex<T> &rhs) const;

      // // 	Writes to output stream the complex number in the form (real,imaginary)
      // // 	Reads from input stream the complex number in the form (real,imaginary)
      // istream & operator>>(istream &in, Complex<T> &rhs);
      // ostream & operator<<(ostream &out, const Complex<T> &rhs);

      // // Forms a complex literal representing an imaginary number (note the underscore)

      // Complex<T> operator"" _i(long double imag);

    private:
        double real;
        double imag;

};

#endif 


