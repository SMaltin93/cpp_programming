#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include <thread>
#include <bits/stdc++.h>


using namespace std;


struct A {
    int data;
};

void foo(unique_ptr<A> p) {
    cout << p->data << endl;
}

void foo2(shared_ptr<A> p) {
    cout << p->data << endl;
}

int main () {

    // Create a unique_ptr to A

    unique_ptr<A> pa(new A {4});
    cout << "unique_ptr " << pa->data << endl;
    // Call foo with the unique_ptr
    foo(move(pa));

    // Create a shared_ptr to A
    shared_ptr<A> sa(new A {5});
    cout << "  shared_ptr " <<sa->data << endl;

    // Call foo2 with the shared_ptr
    foo2(sa);
   // foo2(move(sa)); //    

   // Create a Weak_ptr to A

    weak_ptr<A> wa(sa);
    // use the lock function to print the data of A
    cout << "weak_ptr "<< wa.lock()->data << endl;


}