#include "headers/matrix.hh"


TwoDimensionalMatrix::TwoDimensionalMatrix() {
    // Constructor
}

TwoDimensionalMatrix::~TwoDimensionalMatrix() {
    // Destructor
}

bool TwoDimensionalMatrix::add_row(int* row, size_t columns) {
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

void TwoDimensionalMatrix::show() {
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

int TwoDimensionalMatrix::get_rows() {
    int row_counter = 0;

    for (std::vector<int> row : this->matrix) {
        row_counter++;
    }
    
    return row_counter;
}

int TwoDimensionalMatrix::get_columns() {
    int column_counter = 0;
    
    if (this->matrix.size() == 0) {
        return column_counter;
    }

    for (int element : this->matrix[0]) {
        column_counter++;
    }
    
    return column_counter;
}

TwoDimensionalMatrix TwoDimensionalMatrix::calc_sum(TwoDimensionalMatrix matrixB) {
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

TwoDimensionalMatrix TwoDimensionalMatrix::calc_product(TwoDimensionalMatrix matrixB) {
    TwoDimensionalMatrix result_matrix;

    if (this->get_rows() != matrixB.get_columns()) {
        printf("<Multiply-Error> Can't multiply two matrices with an invalid amount of rows and columns!");
        return result_matrix;
    }

    std::vector<int> current_row;
    int B_column_counter;
    int current_column;
    for (std::vector<int> rowA : this->matrix) {
        ////////////////// WRONG ///////////////////
        /*B_column_counter = 0;
        current_row.clear();
        current_column = 0;
        for (int A_element : rowA) {
            for (std::vector<int> rowB : matrixB.matrix) {
                current_column += rowB[B_column_counter] * A_element;
            }
            B_column_counter++;
            current_row.push_back(current_column);
        }
        result_matrix.matrix.push_back(current_row);*/
    }

    return result_matrix;
}

void TwoDimensionalMatrix::import_into_static_array(int** static_array) {
    int rows = this->get_rows();
    int columns = this->get_columns();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            static_array[row][col] = this->matrix[row][col];
        }
    }
}