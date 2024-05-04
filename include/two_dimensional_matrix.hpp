#ifndef TWO_DIMENSIONAL_MATRIX_HPP
#define TWO_DIMENSIONAL_MATRIX_HPP

#include <iostream>
#include <vector>

// Define a type trait to check if a type is a numeric type
template <typename T> struct is_numeric
{
    static constexpr bool value = std::is_arithmetic<T>::value && !std::is_same<T, bool>::value &&
                                  !std::is_same<T, char>::value && !std::is_same<T, char16_t>::value &&
                                  !std::is_same<T, char32_t>::value && !std::is_same<T, wchar_t>::value;
};

template <typename T, typename U = std::enable_if_t<is_numeric<T>::value>> class TwoDimensionalMatrix
{
  public:
    TwoDimensionalMatrix();
    ~TwoDimensionalMatrix();

    TwoDimensionalMatrix<T, U> calc_sum(TwoDimensionalMatrix<T, U> matrixB);
    TwoDimensionalMatrix<T, U> calc_difference(TwoDimensionalMatrix<T, U> matrixB);
    TwoDimensionalMatrix<T, U> calc_product(TwoDimensionalMatrix<T, U> matrixB);
    TwoDimensionalMatrix<T, U> calc_scalar_product(T scalar);
    TwoDimensionalMatrix<T, U> calc_transpose();

    size_t get_rows_size();
    size_t get_columns_size();
    T get_element(size_t row, size_t column);
    void set_element(size_t row, size_t column, T value);
    bool add_row(T *row, size_t columns);
    void show();
    void export_as_static_array(T **static_array);
    void import_static_array(T **static_array, int rows, int columns);

  private:
    std::vector<std::vector<T>> matrix;
};

#endif