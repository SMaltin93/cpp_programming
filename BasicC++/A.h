#ifndef AH
#define AH

struct B; // forward declaration
class A {
    B *b;
    int method(int x);
};

#endif  // AH