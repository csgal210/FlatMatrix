# Overview

This **written** programming assignment combines learning C++ language features along with design elements of creating a matrix class. You will code/compare/discuss/analyze portions of four different implementations of a matrix.

Begin by **reading ths assignment thoroughly.**

# Background preparation

PFArray example from lecture: copy constructor, uses of const, passing/returning references, operator overloading, and more. Review [matrix multiplication](https://www.geeksforgeeks.org/maths/multiplying-matrices/#google_vignette).

# Terminology

Raw array

Flat array

Rule of Three

Shallow copy

Overloaded operators

Template class

Optional third parameter

Dynamic array

Multi-index subscript

Matrix multiplicaion

Read-only reference

Array arithmetic

*These terms are likely to appear on a quiz or exam.*

# C++

<algorithm>

new

delete []

(\*this)

friend

<vector>

<stdexcept>

<iostream>

template

typename

try/catch

throw

size\_t

sizeof malloc/free

# Discussion & Required Questions & Programming (boxed)

A matrix is comprised of elements arranged in rows (horizontal) and columns (vertical). We can implement this as

- A two-dimensional array of arrays) accessed by dereferecing pointers
- A one-dimensional array accessed via array arithmetic

Either of these can use subscript operators as we will see.

A traditional C++ array implementation is a fixed-size continguously-allocated homogenous data structure.

**QUESTIONS** Write all question responses on a separate sheet of paper to hand in.

## 1. Explain why it’s fixed-size?
## 2. Explain why contiguous allocation is necessary for an array.
## 3. Why is it homogenous?
## 4. What characteristics enable its classification as a data structure?

A C++ STL (Standard Template Library) **vector** class is a dynamically-sized contiguous homogenous data structure.

**QUESTIONS**

## 5. Explain how dynamic allocation works in the vector class.
## 6. List the methods: just the names, not their [various] parameter list(s).
## 7. Which of these methods implement are required to implement dynamic allocation?

# First matrix implementation: Flat matrix & vector class

Get **Matrix1** header and cpp file from GitHub:

[GitHub repository](file:///Users/pattyburnap/Library/CloudStorage/GoogleDrive-pkraft%40sdsu.edu/My%20Drive/210/Assignments/sp26/GitHub%20repository) (https://github.com/csgal210/p1fa26)

This program performs matrix multiplication while operating on a single std::vector. Java API ArrayList class has many similar properties, including allowing generic data types. C++ implements generic types using the **template** mechanism.

#include <iostream>
#include <vector>

**template<typename T>**
class Matrix1 {
private:
 size\_t rows;
 size\_t cols;
 std::vector<**T**> data; // flat 1D storage for continuous memory layout
public:

**Questions**

## 8. Explain why size\_t is preferred over int.
## 9. Explain why std::vector is required though the vector header is included.
## 10. Complete Matrix1 implementation by writing a constructor that has parameters rows, columns, and an optional\* initial value. Use an initialization list for all three private member fieids (look up the vector class constructor that has size and initial value parameters).
   Add a comment “Cannot instantiate a zero-sized vector” before the constructor.
   If the value of rows or columns is not positive, throw invalid\_argument exception with the message “Matrix dimensions must be greater than zero.”
## 11. Explain why there are two versions of overloading the () operator.
## 12. In the method that overloads the multiplication operator, to access an element, the variable temp is assigned (\*this)(i, k). What is the meaning of (\*this) in this context?
## 13. Write out the code for the “cache friendly loop” segment of matrix mutliplication. For the loop variables, use r, s, and t.
   Then indicate a count of the steps on each line. Give the resulting polynomial.
## 14. Finally for this implementation of Matrix1, write C++ code to initialize a 2 x 3 matrix in a main() method (thus testing the constructor and () operator). The matrix should have the values:
    1 2 3
    4 5 6

\*An optional parameter must be given a default value in the event it’s not explicity provided as an argument. The syntax will be constT& initialVal = T()

Explanation:

- const T& means the argument is accepted by constant reference, avoiding an unnecessary copy when passed to the constructor.
- initialVal is the parameter’s name.
- = T() provides a default value, making the argument optional.
- T() value-initializes an object of type T.

For common types, T() usually produces 0 for int, 0.0 for double, false for bool, and empty string for std::string.

# Second matrix implementation: multi-index subscript

Get the code for ModernMatrix. The class definition is not provided (on purpose). An array element is accessed by myArray[theIndex], a single index. We want to use two indexes, as in myMatrix[someRow,someColumn], so we’ll overload the subscript [ ] operator.

**Questions**

## 15. Write out either version of Matrix1::operator(), then show the modification required to implement a two-index subscript.
## 16. Is attempting to copy and modify a good practice for code development in your opinion? Support your answer with pro and con examples.

# Third Matrix Implementation: Raw Arrays & Single Subscript

Get the code for ArrayMattix.

To use a classic array while maintaining dynamic sizing at runtime, we must use a dynamically allocated 1D array via the new and delete[] operators.Because we are managing raw memory directly instead of letting std::vector handle it, we must explicitly implement the **Rule of Three** (Destructor, Copy Constructor, and Copy Assignment Operator) to prevent memory leaks and shallow copy bugs.

To access the matrix using a single-index subscript, the class overloads operator[] to accept a single integer representing the row. To get the 2D look matrix[row][col], this operator returns a **raw pointer** to the start of that specific row. The compiler then automatically applies the second set of brackets [col] directly to that pointer.

This implementation also employs a template mechanism. Read through the code before continuing the discussion below.

The constructor allows for an **optional third parameter**. If no initial value argument is supplied with the method call, then a default value is assigned for every element in the matrix.

ArrayMatrix(size\_t rows, size\_t cols, **const T& initial\_val = T())**
 : m\_rows(rows), m\_cols(cols), m\_data(nullptr) {

**Questions**

## 17. Describe the Rule of Three.
## 18. Implementing the Rule of Three avoids the problems of a memory leak and a shallow copy bug. Give an example of each using C++ code and a brief explanation.
## 19. What is the purpose in the code for the <algorithm> header?
## 20. What will the default value T() assign?
## 21. What function does std::fill() perform?
## 22. List all operators that are overloaded in ArrayMatrix.

## Subscript overloading

The return value of operator[] is a pointer to a row. Let’s spend some time digesting how A[r][c] works. Recall that a pointer may be used with subscript operators (not overloaded) since A[n] is equivalent to \*(A + n). Two dimensional pointer arithmetic gives us
\*(\*(A + r) + c). Going back to subscripts, A[r] returns a pointer to a row (let’s call it aptr\*) so that aptr[c] is the column element in that row. Still digesting?

## Friend Streams

The stream operators >> and << return a reference to the stream object, std::istream& and std::ostream& respectively. This then permits “chaining” commands in statements, such as std::cout << "Result:\n" << matrixA << "\n";

A method using the keyword friend when placed inside a templated class instructs the compiler to automatically instantiate the correct inline non-member function mapping for whichever type T is designated for the matrix object.

Should the user mismatch the data type in the stream, the expression will safely fail by checking by the error checking if (!(is >> matrix.m\_data[i])).

## Programming Task for the third matrix

Write a separate client (test) program for ArrayMatrix such that each method is demonstrated. Turn in the code on paper along with the Questions for this assignment.

# Fourth matrix implementation: malloc and free

Get the code for p1.cpp, p1.h

By this time, you should be familiar with most of the features used here in this p1 class. Go first to the main() function in p1.cpp. You will add to this matrix multiplcation.

This class demonstrates implementing matrix mutliplcation without overloading subscript or parenthesis operators. Only the assignment operator is overloaded to allow copying a matrix.

**Questions**

## 23. Describe in detail how the matrix is constructed and accessed. Your answer should include a description of the use of malloc and free.
## 24. Why is a static\_cast<int> used?
## 25. In multiply, why are left and right declared as const \*int?

## Programming Task for the fourth matrix

Add a call to multiply matrices. Turn in the code for the main() function and show the output of the two matrices to be multiplied and the resulting matrix.

## Extra Credit Task

It has been suggested that the ArrayMatrix design can be modified by implementing The Rule of Five. Describe the Rule of Five and what is required to implement it. Would it improve the code?
