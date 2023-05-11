#include <bits/stdc++.h>

#include "complex.h"


using namespace std; 


Complex::Complex(){
    this->real = 0;
    this->imag = 0;
}

Complex::Complex(double real) : real(real), imag(0) {}

constexpr Complex::Complex(double real, double imag) : real(real), imag(imag) {}
//copy constructor
Complex::Complex(const Complex &rhs) : real(rhs.real), imag(rhs.imag) {}



//move constructor
Complex::Complex(Complex && rhs) noexcept{ 
    this->real = rhs.real;
    this->imag = rhs.imag;
    rhs.real = 0;
    rhs.imag = 0;
}

//assignment operators


Complex & Complex::operator=(const Complex &rhs){
    this->real = rhs.real;
    this->imag = rhs.imag;
    return *this;
}


Complex & Complex::operator=(Complex &&rhs) noexcept{
    this->real = rhs.real;
    this->imag = rhs.imag;
    rhs.real = 0;
    rhs.imag = 0;
    return *this;
}

//unary operators


Complex Complex::operator-() const{
    -this->real;
    -this->imag;
    return *this;
}


Complex Complex::operator+() const{
    this->real;
    this->imag;
    return *this;
}




//arithmetic operators

Complex Complex::operator+(const Complex &rhs) const{
    Complex temp;
    temp.real = this->real + rhs.real;
    temp.imag = this->imag + rhs.imag;
    return temp;
}
// handel Complex k = 1 + 5_i;


Complex operator+(const double &lhs, const Complex &rhs){
    return Complex(lhs + rhs.getReal(), rhs.getImag());
}


Complex Complex::operator-(const Complex &rhs) const{
    Complex temp; 
    temp.real = this->real - rhs.real; 
    temp.imag = this->imag - rhs.imag;
    return temp;
}


Complex Complex::operator*(const Complex &rhs) const{ // the formula is (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    Complex temp;
    temp.real = this->real * rhs.real - this->imag * rhs.imag;
    temp.imag = this->real * rhs.imag + this->imag * rhs.real;
    return temp;
}

// multiplikation for scalar

Complex Complex::operator*(const double &scal) const{ //
    return Complex(this->real * scal, this->imag * scal);
}


Complex Complex::operator/(const Complex &rhs) const{ // the formula is (a+bi)/(c+di) = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i
    Complex temp;
    temp.real = (this->real * rhs.real + this->imag * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    temp.imag = (this->imag * rhs.real - this->real * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    return temp; 
}

// void operator+=(const Complex<T> &rhs);

void Complex::operator+=(const Complex &rhs) {
    this->real = this->real + rhs.real ;
    this->imag = this->imag + rhs.imag;
} 

// example Examples of things that should work.
void Complex::operator-=(const Complex &rhs) {
    this->real -= rhs.real ;
    this->imag -= rhs.imag;
}

// void operator*=(const Complex<T> &rhs);

void Complex::operator*=(const Complex &rhs) {
    Complex temp;
    temp.real = this->real * rhs.real - this->imag * rhs.imag;
    temp.imag = this->real * rhs.imag + this->imag * rhs.real;
    *this = temp;
}

// multiplication operator with scalar
// Complex<T> operator*(const Complex<T> &scal) const; // scalar multiplication

void Complex::operator*=(const double &scalar){
    this->real *= scalar;
    this->imag *= scalar;
}


void Complex::operator/=(const Complex &rhs) {
    Complex temp;
    temp.real = (this->real * rhs.real + this->imag * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    temp.imag = (this->imag * rhs.real - this->real * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    *this = temp; 
}


// // comparison operators

bool Complex::operator==(const Complex &rhs) const {
    return (this->real == rhs.real && this->imag == rhs.imag);
}


bool Complex::operator!=(const Complex &rhs) const {
    return !(this->real == rhs.real && this->imag == rhs.imag);
}


//getter 

double Complex::getReal() const{
    return this->real;
}


double Complex::getImag() const{
    return this->imag;
}


// // return magnitude of complex number

double Complex::abs()  const{
    return sqrt( pow(this->real, 2) + pow(this->imag, 2) );
}

// comparison operators

bool Complex::operator<(const Complex &rhs) const { // the formula is  |a+bi| < |c+di| 
    return (this->abs() < rhs.abs() ); 
}

// input and output operators
// Writes to output stream the complex number in the form (real,imaginary)


ostream & operator<<(ostream & os, const Complex &rhs){
    os << "(" << rhs.getReal() << "," << rhs.getImag() << ")";
    return os;
}

// 	Reads a complex number from is. The supported formats are real, (real) and (real,imaginary) Where the input must be convertible to Double

istream & operator>>(istream & is, Complex &rhs) {
    char c; // for the brackets
    double real, imag; 
    is >> c;
    if (c == '(') {
        is >> real >> c;
        if (c == ',') {
            is >> imag >> c;
            rhs = Complex(real, imag);
        } else {
            imag = 0;
            rhs = Complex(real, imag);
        }
    } else {
        is >> real;
        imag = 0;
        rhs = Complex(real, imag);
    }
    return is; 
} 

constexpr Complex operator""_i (long double arg) {
  return Complex{0, static_cast<double>(arg)};
}
 