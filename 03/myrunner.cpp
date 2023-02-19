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
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "mytest.h", 7, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDefaultConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 11, "testDefaultConstructor" ) {}
 void runTest() { suite_MyTestSuite.testDefaultConstructor(); }
} testDescription_suite_MyTestSuite_testDefaultConstructor;

static class TestDescription_suite_MyTestSuite_testConstructorWithRealPart : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testConstructorWithRealPart() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 18, "testConstructorWithRealPart" ) {}
 void runTest() { suite_MyTestSuite.testConstructorWithRealPart(); }
} testDescription_suite_MyTestSuite_testConstructorWithRealPart;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
