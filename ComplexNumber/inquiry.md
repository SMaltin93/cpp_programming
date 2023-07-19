# Inquiry

Write your answers below and include the questions. Do copy relevant code to your answers so that both questions and answers are in context 

## Answers

What did you learn from this assignment?

Implementing complex number class with basic operations, comparison operators, and other member functions.
Better understanding of move constructors.
Testing the code. 

__________________________________________________________________

What was the hardest part (or parts) in this assignment?

I think that the hardest part in this lab is implementing operator <<, >>, < , and ""_i .
Which of your class methods or non-member functions returns a copy?
operator-() const: This returns a new Complex object that is the negation of the current object.
operator+() const: This returns a new Complex object that is a copy of the current object.
operator+(const double &lhs, const Complex<T> &rhs): This returns a new Complex object that is the sum of a scalar (double) and a Complex object.
__________________________________________________________________

Which of your class methods or non-member functions returns a reference?

Both the move assignment operator and the copy assignment operator (Complex<T> & Complex<T>::operator=(Complex<T> &&rhs) and  Complex<T> & Complex<T>::operator=(const Complex<T> &rhs)) return a reference to the calling object (i.e., the Complex object that called the operator) using the keyword this.
____________________________________________________________

How many tests do you need at minimum to test the abs function?

You need at least two tests: one for a complex number with a positive magnitude and one for a complex number with a negative magnitude.

__________________________________________________________________

Describe and motivate how your implementation of operator= works?

The operator= lets us copy the values of one complex number to another using the assignment operator (=). The function copies the real and imaginary parts of the right-hand side object to the left-hand side object. To make it easy to chain assignments, the function returns a reference to the left-hand side object.
__________________________________________________________________

What constructors/functions are called when writing the statement Complex k = 3 + 5_i;?

The statement Complex k = 3 + 5_i; creates a Complex object named k using the default constructor, which initializes real and imag to zero. Then, the operator""_i is called with an argument of 5, which creates a temporary Complex object with a real part of 0 and an imaginary part of 5. The operator+ function is called with arguments of 3 and the temporary Complex object, which returns another temporary Complex object with a real part of 3 and an imaginary part of 5. The assignment operator is then called to assign this temporary Complex object to the object k.
__________________________________________________________________

Describe and motivate how your implementation of operator += -= /= *= = works with regard to return value?

The operator+=(), operator-=(), operator/=(), operator*=() take a Complex object as an argument and perform the corresponding operation on the current object's real and imaginary parts. They return a reference to the current object to allow for chaining assignments. The return value enables the user to perform multiple operations on a single Complex object in a single statement.
__________________________________________________________________

What is the rule of three in C++. Look it up in a C++ book or on the web? 
https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)

The Rule of Three in C++ is a guideline that states that if a class defines any of the following three functions, it should define all three.
Copy constructor: a constructor that creates a new object by initializing it with another object of the same class.
Copy assignment operator: an overloaded operator that assigns one object to another object of the same class, creating a copy of the original object.
Destructor: a special member function that is called when an object of the class is destroyed.
__________________________________________________________________

With regard to the rule of three, do you need to explicitly define and implement the copy-constructor in this assignment?

Yes, we need to define and implement the copy constructor as part of the Rule of Three. The Rule of Three states that if a class defines a destructor, a copy constructor, or a copy assignment operator, then it should define all three. This is because the default versions of these functions provided by the compiler might not be correct for a particular class, especially if the class uses dynamic memory allocation or other resources which require explicit management.

__________________________________________________________________

The literal i has an underscore before it. Why is that? Look it up in the c++11 draft section 17.6.4.3.5 and explain. Has there been any changes regarding this matter in the new c++17 draft

 In C++, the suffix "i" is commonly used to denote a complex literal of type std::complex<double>. The C++11 draft specifies the allowed suffixes for imaginary literals in C++, which means that the "i" or "I" letter can be added as a suffix to a floating-point or integer literal to represent an imaginary number. Additionally, the C++11 standard allows an underscore to be placed immediately before the 'i' or 'I' suffix to avoid any confusion with variable names that may include the letter 'i'. This underscore aims to distinguish between an imaginary literal and a variable name that happens to contain the letter 'i'.
The C++17 standard has not made any changes to the rules regarding the use of identifiers with a leading underscore, so the same rules as in C++11 still apply.