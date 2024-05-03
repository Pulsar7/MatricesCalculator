#include "../include/two_dimensional_matrix.hpp"
#include <chrono>

int main()
{
    auto start = std::chrono::system_clock::now();

    TwoDimensionalMatrix<double> matrixA;

    double Arow1[] = {1.0, 2.0, 3.0};
    double Arow2[] = {4.0, 5.0, 6.0};

    matrixA.add_row(Arow1, sizeof(Arow1) / sizeof(double));
    matrixA.add_row(Arow2, sizeof(Arow2) / sizeof(double));
    matrixA.show();

    TwoDimensionalMatrix<double> result_matrix = matrixA.calc_scalar_product(1.5);
    result_matrix.show();

    auto delta = std::chrono::system_clock::now() - start;
    auto runtime_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(delta).count();
    std::cout << "Runtime=" << runtime_microseconds << " microseconds" << std::endl;

    return 0;
}