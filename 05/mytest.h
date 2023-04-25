#include <cxxtest/TestSuite.h>
#include <bits/stdc++.h>
#include "bintree.cpp"
using namespace std;
class MyTestSuite : public CxxTest::TestSuite {
   
public:  

// Test eligble functions with an empty tree (call with nullptr)
void test_empty_tree() {
    Node *p = nullptr;
    TS_ASSERT_EQUALS(max_height(p), 0);
    TS_ASSERT_EQUALS(min_height(p), 0);
    TS_ASSERT_EQUALS(size(p), 0);
    TS_ASSERT_EQUALS(is_balanced(p), true);
    delete_tree(p);
}

// Testar insert
void test_insert() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;

    insert(p, 2, 2.2);  
    TS_ASSERT_EQUALS(p->right->key, 2);
    TS_ASSERT_EQUALS(p->right->data, 2.2);
    TS_ASSERT_EQUALS(p->right->left, nullptr);
    TS_ASSERT_EQUALS(p->right->right, nullptr);
    delete_tree(p);
    
}

// Testar remove
void test_remove() {
    Node *p = nullptr;
    insert(p, 1, 1.1);

    remove(p, 1);
    TS_ASSERT_EQUALS(p, nullptr);
    delete_tree(p);
}

void test_find() {
    Node *p = nullptr;
    insert(p, 1, 1.1);
    TS_ASSERT_EQUALS(find(p, 1), 1.1);
    delete_tree(p);

}

void test_edit () {
    Node *p = nullptr;
    insert(p, 1, 1.1);
    edit(p, 1) = 2.2;
    TS_ASSERT_EQUALS(find(p, 1), 2.2);
    delete_tree(p);

}

void test_delete_tree() {
    Node *p = nullptr;
    insert(p, 1, 1.1);
    delete_tree(p);
    TS_ASSERT_EQUALS(p, nullptr);
}




};
