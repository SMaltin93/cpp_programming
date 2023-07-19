# Inquiry

Write your answers below and include the questions. Do copy relevant code to your answers so that both questions and answers are in context 

## Answers

Where can you find the manual to g++?

We can find the manual to g++ in different ways:
typing man g++ in the terminal. And on Gcc website https://gcc.gnu.org/onlinedocs/gcc/

What is the purpose of -Wall and -g, when passed as arguments to g++?

The -Wall flag i passed to enable all warning messages.
The -g flag is passed to enable debugging.  

What is the difference between an object file, and an executable?

An object file is a file contain machine code and other information and it is generated after compiling the source code.  
An executable file is created by a compiler. It takes source code and generates machine code that can be run on specific platform. It can also be created by linking a set of object file using a linker. 

What in the example above is a forward declaration?

```cpp
struct B;  // forward declaration

class A {
    public:
        B b;
        int method(int x) { return x; }
};
```
Why is it not possible to have class A containing a B object and B containing an A object?

Because it crates a recursive relation or a circular dependency. If that happen so the both classes are going to depend on each other and that will creates a loop that the compiler cannot resolve.   


What is the purpose of std::cout, std::cerr, and std::clog, respectively?

cout (console output) is used for printing normal output to the console.

cerr (console error) is used for printing error messages or other diagnostic information to the console. 

clog (console log) is used for logging messages or other diagnostic information to the console.