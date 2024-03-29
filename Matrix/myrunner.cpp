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
 TestDescription_suite_MyTestSuite_testDefaultConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 10, "testDefaultConstructor" ) {}
 void runTest() { suite_MyTestSuite.testDefaultConstructor(); }
} testDescription_suite_MyTestSuite_testDefaultConstructor;

static class TestDescription_suite_MyTestSuite_testDimensionConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDimensionConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "testDimensionConstructor" ) {}
 void runTest() { suite_MyTestSuite.testDimensionConstructor(); }
} testDescription_suite_MyTestSuite_testDimensionConstructor;

static class TestDescription_suite_MyTestSuite_testRowColumnConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRowColumnConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 21, "testRowColumnConstructor" ) {}
 void runTest() { suite_MyTestSuite.testRowColumnConstructor(); }
} testDescription_suite_MyTestSuite_testRowColumnConstructor;

static class TestDescription_suite_MyTestSuite_testInitializerListConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInitializerListConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 26, "testInitializerListConstructor" ) {}
 void runTest() { suite_MyTestSuite.testInitializerListConstructor(); }
} testDescription_suite_MyTestSuite_testInitializerListConstructor;

static class TestDescription_suite_MyTestSuite_testCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCopyConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 36, "testCopyConstructor" ) {}
 void runTest() { suite_MyTestSuite.testCopyConstructor(); }
} testDescription_suite_MyTestSuite_testCopyConstructor;

static class TestDescription_suite_MyTestSuite_testMoveConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMoveConstructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 49, "testMoveConstructor" ) {}
 void runTest() { suite_MyTestSuite.testMoveConstructor(); }
} testDescription_suite_MyTestSuite_testMoveConstructor;

static class TestDescription_suite_MyTestSuite_testOperatorEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorEqual() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "testOperatorEqual" ) {}
 void runTest() { suite_MyTestSuite.testOperatorEqual(); }
} testDescription_suite_MyTestSuite_testOperatorEqual;

static class TestDescription_suite_MyTestSuite_testOperatorEqualMove : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorEqualMove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 70, "testOperatorEqualMove" ) {}
 void runTest() { suite_MyTestSuite.testOperatorEqualMove(); }
} testDescription_suite_MyTestSuite_testOperatorEqualMove;

static class TestDescription_suite_MyTestSuite_testDestructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testDestructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 79, "testDestructor" ) {}
 void runTest() { suite_MyTestSuite.testDestructor(); }
} testDescription_suite_MyTestSuite_testDestructor;

static class TestDescription_suite_MyTestSuite_testRows : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRows() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 87, "testRows" ) {}
 void runTest() { suite_MyTestSuite.testRows(); }
} testDescription_suite_MyTestSuite_testRows;

static class TestDescription_suite_MyTestSuite_testCols : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCols() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 91, "testCols" ) {}
 void runTest() { suite_MyTestSuite.testCols(); }
} testDescription_suite_MyTestSuite_testCols;

static class TestDescription_suite_MyTestSuite_testOperatorParenthesis : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorParenthesis() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 96, "testOperatorParenthesis" ) {}
 void runTest() { suite_MyTestSuite.testOperatorParenthesis(); }
} testDescription_suite_MyTestSuite_testOperatorParenthesis;

static class TestDescription_suite_MyTestSuite_testOperatorParenthesisConst : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testOperatorParenthesisConst() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 104, "testOperatorParenthesisConst" ) {}
 void runTest() { suite_MyTestSuite.testOperatorParenthesisConst(); }
} testDescription_suite_MyTestSuite_testOperatorParenthesisConst;

static class TestDescription_suite_MyTestSuite_testMultiplicationOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMultiplicationOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 117, "testMultiplicationOperator" ) {}
 void runTest() { suite_MyTestSuite.testMultiplicationOperator(); }
} testDescription_suite_MyTestSuite_testMultiplicationOperator;

static class TestDescription_suite_MyTestSuite_testAdditionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAdditionOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 131, "testAdditionOperator" ) {}
 void runTest() { suite_MyTestSuite.testAdditionOperator(); }
} testDescription_suite_MyTestSuite_testAdditionOperator;

static class TestDescription_suite_MyTestSuite_testSubtractionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSubtractionOperator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 146, "testSubtractionOperator" ) {}
 void runTest() { suite_MyTestSuite.testSubtractionOperator(); }
} testDescription_suite_MyTestSuite_testSubtractionOperator;

static class TestDescription_suite_MyTestSuite_testMultiplicationOperatorEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMultiplicationOperatorEqual() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 160, "testMultiplicationOperatorEqual" ) {}
 void runTest() { suite_MyTestSuite.testMultiplicationOperatorEqual(); }
} testDescription_suite_MyTestSuite_testMultiplicationOperatorEqual;

static class TestDescription_suite_MyTestSuite_testAdditionOperatorEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAdditionOperatorEqual() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 173, "testAdditionOperatorEqual" ) {}
 void runTest() { suite_MyTestSuite.testAdditionOperatorEqual(); }
} testDescription_suite_MyTestSuite_testAdditionOperatorEqual;

static class TestDescription_suite_MyTestSuite_testSubtractionOperatorEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSubtractionOperatorEqual() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 186, "testSubtractionOperatorEqual" ) {}
 void runTest() { suite_MyTestSuite.testSubtractionOperatorEqual(); }
} testDescription_suite_MyTestSuite_testSubtractionOperatorEqual;

static class TestDescription_suite_MyTestSuite_testReset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testReset() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 204, "testReset" ) {}
 void runTest() { suite_MyTestSuite.testReset(); }
} testDescription_suite_MyTestSuite_testReset;

static class TestDescription_suite_MyTestSuite_testAppendRow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAppendRow() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 215, "testAppendRow" ) {}
 void runTest() { suite_MyTestSuite.testAppendRow(); }
} testDescription_suite_MyTestSuite_testAppendRow;

static class TestDescription_suite_MyTestSuite_testRemoveRow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRemoveRow() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 236, "testRemoveRow" ) {}
 void runTest() { suite_MyTestSuite.testRemoveRow(); }
} testDescription_suite_MyTestSuite_testRemoveRow;

static class TestDescription_suite_MyTestSuite_testInsertRow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsertRow() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 252, "testInsertRow" ) {}
 void runTest() { suite_MyTestSuite.testInsertRow(); }
} testDescription_suite_MyTestSuite_testInsertRow;

static class TestDescription_suite_MyTestSuite_testInsertColumn : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInsertColumn() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 272, "testInsertColumn" ) {}
 void runTest() { suite_MyTestSuite.testInsertColumn(); }
} testDescription_suite_MyTestSuite_testInsertColumn;

static class TestDescription_suite_MyTestSuite_testAppendColumn : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAppendColumn() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 292, "testAppendColumn" ) {}
 void runTest() { suite_MyTestSuite.testAppendColumn(); }
} testDescription_suite_MyTestSuite_testAppendColumn;

static class TestDescription_suite_MyTestSuite_testRemoveColumn : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testRemoveColumn() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 313, "testRemoveColumn" ) {}
 void runTest() { suite_MyTestSuite.testRemoveColumn(); }
} testDescription_suite_MyTestSuite_testRemoveColumn;

static class TestDescription_suite_MyTestSuite_testBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testBegin() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 331, "testBegin" ) {}
 void runTest() { suite_MyTestSuite.testBegin(); }
} testDescription_suite_MyTestSuite_testBegin;

static class TestDescription_suite_MyTestSuite_testEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testEnd() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 342, "testEnd" ) {}
 void runTest() { suite_MyTestSuite.testEnd(); }
} testDescription_suite_MyTestSuite_testEnd;

static class TestDescription_suite_MyTestSuite_testIdentity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testIdentity() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 354, "testIdentity" ) {}
 void runTest() { suite_MyTestSuite.testIdentity(); }
} testDescription_suite_MyTestSuite_testIdentity;

static class TestDescription_suite_MyTestSuite_testMatrixInOut : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMatrixInOut() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 372, "testMatrixInOut" ) {}
 void runTest() { suite_MyTestSuite.testMatrixInOut(); }
} testDescription_suite_MyTestSuite_testMatrixInOut;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
