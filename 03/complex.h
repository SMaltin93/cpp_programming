
#include <bits/stdc++.h>

using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H



class Complex {
    
    public: 
      Complex();
      Complex(double real); //not : make it non explicit
      constexpr explicit Complex(double, double );
      // constexpr explicit Complex(double real, double imaginary) : real(real), imag(imaginary) {}
      Complex(const Complex &rhs); // copy constructor
      Complex(Complex && rhs) noexcept; // move constructor
      
      // assignment operators
      Complex& operator=(const Complex &rhs);
      Complex& operator=(Complex &&rhs) noexcept;

      
      // unary operators
      Complex operator-() const;
      Complex operator+() const;

      // arithmetic operators
      Complex operator+(const Complex &rhs) const;
      // handel Complex k = 1 + 5_i;
      // // friend means that this function can access private members of the class, for example, Complex::real and Complex::imag in this case.
    

      Complex operator-(const Complex &rhs) const;
      Complex operator*(const Complex &rhs) const;
      //multiplcation operator for scalar multiplication
      Complex operator*(const double &scalar ) const;
      Complex operator/(const Complex &rhs) const;

      void operator+=(const Complex &rhs);
      void operator-=(const Complex &rhs);
      void operator*=(const Complex &rhs);
      //multiplication operator for scalar multiplication
      void operator*=(const double &scalar);

      void operator/=(const Complex &rhs);

      // comparison operators
      bool operator==(const Complex &rhs) const;
      bool operator!=(const Complex &rhs) const;

      double  getReal() const;
      double  getImag() const;

      // return magnitude of complex number
      double abs() const;
      
      bool operator<(const Complex &rhs) const;

    private:
        double real;
        double imag;

};

#endif 


