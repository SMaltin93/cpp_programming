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

static class TestDescription_suite_MyTestSuite_test_validInput : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_validInput() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "test_validInput" ) {}
 void runTest() { suite_MyTestSuite.test_validInput(); }
} testDescription_suite_MyTestSuite_test_validInput;

static class TestDescription_suite_MyTestSuite_test_emptyInput : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_emptyInput() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 21, "test_emptyInput" ) {}
 void runTest() { suite_MyTestSuite.test_emptyInput(); }
} testDescription_suite_MyTestSuite_test_emptyInput;

static class TestDescription_suite_MyTestSuite_test_wrongInput : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_wrongInput() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 27, "test_wrongInput" ) {}
 void runTest() { suite_MyTestSuite.test_wrongInput(); }
} testDescription_suite_MyTestSuite_test_wrongInput;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
