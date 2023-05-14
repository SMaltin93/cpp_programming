

#include <bits/stdc++.h>
#include "bintree.h" 

// insert key and value in the binary tree,  initialize the new nodes left and right to nullptr.
// If the key already exists the value is overwritten, duplicate keys are not allowed. 
// Key is required to have implemented operator<
using namespace std;

void insert(Node *&p, int key, double to_be_inserted) {
    if (p == nullptr) {
        p = new Node;
        p->key = key;
        p->data = to_be_inserted;
        p->left = nullptr;
        p->right = nullptr;
    } else if (key < p->key) {
        insert(p->left, key, to_be_inserted);
    } else if (key > p->key) {
        insert(p->right, key, to_be_inserted);
    } else {
        p->data = to_be_inserted;
    }
}

// remove - Remove the node with this key. 
// If the node has two children you need to either find the maximum node to left or the minimum node to the right. 
// Copy that node to the node with the key to be deleted and remove the found minimum/maximum node instead.


void remove(Node*& p, const int& key) {
    if (p == nullptr) {
        return;
    } else if (key < p->key) {
        remove(p->left, key);
    } else if (key > p->key) {
        remove(p->right, key);
    } else {
        if (p->left == nullptr && p->right == nullptr) {
            delete p;
            p = nullptr;
        } else if (p->left == nullptr) {
            Node* temp = p;
            p = p->right;
            delete temp;
        } else if (p->right == nullptr) {
            Node* temp = p;
            p = p->left;
            delete temp;
        } else {
            Node* min_right = p->right;
            while (min_right->left != nullptr) {
                min_right = min_right->left;
            }
            p->key = min_right->key;
            p->data = min_right->data;
            remove(p->right, min_right->key);
        }
    }
}

// find - Find the node with key and returns it associated data.

const double & find(Node *p, const int & to_be_found) {
    if (p == nullptr) {
        throw out_of_range("Key not found");
    } else if (to_be_found < p->key) {
        return find(p->left, to_be_found);
    } else if (to_be_found > p->key) {
        return find(p->right, to_be_found);
    } else {
        return p->data;
    }
}

// edit - Find and return a reference to editable data associated with the key. 

double & edit(Node *p, const int & to_be_changed) {
    if (p == nullptr) {
        throw out_of_range("Key not found");
    } else if (to_be_changed < p->key) {
        return edit(p->left, to_be_changed);
    } else if (to_be_changed > p->key) {
        return edit(p->right, to_be_changed);
    } else {
        return p->data;
    }
}

// Deletes the entire tree at p.

void delete_tree(Node *&p) {
    if (p != nullptr) {
        delete_tree(p->left);
        delete_tree(p->right);
        delete p;
        p = nullptr;
    }
}

// returns the height (longest chain) of the tree

unsigned int max_height(Node *p) {
    if (p == nullptr) {
        return 0;
    } else {
        return 1 + max(max_height(p->left), max_height(p->right));
    }
}
 // min_height - returns the shortest chain of the tree

unsigned int min_height(Node *p) {
    if (p == nullptr) {
        return 0;
    } else {
        return 1 + min(min_height(p->left), min_height(p->right));
    }
}

// size - returns the number of nodes in the tree, including the p.

unsigned int size(Node *p) {
    if (p == nullptr) {
        return 0;
    } else {
        return 1 + size(p->left) + size(p->right);
    }
}

// is_balanced - returns true if the tree is balanced, false otherwise.

bool is_balanced(Node *p) {
    if (p == nullptr) {
        return true;
    } else {
        return (max_height(p->left) - max_height(p->right) <= 1) && is_balanced(p->left) && is_balanced(p->right);
    }
}

// Extra functions 

// max replacement - replaces the node with the maximum value in the left subtree

void max_replacement(Node *&p) {
    if (p == nullptr) {
        return;
    }
    if (p->right == nullptr) {
        Node *temp = p;
        if(p->left != nullptr) {
            p = p->left;
        } else {
            p = nullptr;
        }
        delete temp;
    } else {
        max_replacement(p->right);
    }
}


void print_tree_inorder(Node *p) {
    if (p != nullptr) {
        print_tree_inorder(p->left);
        cout << p->key << " " << p->data << endl;
        print_tree_inorder(p->right);
    }
}






