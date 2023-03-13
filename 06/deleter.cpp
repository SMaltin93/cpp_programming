#include <bits/stdc++.h>

using namespace std;

struct B {
    B() { 
        b = new int[4]; 
    }

    int * b;
    ~B() { 
        delete [] b; 
    }
    B(const B &) = delete;
    void operator= (const B & ) = delete;
};

void memoryLeak () {
    unique_ptr<B> pb(new B[2]);
    // delete [] pb.get();
}

void correctDeleter() {
    // auto deleter = [](B * b) { delete [] b; };
    // unique_ptr<B, decltype(deleter)> pb(new B[2], deleter);
    // function<void(B*)> fb = [](B * b) { delete [] b; };

    unique_ptr<B, function<void(B*)>> pb(new B[2], [](B * b) { delete [] b; });



}

int main() {
    // memoryLeak();
    correctDeleter();
     
}