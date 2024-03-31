#include "headers/matrices_calc.hh"
#include <chrono>


int main(int argc, const char** argv) {
    auto start = std::chrono::system_clock::now();

    TwoDimensionalMatrix<int> matrixA;

    int Arow1[] = {1,2,3};
    int Arow2[] = {4,5,6};

    matrixA.add_row(Arow1,sizeof(Arow1)/sizeof(int));
    matrixA.add_row(Arow2,sizeof(Arow2)/sizeof(int));
    matrixA.show();

    TwoDimensionalMatrix<int> matrixB;

    int Brow1[] = {1,2,3};
    int Brow2[] = {4,5,6};

    matrixB.add_row(Brow1,sizeof(Brow1)/sizeof(int));
    matrixB.add_row(Brow2,sizeof(Brow2)/sizeof(int));
    matrixB.show();

    TwoDimensionalMatrix<int> result_matrix = matrixA.calc_difference(matrixB);

    result_matrix.show();

    auto delta = std::chrono::system_clock::now() - start;
    auto runtime_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(delta).count();
    std::cout << "Runtime=" << runtime_microseconds << " microseconds" << std::endl;

    return 0;
}