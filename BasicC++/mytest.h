// mytest.h
#include <cxxtest/TestSuite.h>
#include "count_if_followed_by.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  void testCount_if_followed_by( void )
  {
    char const data[4] = {'a','b','a','b'};
    int  const result  = count_if_followed_by (data, 3, 'b', 'a');
    
    TS_ASSERT( result == 1 ); 
  }

  void testNo_Match () {
    char data[4] = {'a','b','a','b'};
    TS_ASSERT_EQUALS(count_if_followed_by (data,3,'b','b'),0);
  }

  void testEmpty_Data (){
    char data[] = {};
    TS_ASSERT_EQUALS(count_if_followed_by (data,0,'a','b'),0);
  } 

  void testOff_By_One_Error() {
    char data[] = {'a','b','c','a','b','c'};
    int len = sizeof(data) / sizeof(data[0]);
    TS_ASSERT_EQUALS(count_if_followed_by (data,len,'a','c'), 0);
  }


};