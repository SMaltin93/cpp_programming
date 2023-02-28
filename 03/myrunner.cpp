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
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "mytest.h", 8, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDefaultConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 12, "testDefaultConstructor" ) {}
 void runTest() { suite_MyTestSuite.testDefaultConstructor(); }
} testDescription_suite_MyTestSuite_testDefaultConstructor;

static class TestDescription_suite_MyTestSuite_testConstructorWithRealPart : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testConstructorWithRealPart() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 19, "testConstructorWithRealPart" ) {}
 void runTest() { suite_MyTestSuite.testConstructorWithRealPart(); }
} testDescription_suite_MyTestSuite_testConstructorWithRealPart;

static class TestDescription_suite_MyTestSuite_testConstructorWithRealAndImaginaryPart : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testConstructorWithRealAndImaginaryPart() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 25, "testConstructorWithRealAndImaginaryPart" ) {}
 void runTest() { suite_MyTestSuite.testConstructorWithRealAndImaginaryPart(); }
} testDescription_suite_MyTestSuite_testConstructorWithRealAndImaginaryPart;

static class TestDescription_suite_MyTestSuite_testCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCopyConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 31, "testCopyConstructor" ) {}
 void runTest() { suite_MyTestSuite.testCopyConstructor(); }
} testDescription_suite_MyTestSuite_testCopyConstructor;

static class TestDescription_suite_MyTestSuite_testMoveConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMoveConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 38, "testMoveConstructor" ) {}
 void runTest() { suite_MyTestSuite.testMoveConstructor(); }
} testDescription_suite_MyTestSuite_testMoveConstructor;

static class TestDescription_suite_MyTestSuite_testAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAssignmentOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 47, "testAssignmentOperator" ) {}
 void runTest() { suite_MyTestSuite.testAssignmentOperator(); }
} testDescription_suite_MyTestSuite_testAssignmentOperator;

static class TestDescription_suite_MyTestSuite_testMoveAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMoveAssignmentOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 54, "testMoveAssignmentOperator" ) {}
 void runTest() { suite_MyTestSuite.testMoveAssignmentOperator(); }
} testDescription_suite_MyTestSuite_testMoveAssignmentOperator;

static class TestDescription_suite_MyTestSuite_testAdditionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAdditionOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 63, "testAdditionOperator" ) {}
 void runTest() { suite_MyTestSuite.testAdditionOperator(); }
} testDescription_suite_MyTestSuite_testAdditionOperator;

static class TestDescription_suite_MyTestSuite_testSubtractionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSubtractionOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 71, "testSubtractionOperator" ) {}
 void runTest() { suite_MyTestSuite.testSubtractionOperator(); }
} testDescription_suite_MyTestSuite_testSubtractionOperator;

static class TestDescription_suite_MyTestSuite_testMultiplicationOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMultiplicationOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 79, "testMultiplicationOperator" ) {}
 void runTest() { suite_MyTestSuite.testMultiplicationOperator(); }
} testDescription_suite_MyTestSuite_testMultiplicationOperator;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
