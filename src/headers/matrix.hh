#ifndef MATRIX_HH
#define MATRIX_HH
#include <stdio.h>
#include <vector>
#include <iostream>


class TwoDimensionalMatrix {

public:
    TwoDimensionalMatrix(); // Constructor
    ~TwoDimensionalMatrix(); // Desctructor

    TwoDimensionalMatrix calc_sum(TwoDimensionalMatrix matrixB);
    int get_rows();
    int get_columns();
    bool add_row(int* row, size_t columns);
    void show();

    // Variables

private:

    // Variables
    std::vector<std::vector<int>> matrix;
};


#endif // MATRIX_HH