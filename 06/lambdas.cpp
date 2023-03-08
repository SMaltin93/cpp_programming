#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include <thread>
#include <bits/stdc++.h>

using namespace std;


int main () {

  vector<int> v = {1, 3, 4, 5, 6, 7, 8, 9};
    // printing v
    cout << "vector v:" << endl;
    for (auto x : v) { cout << x << " ";};
    cout << endl;

    // Write a for_each statement that uses a lambda expression to print odd numbers in vector v. 

   for_each(v.cbegin(), v.cend(), [](int value){ 
    if (value % 2 != 0) { 
        cout << value << "\n";
    }
    });

    // changes the values in v by multipliying all odd numbers by 2.

    for_each(v.begin(), v.end(), [=](int &value){
    if (value % 2 != 0) {
        value *= 2;
        cout << value << "\n";
    }
    });

    //  changes the vector elements by adding the size of the vector to all elements.

    for_each(v.begin(), v.end(), [v](int &value){
        value += v.size();
        cout << value << "\n";
    });

    // Write a lambda function on our own that changes any data of your choice outside the scope of the lambda by capturing with [ & ]

    int x = 10;
    for_each(v.begin(), v.end(), [&x](int &value){
        value += x;
        cout << value << "\n";
    });



}