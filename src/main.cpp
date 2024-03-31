#include "headers/matrices_calc.hh"
#include <chrono>


int main(int argc, const char** argv) {
    auto start = std::chrono::system_clock::now();

    TwoDimensionalMatrix<double> matrixA;

    double Arow1[] = {1.0,2.0,3.0};
    double Arow2[] = {4.0,5.0,6.0};

    matrixA.add_row(Arow1,sizeof(Arow1)/sizeof(double));
    matrixA.add_row(Arow2,sizeof(Arow2)/sizeof(double));
    matrixA.show();

    TwoDimensionalMatrix<double> result_matrix = matrixA.calc_scalar_product(1.5);
    result_matrix.show();

    auto delta = std::chrono::system_clock::now() - start;
    auto runtime_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(delta).count();
    std::cout << "Runtime=" << runtime_microseconds << " microseconds" << std::endl;

    // Creating two 3D matrices of size 2x2x2 for demonstration
    ThreeDimensionalMatrix<int> matrix1(2, 2, 2);
    ThreeDimensionalMatrix<int> matrix2(2, 2, 2);

    // Initializing matrix1 with some values
    matrix1.set_value(0, 0, 0, 1);
    matrix1.set_value(0, 0, 1, 2);
    matrix1.set_value(0, 1, 0, 3);
    matrix1.set_value(0, 1, 1, 4);
    matrix1.set_value(1, 0, 0, 5);
    matrix1.set_value(1, 0, 1, 6);
    matrix1.set_value(1, 1, 0, 7);
    matrix1.set_value(1, 1, 1, 8);

    // Initializing matrix2 with some values
    matrix2.set_value(0, 0, 0, 8);
    matrix2.set_value(0, 0, 1, 7);
    matrix2.set_value(0, 1, 0, 6);
    matrix2.set_value(0, 1, 1, 5);
    matrix2.set_value(1, 0, 0, 4);
    matrix2.set_value(1, 0, 1, 3);
    matrix2.set_value(1, 1, 0, 2);
    matrix2.set_value(1, 1, 1, 1);

    // Performing arithmetic operations
    ThreeDimensionalMatrix<int> sumMatrix = matrix1 + matrix2;
    ThreeDimensionalMatrix<int> diffMatrix = matrix1 - matrix2;
    ThreeDimensionalMatrix<int> prodMatrix = matrix1 * matrix2;

    // Displaying results
    std::cout << "Sum of Matrix 1 and Matrix 2:" << std::endl;
    // Display sumMatrix
    sumMatrix.show();

    std::cout << "\nDifference between Matrix 1 and Matrix 2:" << std::endl;
    // Display diffMatrix
    diffMatrix.show();

    std::cout << "\nProduct of Matrix 1 and Matrix 2:" << std::endl;
    // Display prodMatrix
    prodMatrix.show();

    return 0;
}
