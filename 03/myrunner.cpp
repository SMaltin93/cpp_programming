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
 TestDescription_suite_MyTestSuite_testConstructorWithRealPart() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 18, "testConstructorWithRealPart" ) {}
 void runTest() { suite_MyTestSuite.testConstructorWithRealPart(); }
} testDescription_suite_MyTestSuite_testConstructorWithRealPart;

static class TestDescription_suite_MyTestSuite_testConstructorWithRealAndImaginaryPart : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testConstructorWithRealAndImaginaryPart() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 25, "testConstructorWithRealAndImaginaryPart" ) {}
 void runTest() { suite_MyTestSuite.testConstructorWithRealAndImaginaryPart(); }
} testDescription_suite_MyTestSuite_testConstructorWithRealAndImaginaryPart;

static class TestDescription_suite_MyTestSuite_testCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCopyConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 32, "testCopyConstructor" ) {}
 void runTest() { suite_MyTestSuite.testCopyConstructor(); }
} testDescription_suite_MyTestSuite_testCopyConstructor;

static class TestDescription_suite_MyTestSuite_testMoveConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMoveConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 40, "testMoveConstructor" ) {}
 void runTest() { suite_MyTestSuite.testMoveConstructor(); }
} testDescription_suite_MyTestSuite_testMoveConstructor;

static class TestDescription_suite_MyTestSuite_testAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAssignmentOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 50, "testAssignmentOperator" ) {}
 void runTest() { suite_MyTestSuite.testAssignmentOperator(); }
} testDescription_suite_MyTestSuite_testAssignmentOperator;

static class TestDescription_suite_MyTestSuite_testMoveAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMoveAssignmentOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "testMoveAssignmentOperator" ) {}
 void runTest() { suite_MyTestSuite.testMoveAssignmentOperator(); }
} testDescription_suite_MyTestSuite_testMoveAssignmentOperator;

static class TestDescription_suite_MyTestSuite_testAdditionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAdditionOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 68, "testAdditionOperator" ) {}
 void runTest() { suite_MyTestSuite.testAdditionOperator(); }
} testDescription_suite_MyTestSuite_testAdditionOperator;

static class TestDescription_suite_MyTestSuite_testSubtractionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSubtractionOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 77, "testSubtractionOperator" ) {}
 void runTest() { suite_MyTestSuite.testSubtractionOperator(); }
} testDescription_suite_MyTestSuite_testSubtractionOperator;

static class TestDescription_suite_MyTestSuite_testMultiplicationOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMultiplicationOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 86, "testMultiplicationOperator" ) {}
 void runTest() { suite_MyTestSuite.testMultiplicationOperator(); }
} testDescription_suite_MyTestSuite_testMultiplicationOperator;

static class TestDescription_suite_MyTestSuite_testScalarMultiplicationOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testScalarMultiplicationOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 95, "testScalarMultiplicationOperator" ) {}
 void runTest() { suite_MyTestSuite.testScalarMultiplicationOperator(); }
} testDescription_suite_MyTestSuite_testScalarMultiplicationOperator;

static class TestDescription_suite_MyTestSuite_testDivisionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDivisionOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 102, "testDivisionOperator" ) {}
 void runTest() { suite_MyTestSuite.testDivisionOperator(); }
} testDescription_suite_MyTestSuite_testDivisionOperator;

static class TestDescription_suite_MyTestSuite_testOperatorPlusEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorPlusEqual() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 111, "testOperatorPlusEqual" ) {}
 void runTest() { suite_MyTestSuite.testOperatorPlusEqual(); }
} testDescription_suite_MyTestSuite_testOperatorPlusEqual;

static class TestDescription_suite_MyTestSuite_testOperatorMinusEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorMinusEqual() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 120, "testOperatorMinusEqual" ) {}
 void runTest() { suite_MyTestSuite.testOperatorMinusEqual(); }
} testDescription_suite_MyTestSuite_testOperatorMinusEqual;

static class TestDescription_suite_MyTestSuite_testOperatorMultiplyEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorMultiplyEqual() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 129, "testOperatorMultiplyEqual" ) {}
 void runTest() { suite_MyTestSuite.testOperatorMultiplyEqual(); }
} testDescription_suite_MyTestSuite_testOperatorMultiplyEqual;

static class TestDescription_suite_MyTestSuite_testEqualityOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEqualityOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 142, "testEqualityOperator" ) {}
 void runTest() { suite_MyTestSuite.testEqualityOperator(); }
} testDescription_suite_MyTestSuite_testEqualityOperator;

static class TestDescription_suite_MyTestSuite_testInequalityOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInequalityOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 151, "testInequalityOperator" ) {}
 void runTest() { suite_MyTestSuite.testInequalityOperator(); }
} testDescription_suite_MyTestSuite_testInequalityOperator;

static class TestDescription_suite_MyTestSuite_testGetter : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testGetter() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 160, "testGetter" ) {}
 void runTest() { suite_MyTestSuite.testGetter(); }
} testDescription_suite_MyTestSuite_testGetter;

static class TestDescription_suite_MyTestSuite_testMagnitude : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMagnitude() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 167, "testMagnitude" ) {}
 void runTest() { suite_MyTestSuite.testMagnitude(); }
} testDescription_suite_MyTestSuite_testMagnitude;

static class TestDescription_suite_MyTestSuite_testOperatorLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorLessThan() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 173, "testOperatorLessThan" ) {}
 void runTest() { suite_MyTestSuite.testOperatorLessThan(); }
} testDescription_suite_MyTestSuite_testOperatorLessThan;

static class TestDescription_suite_MyTestSuite_testOperatorOutStream : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorOutStream() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 181, "testOperatorOutStream" ) {}
 void runTest() { suite_MyTestSuite.testOperatorOutStream(); }
} testDescription_suite_MyTestSuite_testOperatorOutStream;

static class TestDescription_suite_MyTestSuite_testOperatorInStream : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorInStream() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 189, "testOperatorInStream" ) {}
 void runTest() { suite_MyTestSuite.testOperatorInStream(); }
} testDescription_suite_MyTestSuite_testOperatorInStream;

static class TestDescription_suite_MyTestSuite_testOperator_i : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperator_i() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 211, "testOperator_i" ) {}
 void runTest() { suite_MyTestSuite.testOperator_i(); }
} testDescription_suite_MyTestSuite_testOperator_i;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
