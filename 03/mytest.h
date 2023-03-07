
#include <cxxtest/TestSuite.h>
#include <bits/stdc++.h>

#include "complex.cpp"
using namespace std;

class MyTestSuite : public CxxTest::TestSuite {
   
public:  
      //test default constructor¨
   void testDefaultConstructor(void) {
       Complex<double> c;
       TS_ASSERT_EQUALS(c.getReal(), 0);
       TS_ASSERT_EQUALS(c.getImag(), 0);
   }
   // test constructor with real part
    void testConstructorWithRealPart(void) {
         Complex<double> c(1.0);
         TS_ASSERT_EQUALS(c.getReal(), 1.0);
         TS_ASSERT_EQUALS(c.getImag(), 0);
    }

    // test constructor with real and imaginary part
    void testConstructorWithRealAndImaginaryPart(void) {
         Complex<double> c(1.0, 2.0);
         TS_ASSERT_EQUALS(c.getReal(), 1.0);
         TS_ASSERT_EQUALS(c.getImag(), 2.0);
    }

   // test copy constructor
    void testCopyConstructor(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(c1);
         TS_ASSERT_EQUALS(c2.getReal(), 1.0);
         TS_ASSERT_EQUALS(c2.getImag(), 2.0);
    }

     // test move constructor
    void testMoveConstructor(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(std::move(c1));
         TS_ASSERT_EQUALS(c2.getReal(), 1.0);
         TS_ASSERT_EQUALS(c2.getImag(), 2.0);
         TS_ASSERT_EQUALS(c1.getReal(), 0.0);
         TS_ASSERT_EQUALS(c1.getImag(), 0.0);
    }

     // test assignment operator
    void testAssignmentOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2 = c1;
         TS_ASSERT_EQUALS(c2.getReal(), 1.0);
         TS_ASSERT_EQUALS(c2.getImag(), 2.0);
    }

     // test move assignment operator
    void testMoveAssignmentOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2 = std::move(c1);
         TS_ASSERT_EQUALS(c2.getReal(), 1.0);
         TS_ASSERT_EQUALS(c2.getImag(), 2.0);
         TS_ASSERT_EQUALS(c1.getReal(), 0.0);
         TS_ASSERT_EQUALS(c1.getImag(), 0.0);
    }
     
          // test addition operator
    void testAdditionOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(3.0, 4.0);
         Complex<double> c3 = c1 + c2;
         TS_ASSERT_EQUALS(c3.getReal(), 4.0);
         TS_ASSERT_EQUALS(c3.getImag(), 6.0);
    }

     // test subtraction operator
    void testSubtractionOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(3.0, 4.0);
         Complex<double> c3 = c1 - c2;
         TS_ASSERT_EQUALS(c3.getReal(), -2.0);
         TS_ASSERT_EQUALS(c3.getImag(), -2.0);
    }

     // test multiplication operator
    void testMultiplicationOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(3.0, 4.0);
         Complex<double> c3 = c1 * c2;
         TS_ASSERT_EQUALS(c3.getReal(), -5.0);
         TS_ASSERT_EQUALS(c3.getImag(), 10.0);
    }

    // test scalar multiplication operator
     void testScalarMultiplicationOperator(void) {
           Complex<double> c1(1.0, 2.0);
           Complex<double> c2 = c1 * 2.0;
           TS_ASSERT_EQUALS(c2.getReal(), 2.0);
           TS_ASSERT_EQUALS(c2.getImag(), 4.0);
     }
     // test division operator
     void testDivisionOperator(void) {
           Complex<double> c1(1.0, 2.0);
           Complex<double> c2(3.0, 4.0);
           Complex<double> c3 = c1 / c2;
           TS_ASSERT_EQUALS(c3.getReal(), 0.44);
           TS_ASSERT_EQUALS(c3.getImag(), 0.08);
     }

     // test operator+= 
     void testOperatorPlusEqual(void) {
           Complex<double> c1(1.0, 2.0);
           Complex<double> c2(3.0, 4.0);
           c1 += c2;
           TS_ASSERT_EQUALS(c1.getReal(), 4.0);
           TS_ASSERT_EQUALS(c1.getImag(), 6.0);
     }

     // test operator-=
     void testOperatorMinusEqual(void) {
           Complex<double> c1(1.0, 2.0);
           Complex<double> c2(3.0, 4.0);
           c1 -= c2;
           TS_ASSERT_EQUALS(c1.getReal(), -2.0);
           TS_ASSERT_EQUALS(c1.getImag(), -2.0);
     }

     // test operator*=
     void testOperatorMultiplyEqual(void) {
          Complex<double> c1(1.0, 2.0);
          Complex<double> c2(3.0, 4.0);
          c1 *= c2;
          TS_ASSERT_EQUALS(c1.getReal(), -5.0);
          TS_ASSERT_EQUALS(c1.getImag(), 10.0);     
     }

     
     // test operator/=


     // test equality operator
     void testEqualityOperator(void) {
           Complex<double> c1(1.0, 2.0);
           Complex<double> c2(3.0, 4.0);
           Complex<double> c3(1.0, 2.0);
           TS_ASSERT_EQUALS(c1 == c2, false);
           TS_ASSERT_EQUALS(c1 == c3, true);
     }

     // test inequality operator
     void testInequalityOperator(void) {
           Complex<double> c1(1.0, 2.0);
           Complex<double> c2(3.0, 4.0);
           Complex<double> c3(1.0, 2.0);
           TS_ASSERT_EQUALS(c1 != c2, true);
           TS_ASSERT_EQUALS(c1 != c3, false);
     }

     // test getter 
     void testGetter(void) {
          Complex<double> c1(1.0,2.0);
          TS_ASSERT_EQUALS(c1.getReal(), 1.0);
          TS_ASSERT_EQUALS(c1.getImag(), 2.0);
     } 

     // test magintude
     void testMagnitude(void) {
          Complex<double> c1(3.0, 4.0);
          TS_ASSERT_EQUALS(c1.abs(), 5.0);
     }

     // test operator< 
     void testOperatorLessThan(void) {
          Complex<double> c1(1.0, 2.0); // it is 1+2i
          Complex<double> c2(3.0, 4.0); // it is 3+4i
          TS_ASSERT_EQUALS(c1 < c2, true);
     } 

     // test operator <<

     void testOperatorOutStream(void) {
          Complex<double> c1(1.0, 2.0);
          ostringstream os;
          os << c1;
          TS_ASSERT_EQUALS(os.str(), "(1,2)");
     }

     // test operator >>
     void testOperatorInStream(void){
          Complex<double> c1(1.0, 2.0);
          // test (1,2)
          istringstream is("(1,2)");
          is >> c1;
          TS_ASSERT_EQUALS(c1.getReal(), 1.0);
          TS_ASSERT_EQUALS(c1.getImag(), 2.0);

          // test (1)
          istringstream is2("(1)");
          is2 >> c1;
          TS_ASSERT_EQUALS(c1.getReal(), 1.0);
          TS_ASSERT_EQUALS(c1.getImag(), 0.0);

          // test 1
          istringstream is3("1");
          is3 >> c1;
          TS_ASSERT_EQUALS(c1.getReal(), 1.0);
          TS_ASSERT_EQUALS(c1.getImag(), 0.0);
     }

     // test operator""_i 
     void testOperator_i(void) {
          Complex<double> c1 = 1_i;
          TS_ASSERT_EQUALS(c1.getReal(), 0.0);
          TS_ASSERT_EQUALS(c1.getImag(), 1.0);
     }

     // Basic test examples
     // Complex x2 = 5;
     // Complex y(6, 2);
     // Complex z = x + y;
     // Complex k = 3 + 5_i;
     // k -= 5 + 1_i * Complex(5, 3);
     // std::cout << Complex(6, 6) / 6 << std::endl;

     void basicTestExample(void) {
     
          // Complex k = 3 + 5_i;
          Complex<double> k = 3 + 5_i;
          TS_ASSERT_EQUALS(k.getReal(), 3.0);
          TS_ASSERT_EQUALS(k.getImag(), 5.0);
          
          // k -= 5 + 1_i * Complex(5, 3);
          k -= 5 + 1_i * Complex<double>(5, 3); // that means 3 + 5_i - (5 + 1_i * (5 + 3_i)) = -7 + 2_i 
          TS_ASSERT_EQUALS(k.getReal(), -7.0);
          TS_ASSERT_EQUALS(k.getImag(), 2.0);
          
          // test complex(6, 6) / 6 
          Complex<double> c1 = Complex<double>(6, 6) / 6;
          TS_ASSERT_EQUALS(c1.getReal(), 1.0);
          TS_ASSERT_EQUALS(c1.getImag(), 1.0);
     }

};