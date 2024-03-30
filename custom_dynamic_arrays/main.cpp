#include "headers/main.hh"


int main(int argc, const char** argv) {
    TwoDimensionalMatrix<int> matrix;

    int row[] = {1,2,3,4,5,6,7};

    matrix.add_row(row,sizeof(row)/sizeof(int));

    printf("ADDED ROW\n");

    return 0;
}