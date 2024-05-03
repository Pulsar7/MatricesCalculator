#include "../include/two_dimensional_matrix.hpp"

template <typename T, typename U> TwoDimensionalMatrix<T, U>::TwoDimensionalMatrix()
{
}

template <typename T, typename U> TwoDimensionalMatrix<T, U>::~TwoDimensionalMatrix()
{
}

template <typename T, typename U>
TwoDimensionalMatrix<T, U> TwoDimensionalMatrix<T, U>::calc_sum(TwoDimensionalMatrix<T, U> matrixB)
{
    TwoDimensionalMatrix<T, U> resultMatrix;
    if (this->get_rows_size() != matrixB.get_rows_size() || this->get_columns_size() != matrixB.get_columns_size())
    {
        std::cout << "The matrices must have the same dimensions" << std::endl;
        return resultMatrix;
    }

    for (size_t i = 0; i < this->get_rows_size(); ++i)
    {
        std::vector<T> row;
        for (size_t j = 0; j < this->get_columns_size(); ++j)
        {
            row.push_back(this->matrix[i][j] + matrixB.get_element(i, j));
        }
        resultMatrix.matrix.push_back(row);
    }
    return resultMatrix;
}

template <typename T, typename U>
TwoDimensionalMatrix<T, U> TwoDimensionalMatrix<T, U>::calc_difference(TwoDimensionalMatrix<T, U> matrixB)
{
    TwoDimensionalMatrix<T, U> resultMatrix;
    if (this->get_rows_size() != matrixB.get_rows_size() || this->get_columns_size() != matrixB.get_columns_size())
    {
        std::cout << "The matrices must have the same dimensions" << std::endl;
        return resultMatrix;
    }

    for (size_t i = 0; i < this->get_rows_size(); ++i)
    {
        std::vector<T> row;
        for (size_t j = 0; j < this->get_columns_size(); ++j)
        {
            row.push_back(this->matrix[i][j] - matrixB.get_element(i, j));
        }
        resultMatrix.matrix.push_back(row);
    }
    return resultMatrix;
}

template <typename T, typename U>
TwoDimensionalMatrix<T, U> TwoDimensionalMatrix<T, U>::calc_product(TwoDimensionalMatrix<T, U> matrixB)
{
    TwoDimensionalMatrix<T, U> resultMatrix;
    if (this->get_columns_size() != matrixB.get_rows_size())
    {
        std::cout
            << "The number of columns of the first matrix must be equal to the number of rows of the second matrix"
            << std::endl;
        return resultMatrix;
    }
    for (size_t i = 0; i < this->get_rows_size(); ++i)
    {
        std::vector<T> row;
        T element = 0;
        for (size_t j = 0; j < matrixB.get_columns_size(); ++j)
        {
            element += this->matrix[i][j] * matrixB.get_element(j, i);
        }
        row.push_back(element);
        resultMatrix.matrix.push_back(row);
    }
    return resultMatrix;
}

template <typename T, typename U> TwoDimensionalMatrix<T, U> TwoDimensionalMatrix<T, U>::calc_scalar_product(T scalar)
{
    TwoDimensionalMatrix<T, U> resultMatrix;
    for (size_t i = 0; i < this->get_rows_size(); ++i)
    {
        std::vector<T> row;
        for (size_t j = 0; j < this->get_columns_size(); ++j)
        {
            row.push_back(this->matrix[i][j] * scalar);
        }
        resultMatrix.matrix.push_back(row);
    }
    return resultMatrix;
}

template <typename T, typename U> size_t TwoDimensionalMatrix<T, U>::get_rows_size()
{
    return this->matrix.size();
}

template <typename T, typename U> size_t TwoDimensionalMatrix<T, U>::get_columns_size()
{
    return this->matrix[0].size();
}

template <typename T, typename U> T TwoDimensionalMatrix<T, U>::get_element(size_t row, size_t column)
{
    return this->matrix[row][column];
}

template <typename T, typename U> void TwoDimensionalMatrix<T, U>::set_element(size_t row, size_t column, T value)
{
    this->matrix[row][column] = value;
}

template <typename T, typename U> bool TwoDimensionalMatrix<T, U>::add_row(T *row, size_t row_size)
{
    std::vector<T> row_vector(row, row + row_size);
    this->matrix.push_back(row_vector);
    return true;
}

template <typename T, typename U> void TwoDimensionalMatrix<T, U>::show()
{
    printf("[");
    size_t row_counter = 0;
    for (std::vector<T> row : this->matrix)
    {
        size_t counter = 0;
        row_counter++;
        std::cout << "\n  [";
        for (T element : row)
        {
            counter++;
            std::cout << element;
            if (counter != row.size())
            {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (row_counter != this->matrix.size())
        {
            std::cout << ",";
        }
        else
        {
            std::cout << "\n";
        }
    }
    std::cout << "]\n";
}

template <typename T, typename U> void TwoDimensionalMatrix<T, U>::export_as_static_array(T **static_array)
{
    for (size_t i = 0; i < this->get_rows_size(); ++i)
    {
        for (size_t j = 0; j < this->get_columns_size(); ++j)
        {
            static_array[i][j] = this->matrix[i][j];
        }
    }
}

template <typename T, typename U>
void TwoDimensionalMatrix<T, U>::import_static_array(T **static_array, int rows, int columns)
{
    for (int i = 0; i < rows; ++i)
    {
        std::vector<T> row;
        for (int j = 0; j < columns; ++j)
        {
            row.push_back(static_array[i][j]);
        }
        this->matrix.push_back(row);
    }
}

template class TwoDimensionalMatrix<double, std::enable_if_t<is_numeric<double>::value>>;