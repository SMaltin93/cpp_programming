# Inquiry

## Answers


What did you learn from this assignment?

Porgramming binary tree in c++ 

What was hardest to implement in this assignment?
remove function

If the signature of insert was changed like below, changing the key of p would not have the desired effect, why is that?

void insert(Node * p, int key, double value) {   // reference to pointer removed
  if ( p == nullptr ) {
     p = new Node();
     p -> key = key;   // ???
     // ...
I think the reason is because the parameter p is passed by value, not by reference. which means that when p is assigned to a new Node object in the if statement, the change only affects the local copy of p inside the function, not the original pointer passed in by the caller.
So if we change the key of p inside the insert function, it would only modify the key field of the local copy of the Node pointed to by p

Are you able to pass a value, such as 17, to a const int & parameter ?

No, we cannot. A const int & parameter is a reference to a constant integer, which means that it expects to receive a reference to an existing integer object.

How do you check if two objects are equal if they only have operator< and not operator==?
If we check !(b < a) && !(a < b) , if  (b not less than a) and (a not less than b) then a equal b.

Does a < b and !(b < a) compare the same thing?
Yes, it dose! The expression a < b checks if a is less than b, while the expression !(b < a) checks if b is not less than a.

Write down data from your test runs

The average height of the tree in 800 iterations: 19.5
The highest maximum height: 34
The average minimum height: 5
The lowest minimum height: 0
The average difference between minimum and maximum height: 29
The greatest difference between minimum and maximum height: 29
The lowest difference between minimum and maximum height: 0