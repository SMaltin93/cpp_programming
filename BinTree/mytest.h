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
// Test all functions for correctness with a tree of size 0.  9 functions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// insert // 2
void test_insert_Tree_of_size_0() {
    Node *p = nullptr;
    insert(p, 1, 1.1);

    TS_ASSERT_EQUALS(p->key, 1);
    TS_ASSERT_EQUALS(p->data, 1.1);
    TS_ASSERT_EQUALS(p->left, nullptr);
    TS_ASSERT_EQUALS(p->right, nullptr);
    delete_tree(p);
}

// remove // 3
void test_remove_Tree_of_size_0() {
    Node *p = nullptr;
    remove(p, 1);
    TS_ASSERT_EQUALS(p, nullptr);
    delete_tree(p);
}

// find // 4
void test_find_Tree_of_size_0() {
    Node *p = nullptr;
    bool caught = false;
    try {
        find(p, 1);
    } catch (out_of_range& e) {
        caught = true;
    }
    TS_ASSERT_EQUALS(caught, true);
    delete_tree(p);
}

// edit // 5
void test_edit_Tree_of_size_0() {
    Node *p = nullptr;
    bool caught = false;
    try {
        edit(p, 1) = 2.2;
    } catch (out_of_range& e) {
        caught = true;
    }
    TS_ASSERT_EQUALS(caught, true);
    delete_tree(p);
}

// delete_tree // 6
void test_delete_tree_Tree_of_size_0() {
    Node *p = nullptr;
    delete_tree(p);
    TS_ASSERT_EQUALS(p, nullptr);
    delete_tree(p);
}

// print_tree_inorder // 7
void test_print_tree_inorder_Tree_of_size_0() {
    Node *p = nullptr;
    print_tree_inorder(p);
    TS_ASSERT_EQUALS(p, nullptr);
    delete_tree(p);
}

// max_replacement // 8
void test_max_replacement_Tree_of_size_0() {
    Node *p = nullptr;
    max_replacement(p);
    TS_ASSERT_EQUALS(p, nullptr);
    delete_tree(p);
}



// Test all functions for correctness with a tree of size 1.  9 functions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


// insert // 9

void test_insert_Tree_of_size_1() {
    Node *p = new Node(1, 1.1);

    insert(p, 2, 2.2);  
    TS_ASSERT_EQUALS(p->right->key, 2);
    TS_ASSERT_EQUALS(p->right->data, 2.2);
    TS_ASSERT_EQUALS(p->right->left, nullptr);
    TS_ASSERT_EQUALS(p->right->right, nullptr);
    delete_tree(p);   
}
// remove // 10

void test_remove_Tree_of_size_1() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;
    remove(p, 1);
    TS_ASSERT_EQUALS(p, nullptr);
    delete_tree(p);
}

// find // 11

void test_find_Tree_of_size_1() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;
    TS_ASSERT_EQUALS(find(p, 1), 1.1);
    delete_tree(p);
}
 
// edit // 12
void test_edit_Tree_of_size_1() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;
    edit(p, 1) = 2.2;
    TS_ASSERT_EQUALS(find(p, 1), 2.2);
    delete_tree(p);
}

// delete_tree // 13
void test_delete_tree_Tree_of_size_1() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;
    delete_tree(p);
    TS_ASSERT_EQUALS(p, nullptr);
}

// max_height //14
void test_max_height_Tree_of_size_1() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;
    TS_ASSERT_EQUALS(max_height(p), 1);
    delete_tree(p);
}


// min_height // 15

void test_min_height_Tree_of_size_1() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;
    TS_ASSERT_EQUALS(min_height(p), 1);
    delete_tree(p);
}

// size // 16

void test_size_Tree_of_size_1() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;
    TS_ASSERT_EQUALS(size(p), 1);
    delete_tree(p);
}

// is_balanced // 17
void test_is_balanced_Tree_of_size_1() {
    Node *p = new Node;
    p->key = 1;
    p->data = 1.1;
    p->left = nullptr;
    p->right = nullptr;
    TS_ASSERT_EQUALS(is_balanced(p), true);
    delete_tree(p);
}


// Tests some functions for correctness with a tree size > 1 

// insert // 18

void test_insert_Tree_of_size_3 () {

    Node *p = new Node(2, 2.2);
    insert(p, 1, 1.1);
    insert(p, 3, 3.3);


    TS_ASSERT_EQUALS(p->key, 2);
    TS_ASSERT_EQUALS(p->data, 2.2);

    TS_ASSERT_EQUALS(p->left->key, 1);
    TS_ASSERT_EQUALS(p->left->data, 1.1);
    TS_ASSERT_EQUALS(p->left->left, nullptr);
    TS_ASSERT_EQUALS(p->left->right, nullptr);

    TS_ASSERT_EQUALS(p->right->key, 3);
    TS_ASSERT_EQUALS(p->right->data, 3.3);
    TS_ASSERT_EQUALS(p->right->left, nullptr);
    TS_ASSERT_EQUALS(p->right->right, nullptr);

    delete_tree(p);


}

// remove // 19
 
void test_remove_Tree_of_size_3 () {

    Node *p = new Node(2, 2.2);
    insert(p, 1, 1.1);
    insert(p, 3, 3.3);
    remove(p, 2);
    TS_ASSERT_EQUALS(p->key, 3);
    TS_ASSERT_EQUALS(p->data, 3.3);
    TS_ASSERT_EQUALS(p->left->key, 1);
    TS_ASSERT_EQUALS(p->left->data, 1.1);
    TS_ASSERT_EQUALS(p->left->left, nullptr);
    TS_ASSERT_EQUALS(p->left->right, nullptr);
    TS_ASSERT_EQUALS(p->right, nullptr);
    delete_tree(p);
}

// find // 20

void test_find_Tree_of_size_3 () {

    Node *p = new Node(2, 2.2);
    insert(p, 1, 1.1);
    insert(p, 3, 3.3);
    TS_ASSERT_EQUALS(find(p, 2), 2.2);
    delete_tree(p);
}

//Test some functions if they properly throw std::out_of_range with a tree size > 1 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// test insert // 21

void test_find_out_of_range() {
    Node* p = new Node(2, 2.2);
    insert(p, 1, 1.1);
    insert(p, 3, 3.3);

    bool caught = false;
    try {
        find(p, 4);
    } catch (out_of_range& e) {
        caught = true;
    }
    TS_ASSERT(caught);
    delete_tree(p);

}

// test edit // 22

void test_edit_out_of_range() {
    Node* p = new Node(2, 2.2);
    insert(p, 1, 1.1);
    insert(p, 3, 3.3);

    bool caught = false;
    try {
        edit(p, 4) = 4.4;
    } catch (out_of_range& e) {
        caught = true;
    }
    TS_ASSERT(caught);
    delete_tree(p);
}



// test max_replacement // 23

void test_max_replacement() {
    // Create a binary tree
    Node* root = nullptr;
    insert(root, 50, 50.0);
    insert(root, 30, 30.0);
    insert(root, 20, 20.0);
    insert(root, 40, 40.0);
    insert(root, 70, 70.0);
    insert(root, 60, 60.0);
    insert(root, 80, 80.0);


    // Perform max_replacement operation
    max_replacement(root);


    // 80 should be removed and replaced with 70
    try {
        find(root, 80);
    } catch (out_of_range& e) {
        TS_ASSERT(true);
    }

    delete_tree(root);
}



};
