#include <cxxtest/TestSuite.h>
#include <bits/stdc++.h>
#include "bintree.cpp"
using namespace std;
class MyTestSuite : public CxxTest::TestSuite {
   
public:  

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


};
