/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
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

static class TestDescription_suite_MyTestSuite_test_insert_Tree_of_size_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_insert_Tree_of_size_0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 20, "test_insert_Tree_of_size_0" ) {}
 void runTest() { suite_MyTestSuite.test_insert_Tree_of_size_0(); }
} testDescription_suite_MyTestSuite_test_insert_Tree_of_size_0;

static class TestDescription_suite_MyTestSuite_test_remove_Tree_of_size_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_remove_Tree_of_size_0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 32, "test_remove_Tree_of_size_0" ) {}
 void runTest() { suite_MyTestSuite.test_remove_Tree_of_size_0(); }
} testDescription_suite_MyTestSuite_test_remove_Tree_of_size_0;

static class TestDescription_suite_MyTestSuite_test_find_Tree_of_size_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_find_Tree_of_size_0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 40, "test_find_Tree_of_size_0" ) {}
 void runTest() { suite_MyTestSuite.test_find_Tree_of_size_0(); }
} testDescription_suite_MyTestSuite_test_find_Tree_of_size_0;

static class TestDescription_suite_MyTestSuite_test_edit_Tree_of_size_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_edit_Tree_of_size_0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 53, "test_edit_Tree_of_size_0" ) {}
 void runTest() { suite_MyTestSuite.test_edit_Tree_of_size_0(); }
} testDescription_suite_MyTestSuite_test_edit_Tree_of_size_0;

static class TestDescription_suite_MyTestSuite_test_delete_tree_Tree_of_size_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_delete_tree_Tree_of_size_0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 66, "test_delete_tree_Tree_of_size_0" ) {}
 void runTest() { suite_MyTestSuite.test_delete_tree_Tree_of_size_0(); }
} testDescription_suite_MyTestSuite_test_delete_tree_Tree_of_size_0;

static class TestDescription_suite_MyTestSuite_test_print_tree_inorder_Tree_of_size_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_print_tree_inorder_Tree_of_size_0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 74, "test_print_tree_inorder_Tree_of_size_0" ) {}
 void runTest() { suite_MyTestSuite.test_print_tree_inorder_Tree_of_size_0(); }
} testDescription_suite_MyTestSuite_test_print_tree_inorder_Tree_of_size_0;

static class TestDescription_suite_MyTestSuite_test_max_replacement_Tree_of_size_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_max_replacement_Tree_of_size_0() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 82, "test_max_replacement_Tree_of_size_0" ) {}
 void runTest() { suite_MyTestSuite.test_max_replacement_Tree_of_size_0(); }
} testDescription_suite_MyTestSuite_test_max_replacement_Tree_of_size_0;

static class TestDescription_suite_MyTestSuite_test_insert_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_insert_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 96, "test_insert_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_insert_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_insert_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_remove_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_remove_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 108, "test_remove_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_remove_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_remove_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_find_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_find_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 121, "test_find_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_find_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_find_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_edit_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_edit_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 132, "test_edit_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_edit_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_edit_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_delete_tree_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_delete_tree_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 144, "test_delete_tree_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_delete_tree_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_delete_tree_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_max_height_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_max_height_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 155, "test_max_height_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_max_height_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_max_height_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_min_height_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_min_height_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 168, "test_min_height_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_min_height_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_min_height_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_size_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_size_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 180, "test_size_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_size_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_size_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_is_balanced_Tree_of_size_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_is_balanced_Tree_of_size_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 191, "test_is_balanced_Tree_of_size_1" ) {}
 void runTest() { suite_MyTestSuite.test_is_balanced_Tree_of_size_1(); }
} testDescription_suite_MyTestSuite_test_is_balanced_Tree_of_size_1;

static class TestDescription_suite_MyTestSuite_test_insert_Tree_of_size_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_insert_Tree_of_size_3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 206, "test_insert_Tree_of_size_3" ) {}
 void runTest() { suite_MyTestSuite.test_insert_Tree_of_size_3(); }
} testDescription_suite_MyTestSuite_test_insert_Tree_of_size_3;

static class TestDescription_suite_MyTestSuite_test_remove_Tree_of_size_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_remove_Tree_of_size_3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 233, "test_remove_Tree_of_size_3" ) {}
 void runTest() { suite_MyTestSuite.test_remove_Tree_of_size_3(); }
} testDescription_suite_MyTestSuite_test_remove_Tree_of_size_3;

static class TestDescription_suite_MyTestSuite_test_find_Tree_of_size_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_find_Tree_of_size_3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 251, "test_find_Tree_of_size_3" ) {}
 void runTest() { suite_MyTestSuite.test_find_Tree_of_size_3(); }
} testDescription_suite_MyTestSuite_test_find_Tree_of_size_3;

static class TestDescription_suite_MyTestSuite_test_find_out_of_range : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_find_out_of_range() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 264, "test_find_out_of_range" ) {}
 void runTest() { suite_MyTestSuite.test_find_out_of_range(); }
} testDescription_suite_MyTestSuite_test_find_out_of_range;

static class TestDescription_suite_MyTestSuite_test_edit_out_of_range : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_edit_out_of_range() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 282, "test_edit_out_of_range" ) {}
 void runTest() { suite_MyTestSuite.test_edit_out_of_range(); }
} testDescription_suite_MyTestSuite_test_edit_out_of_range;

static class TestDescription_suite_MyTestSuite_test_max_replacement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_max_replacement() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 301, "test_max_replacement" ) {}
 void runTest() { suite_MyTestSuite.test_max_replacement(); }
} testDescription_suite_MyTestSuite_test_max_replacement;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
