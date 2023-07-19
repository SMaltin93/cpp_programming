What did you learn from this assignment?

I learned about inheritance and virtual functions, and how they can be used to create a hierarchy of classes with polymorphic behavior. I also gained practice using pointers and references.

What was most difficult to do in this assignment?

The most challenging part was getting the program to run initially and debugging segmentation faults.

The code relies on virtual functions. Could the code have been written without virtual functions?

Yes, it's possible to achieve polymorphism without virtual functions, using alternative techniques like function pointers or templates. However, virtual functions provide an intuitive way to achieve polymorphism, which is why they are often preferred.

Could ChessPiece have been an abstract class?

Yes, ChessPiece could have been an abstract class, since it provides an interface that can be implemented by derived classes.

There was no separate unit test for each function in this assignment, instead you tested several functions at once with different boards. What are the benefits and drawbacks for this kind of testing compared to unit tests?

Testing several functions at once with different boards can provide a more comprehensive assessment of the program's functionality, since it tests the interactions between functions. However, it can make it harder to isolate individual errors in specific functions, and can make debugging more challenging. Using unit tests would make it easier to pinpoint the source of errors.

What is the problem with a diamond inheritance?

The problem with diamond inheritance is that it can create ambiguity when a class inherits from two different classes that share a common base class. This can result in the creation of multiple instances of the shared base class, leading to errors.

Did you encounter any problem with protected member variables and, if so, how did you solve them?

I did not encounter any problems with protected member variables.