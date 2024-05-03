#ifndef CUSTOM_MATRIX_HPP
#define CUSTOM_MATRIX_HPP
#include "dynamic_arrays.hpp"
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

template<typename T>
TwoDimensionalMatrix<T>::TwoDimensionalMatrix() {
    // Constructor
}

template<typename T>
TwoDimensionalMatrix<T>::~TwoDimensionalMatrix() {
    // Destructor
}

template<typename T>
bool TwoDimensionalMatrix<T>::add_row(T* row, size_t columns) {
    try {
        DynamicArray<T> dyn_array_row;

        for (int counter = 0; counter < columns; counter++) {
            dyn_array_row.append(row[counter]);
        }
        this->matrix.append(dyn_array_row);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception " << e.what() << std::endl;
    }

    return false;
}


#endif // CUSTOM_MATRIX_HH