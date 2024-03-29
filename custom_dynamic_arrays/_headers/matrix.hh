#ifndef CUSTOM_MATRIX_HH
#define CUSTOM_MATRIX_HH
#include "dynamic_arrays.hh"
#include <iostream>


template<typename T>
class TwoDimensionalMatrix {

public:
    TwoDimensionalMatrix(); // Constructor
    ~TwoDimensionalMatrix(); // Destructor
    bool add_row(T* row, size_t columns);

    // Variables
    DynamicArray<DynamicArray<T>> matrix;
private:

    // Variables

};


#endif // CUSTOM_MATRIX_HH