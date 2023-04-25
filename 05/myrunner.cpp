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

static class TestDescription_suite_MyTestSuite_test_empty_tree : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_empty_tree() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 10, "test_empty_tree" ) {}
 void runTest() { suite_MyTestSuite.test_empty_tree(); }
} testDescription_suite_MyTestSuite_test_empty_tree;

static class TestDescription_suite_MyTestSuite_test_insert : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_insert() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 20, "test_insert" ) {}
 void runTest() { suite_MyTestSuite.test_insert(); }
} testDescription_suite_MyTestSuite_test_insert;

static class TestDescription_suite_MyTestSuite_test_remove : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_remove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 37, "test_remove" ) {}
 void runTest() { suite_MyTestSuite.test_remove(); }
} testDescription_suite_MyTestSuite_test_remove;

static class TestDescription_suite_MyTestSuite_test_find : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_find() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 46, "test_find" ) {}
 void runTest() { suite_MyTestSuite.test_find(); }
} testDescription_suite_MyTestSuite_test_find;

static class TestDescription_suite_MyTestSuite_test_edit : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_edit() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 54, "test_edit" ) {}
 void runTest() { suite_MyTestSuite.test_edit(); }
} testDescription_suite_MyTestSuite_test_edit;

static class TestDescription_suite_MyTestSuite_test_delete_tree : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_delete_tree() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 63, "test_delete_tree" ) {}
 void runTest() { suite_MyTestSuite.test_delete_tree(); }
} testDescription_suite_MyTestSuite_test_delete_tree;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
