#include "headers/matrices_calc.hh"
#include <chrono>


int main(int argc, const char** argv) {
    auto start = std::chrono::system_clock::now();

    TwoDimensionalMatrix matrixA;

    int Arow1[] = {23,201,2333};
    int Arow2[] = {43,532,6348};

    matrixA.add_row(Arow1,sizeof(Arow1)/sizeof(int));
    matrixA.add_row(Arow2,sizeof(Arow2)/sizeof(int));
    matrixA.show();

    TwoDimensionalMatrix matrixB;

    int Brow1[] = {13498,449,333};
    int Brow2[] = {2393,500};

    matrixB.add_row(Brow1,sizeof(Brow1)/sizeof(int));
    matrixB.add_row(Brow2,sizeof(Brow2)/sizeof(int));
    matrixB.show();

    TwoDimensionalMatrix result_matrix = matrixA.calc_sum(matrixB);

    result_matrix.show();

    auto delta = std::chrono::system_clock::now() - start;
    auto runtime_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(delta).count();
    std::cout << "Runtime=" << runtime_microseconds << " microseconds" << std::endl;

    return 0;
}