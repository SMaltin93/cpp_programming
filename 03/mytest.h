
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

    void testConstructorWithRealAndImaginaryPart(void) {
         Complex<double> c(1.0, 2.0);
         TS_ASSERT_EQUALS(c.getReal(), 1.0);
         TS_ASSERT_EQUALS(c.getImag(), 2.0);
    }
};