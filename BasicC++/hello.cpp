#include <iostream>
#include <cstdlib> // std::atoi
#include "hello.h"

using namespace std;

void hello (const char * name, int count) {
    
    if (count == 0){
        return;
    }
    cout << "Hello, ";
    for (int i = 0; i < count; ++i) {
        cout << name << " ";
    }
    cout << "!" << endl;
}

pair<const char *, int> parse_args (int argc, char * argv[]) {

    // print Hello, World! if no arguments are given
    if (argc == 1) {
        cout << "Hello, World!" << endl;
        return make_pair ("", -1);
    }
    // print if that 2 arguments are given
    if (argc == 2) {
        cout << "Hello, " << argv[1] << "!" << endl;
        return make_pair ("", -1);
    }
    // if everything is fine
    // check if the second argument is an integer
    if (argc == 3) {
        for (int i = 0; argv[2][i]; i++) {
            if (!isdigit(argv[2][i]) || atoi(argv[2]) < 0) {
                cout << "error: 2nd argument must be an integral greater than zero!" << endl;
                return make_pair ("", -1);
            }
        }
    }
    // to many arguments
    if (argc > 3) {
        cout << "error: Too many arguments!" << endl;
        return make_pair ("", -1);
    }
   
    return make_pair (argv[1], atoi(argv[2]));

}