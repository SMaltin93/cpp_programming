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

static class TestDescription_suite_MyTestSuite_testDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDefaultConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "testDefaultConstructor" ) {}
 void runTest() { suite_MyTestSuite.testDefaultConstructor(); }
} testDescription_suite_MyTestSuite_testDefaultConstructor;

static class TestDescription_suite_MyTestSuite_testDimensionConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDimensionConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 13, "testDimensionConstructor" ) {}
 void runTest() { suite_MyTestSuite.testDimensionConstructor(); }
} testDescription_suite_MyTestSuite_testDimensionConstructor;

static class TestDescription_suite_MyTestSuite_testRowColumnConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRowColumnConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 19, "testRowColumnConstructor" ) {}
 void runTest() { suite_MyTestSuite.testRowColumnConstructor(); }
} testDescription_suite_MyTestSuite_testRowColumnConstructor;

static class TestDescription_suite_MyTestSuite_testInitializerListConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInitializerListConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 24, "testInitializerListConstructor" ) {}
 void runTest() { suite_MyTestSuite.testInitializerListConstructor(); }
} testDescription_suite_MyTestSuite_testInitializerListConstructor;

static class TestDescription_suite_MyTestSuite_testCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCopyConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 34, "testCopyConstructor" ) {}
 void runTest() { suite_MyTestSuite.testCopyConstructor(); }
} testDescription_suite_MyTestSuite_testCopyConstructor;

static class TestDescription_suite_MyTestSuite_testMoveConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMoveConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 47, "testMoveConstructor" ) {}
 void runTest() { suite_MyTestSuite.testMoveConstructor(); }
} testDescription_suite_MyTestSuite_testMoveConstructor;

static class TestDescription_suite_MyTestSuite_testOperatorEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorEqual() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 56, "testOperatorEqual" ) {}
 void runTest() { suite_MyTestSuite.testOperatorEqual(); }
} testDescription_suite_MyTestSuite_testOperatorEqual;

static class TestDescription_suite_MyTestSuite_testOperatorEqualMove : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorEqualMove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 68, "testOperatorEqualMove" ) {}
 void runTest() { suite_MyTestSuite.testOperatorEqualMove(); }
} testDescription_suite_MyTestSuite_testOperatorEqualMove;

static class TestDescription_suite_MyTestSuite_testDestructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDestructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 77, "testDestructor" ) {}
 void runTest() { suite_MyTestSuite.testDestructor(); }
} testDescription_suite_MyTestSuite_testDestructor;

static class TestDescription_suite_MyTestSuite_testRows : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRows() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 85, "testRows" ) {}
 void runTest() { suite_MyTestSuite.testRows(); }
} testDescription_suite_MyTestSuite_testRows;

static class TestDescription_suite_MyTestSuite_testCols : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCols() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 89, "testCols" ) {}
 void runTest() { suite_MyTestSuite.testCols(); }
} testDescription_suite_MyTestSuite_testCols;

static class TestDescription_suite_MyTestSuite_testOperatorParenthesis : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorParenthesis() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 94, "testOperatorParenthesis" ) {}
 void runTest() { suite_MyTestSuite.testOperatorParenthesis(); }
} testDescription_suite_MyTestSuite_testOperatorParenthesis;

static class TestDescription_suite_MyTestSuite_testOperatorParenthesisConst : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorParenthesisConst() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 102, "testOperatorParenthesisConst" ) {}
 void runTest() { suite_MyTestSuite.testOperatorParenthesisConst(); }
} testDescription_suite_MyTestSuite_testOperatorParenthesisConst;

static class TestDescription_suite_MyTestSuite_testMultiplicationOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMultiplicationOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 115, "testMultiplicationOperator" ) {}
 void runTest() { suite_MyTestSuite.testMultiplicationOperator(); }
} testDescription_suite_MyTestSuite_testMultiplicationOperator;

static class TestDescription_suite_MyTestSuite_testAdditionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAdditionOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 130, "testAdditionOperator" ) {}
 void runTest() { suite_MyTestSuite.testAdditionOperator(); }
} testDescription_suite_MyTestSuite_testAdditionOperator;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
