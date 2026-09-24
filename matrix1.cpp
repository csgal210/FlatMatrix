// matrix1:
/*
Key Design NotesFlat
1D Vector: Instead of using a slow, fragmented std::vector<std::vector<T>>,
a flat array or vector is preferred for raw computing performance. It
speeds up cache access due to contiguous memory spatial locality.
Function Overload operator(): Prior to C++23, the classic array index
operator (operator[]) could only accept one parameter. Therefore, standard
custom matrix classes overload the parenthesis operator () to accept multiple
parameters like matrix(row, col).

Const Correctness: Both operator() and individual methods like print() have duplicated
const variations. This allows the Matrix instances to be safely passed around as
read-only references (const Matrix<T>&).
*/

#include "matrix1.h"
#include <stdexcept>

int main() {
    try {
        // Initialize two 2x3 matrices with different initial values
        Matrix1<double> mat1(2, 3, 1.5);
        Matrix1<double> mat2(2, 3, 2.0);

        // Modify individual elements
        mat1(0, 1) = 5.5;
        mat2(1, 2) = 4.0;

        std::cout << "Matrix 1:\n";
        mat1.print();

        std::cout << "\nMatrix 2:\n";
        mat2.print();

        // Perform matrix addition
        Matrix1<double> mat3 = mat1 + mat2;

        std::cout << "\nResult of Matrix 1 + Matrix 2:\n";
        mat3.print();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    try {
        // Create a 2x3 matrix
        Matrix1<int> mat1(2, 3);
        mat1(0,0)=1; mat1(0,1)=2; mat1(0,2)=3;
        mat1(1,0)=4; mat1(1,1)=5; mat1(1,2)=6;

        // Create a 3x2 matrix
        Matrix1<int> mat2(3, 2);
        mat2(0,0)=7;  mat2(0,1)=8;
        mat2(1,0)=9;  mat2(1,1)=10;
        mat2(2,0)=11; mat2(2,1)=12;

        std::cout << "Matrix A (2x3):\n"; mat1.print();
        std::cout << "\nMatrix B (3x2):\n"; mat2.print();

        Matrix1<int> result = mat1 * mat2; // Expecting a 2x2 matrix
        std::cout << "\nResult of A * B (2x2):\n"; result.print();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
