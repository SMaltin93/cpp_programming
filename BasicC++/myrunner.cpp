/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "mytest.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "mytest.h", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testCount_if_followed_by : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCount_if_followed_by() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "testCount_if_followed_by" ) {}
 void runTest() { suite_MyTestSuite.testCount_if_followed_by(); }
} testDescription_suite_MyTestSuite_testCount_if_followed_by;

static class TestDescription_suite_MyTestSuite_testNo_Match : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testNo_Match() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 16, "testNo_Match" ) {}
 void runTest() { suite_MyTestSuite.testNo_Match(); }
} testDescription_suite_MyTestSuite_testNo_Match;

static class TestDescription_suite_MyTestSuite_testEmpty_Data : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEmpty_Data() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 21, "testEmpty_Data" ) {}
 void runTest() { suite_MyTestSuite.testEmpty_Data(); }
} testDescription_suite_MyTestSuite_testEmpty_Data;

static class TestDescription_suite_MyTestSuite_testOff_By_One_Error : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOff_By_One_Error() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 26, "testOff_By_One_Error" ) {}
 void runTest() { suite_MyTestSuite.testOff_By_One_Error(); }
} testDescription_suite_MyTestSuite_testOff_By_One_Error;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
