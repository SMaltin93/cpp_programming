
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

    void testCopyConstructor(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(c1);
         TS_ASSERT_EQUALS(c2.getReal(), 1.0);
         TS_ASSERT_EQUALS(c2.getImag(), 2.0);
    }

    void testMoveConstructor(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(std::move(c1));
         TS_ASSERT_EQUALS(c2.getReal(), 1.0);
         TS_ASSERT_EQUALS(c2.getImag(), 2.0);
         TS_ASSERT_EQUALS(c1.getReal(), 0.0);
         TS_ASSERT_EQUALS(c1.getImag(), 0.0);
    }

    void testAssignmentOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2 = c1;
         TS_ASSERT_EQUALS(c2.getReal(), 1.0);
         TS_ASSERT_EQUALS(c2.getImag(), 2.0);
    }

    void testMoveAssignmentOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2 = std::move(c1);
         TS_ASSERT_EQUALS(c2.getReal(), 1.0);
         TS_ASSERT_EQUALS(c2.getImag(), 2.0);
         TS_ASSERT_EQUALS(c1.getReal(), 0.0);
         TS_ASSERT_EQUALS(c1.getImag(), 0.0);
    }

    void testAdditionOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(3.0, 4.0);
         Complex<double> c3 = c1 + c2;
         TS_ASSERT_EQUALS(c3.getReal(), 4.0);
         TS_ASSERT_EQUALS(c3.getImag(), 6.0);
    }

    void testSubtractionOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(3.0, 4.0);
         Complex<double> c3 = c1 - c2;
         TS_ASSERT_EQUALS(c3.getReal(), -2.0);
         TS_ASSERT_EQUALS(c3.getImag(), -2.0);
    }

    void testMultiplicationOperator(void) {
         Complex<double> c1(1.0, 2.0);
         Complex<double> c2(3.0, 4.0);
         Complex<double> c3 = c1 * c2;
         TS_ASSERT_EQUALS(c3.getReal(), -5.0);
         TS_ASSERT_EQUALS(c3.getImag(), 10.0);
    }

    
};