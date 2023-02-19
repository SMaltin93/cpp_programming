
#include <cxxtest/TestSuite.h>
#include <bits/stdc++.h>
#include "complex.h"
using namespace std;

class MyTestSuite : public CxxTest::TestSuite {
   
public:  
    //test default constructor¨
   void testDefaultConstructor(void) {
       Complex<double> c1;
       TS_ASSERT_EQUALS(c1.getReal(), 0);
       TS_ASSERT_EQUALS(c1.getImag(), 0);
   }
};