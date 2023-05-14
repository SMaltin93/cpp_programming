

#include <bits/stdc++.h>
using namespace std;

#ifndef BINTREE_H
#define BINTREE_H

struct Node {
    int key;
    double data;
    Node * right;
    Node * left;

    Node() : key(0), data(0), right(nullptr), left(nullptr) {}
    Node(int key, double data) : key(key), data(data), right(nullptr), left(nullptr) {}
    
    ~Node() {
        delete left;
        delete right;
    }
};

void insert(Node *&p, int key, double to_be_inserted); // 
void remove(Node *&p, const int & key);
const double & find(Node *p, const int & to_be_found);
double & edit(Node *p, const int & to_be_changed);
void delete_tree(Node *&p);
// Extra functions
void print_tree_inorder(Node *p);
// look for max replecement
void max_replacement(Node *&p);

unsigned int max_height(Node *p); // unsigned int menas that it can't be negative
unsigned int min_height(Node *p);
unsigned int size(Node *p);
bool is_balanced(Node *p);

#endif 