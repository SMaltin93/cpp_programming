# Inquiry

Write your answers below and include the questions. Do copy relevant code to your answers so that both questions and answers are in context 

## Answers


What did you learn from this assignment?

What was hardest to implement in this assignment?
The methods like remove, append. 

How many methods/functions have you implemented?
7 methods and 6 operators

How many methods/functions have you tested?
all methods that I implemented

Describe and motivate how your implementation of operator= works
When do you need to resize in your code?

The move assignment operator operator= is designed to transfer ownership of the resources managed by one Matrix object to another Matrix object, avoiding the need to perform a deep copy of the data. It allows the contents of one object to be transferred to another, leaving the original object in a valid but unspecified state.

When you resize your matrix, are you able to move the elements?

It is possible to implement a matrix resize operation that avoids unnecessary copying by using a move constructor or move assignment operator, but this would depend on the specific implementation of the matrix class.

Why do you need to implement a const-version of the accessor operator?
This is useful when we have a const reference or pointer to a matrix object and we want to access its elements without modifying them.

Is it possible to call std::sort() to sort your matrix using begin() and end()?
Yes, it is possible to call sort() to sort a matrix using begin() and end() 

What other kind of iterators, besides random access iterators, are there in C++?