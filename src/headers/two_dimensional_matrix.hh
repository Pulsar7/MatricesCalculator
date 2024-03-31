#ifndef TWO_DIMENSIONAL_MATRIX_HH
#define TWO_DIMENSIONAL_MATRIX_HH
#include <type_traits>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdexcept> // 

// Define a type trait to check if a type is a numeric type
template <typename T>
struct is_numeric {
    static constexpr bool value =
        std::is_arithmetic<T>::value &&
        !std::is_same<T, bool>::value &&
        !std::is_same<T, char>::value &&
        !std::is_same<T, char16_t>::value &&
        !std::is_same<T, char32_t>::value &&
        !std::is_same<T, wchar_t>::value;
};

template <typename T, typename U = std::enable_if_t<is_numeric<T>::value>>
class TwoDimensionalMatrix {

public:
    TwoDimensionalMatrix(); // Constructor
    ~TwoDimensionalMatrix(); // Desctructor

    TwoDimensionalMatrix<T,U> calc_sum(TwoDimensionalMatrix<T,U> matrixB);
    TwoDimensionalMatrix<T,U> calc_product(TwoDimensionalMatrix<T,U> matrixB);
    int get_rows();
    int get_columns();
    bool add_row(T* row, size_t columns);
    void show();
    void export_as_static_array(T** static_array);
    void import_static_array(T** static_array, int rows, int columns);

    // Variables

private:

    // Variables
    std::vector<std::vector<T>> matrix;
};



template<typename T, typename U>
TwoDimensionalMatrix<T,U>::TwoDimensionalMatrix() {
    // Constructor
}

template<typename T, typename U>
TwoDimensionalMatrix<T,U>::~TwoDimensionalMatrix() {
    // Destructor
}

template<typename T, typename U>
bool TwoDimensionalMatrix<T,U>::add_row(T* row, size_t columns) {
    try {
        std::vector<int> vector_row;

        for (int counter = 0; counter < columns; counter++) {
            vector_row.push_back(row[counter]);
        }

        this->matrix.push_back(vector_row);
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception " << e.what() << std::endl;
    }
    return false;
}

template<typename T, typename U>
void TwoDimensionalMatrix<T,U>::show() {
    printf("[");
    int row_counter = 0;
    for (std::vector<int> row : this->matrix) {
        int counter = 0;
        row_counter++;
        printf("\n  [");
        for (int element : row) {
            counter++;
            printf("%d",element);
            if (counter != row.size()) {
                printf(",");
            }
        }
        printf("]");
        if (row_counter != this->matrix.size()) {
            printf(",");
        } else {
            printf("\n");
        }
    }
    printf("]\n");
}

template<typename T, typename U>
int TwoDimensionalMatrix<T,U>::get_rows() {
    int row_counter = 0;

    for (std::vector<int> row : this->matrix) {
        row_counter++;
    }
    
    return row_counter;
}

template<typename T, typename U>
int TwoDimensionalMatrix<T,U>::get_columns() {
    int column_counter = 0;
    
    if (this->matrix.size() == 0) {
        return column_counter;
    }

    for (int element : this->matrix[0]) {
        column_counter++;
    }
    
    return column_counter;
}

template<typename T, typename U>
TwoDimensionalMatrix<T,U> TwoDimensionalMatrix<T,U>::calc_sum(TwoDimensionalMatrix<T,U> matrixB) {
    TwoDimensionalMatrix result_matrix;

    if (this->get_rows() != matrixB.get_rows()) {
        printf("<Sum-Error> Can't add two matrices with different amount of rows!\n");
        return result_matrix;
    }

    if (this->get_columns() != matrixB.get_columns()) {
        printf("<Sum-Error> Can't add two matrices with different amount of columns!\n");
        return result_matrix;
    }
    
    int row_counter = 0;
    for (std::vector<int> Arow : this->matrix) {
        std::vector<int> current_row;
        int column_counter = 0;
        for (int element : Arow) {
            current_row.push_back(Arow[column_counter]+matrixB.matrix[row_counter][column_counter]);
            column_counter++;
        }
        result_matrix.matrix.push_back(current_row);
        row_counter++;
    }

    return result_matrix;
}

template<typename T, typename U>
TwoDimensionalMatrix<T,U> TwoDimensionalMatrix<T,U>::calc_product(TwoDimensionalMatrix<T,U> matrixB) {
    /*
        Calulate the product of two 2-Dimensional matrices

        „result_matrix = this->matrix * matrixB”
    */
    TwoDimensionalMatrix result_matrix;
    int A_rows = this->get_rows();
    int A_cols = this->get_columns();
    int B_rows = matrixB.get_rows(); // necessary?
    int B_cols = matrixB.get_columns(); // necessary?

    if (A_rows != B_cols) {
        printf("<Multiply-Error> Can't multiply two matrices with an invalid amount of rows and columns!");
        return result_matrix;
    }

    std::vector<int> current_row;

    int col_counter = 0;
    int new_element = 0;
    
    for (std::vector<int> row : this->matrix) { // Iterate rows of this->matrix
        for (int i = 0; i < A_rows; i++) {
            int row_counter = 0;
            for (int element : row) { // Iterate every row-element of this->matrix
                new_element += element * matrixB.matrix[row_counter][col_counter];
                row_counter++;
            }
            col_counter++;
            current_row.push_back(new_element); // Add new element in row for `result_matrix`
            new_element = 0;
        }
        col_counter = 0;
        result_matrix.matrix.push_back(current_row); // Add new row for `result_matrix`
        current_row.clear();
    }

    return result_matrix;
}

template<typename T, typename U>
void TwoDimensionalMatrix<T,U>::export_as_static_array(T** static_array) {
    int rows = this->get_rows();
    int columns = this->get_columns();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            static_array[row][col] = this->matrix[row][col];
        }
    }
}

template<typename T, typename U>
void TwoDimensionalMatrix<T,U>::import_static_array(T** static_array, int rows, int columns) {
    // ???
}


#endif // TWO_DIMENSIONAL_MATRIX_HH