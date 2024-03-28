#include "headers/matrices_calc.hh"


int main(int argc, const char** argv) {
    TwoDimensionalMatrix matrixA;

    int Arow1[] = {1,2,3};
    int Arow2[] = {4,5,6};

    matrixA.add_row(Arow1,sizeof(Arow1)/sizeof(int));
    matrixA.add_row(Arow2,sizeof(Arow2)/sizeof(int));
    matrixA.show();

    TwoDimensionalMatrix matrixB;

    int Brow1[] = {1,4};
    int Brow2[] = {2,5};
    int Brow3[] = {3,6};

    matrixB.add_row(Brow1,sizeof(Brow1)/sizeof(int));
    matrixB.add_row(Brow2,sizeof(Brow2)/sizeof(int));
    matrixB.add_row(Brow3,sizeof(Brow3)/sizeof(int));
    matrixB.show();

    TwoDimensionalMatrix result_matrix = matrixA.calc_product(matrixB);

    result_matrix.show();

    return 0;
}