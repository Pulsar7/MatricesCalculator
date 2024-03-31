#ifndef THREE_DIMENSIONAL_MATRIX_HH
#define THREE_DIMENSIONAL_MATRIX_HH
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <iomanip>

template <typename T>
class ThreeDimensionalMatrix {
public:
    ThreeDimensionalMatrix(std::size_t x, std::size_t y, std::size_t z) 
        : dimX(x), dimY(y), dimZ(z), matrix(x, std::vector<std::vector<T>>(y, std::vector<T>(z, 0))) {}

    void set_value(std::size_t x, std::size_t y, std::size_t z, T value) {
        if (x >= dimX || y >= dimY || z >= dimZ) {
            throw std::out_of_range("Index out of bounds");
        }
        matrix[x][y][z] = value;
    }

    T get_value(std::size_t x, std::size_t y, std::size_t z) const {
        if (x >= dimX || y >= dimY || z >= dimZ) {
            throw std::out_of_range("Index out of bounds");
        }
        return matrix[x][y][z];
    }

    void show() const {
        for (size_t i = 0; i < dimX; ++i) {
            for (size_t j = 0; j < dimY; ++j) {
                for (size_t k = 0; k < dimZ; ++k) {
                    std::cout << matrix[i][j][k] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "-----" << std::endl;
        }
    }

    ThreeDimensionalMatrix<T> operator+(const ThreeDimensionalMatrix<T>& rhs) {
        if (dimX != rhs.dimX || dimY != rhs.dimY || dimZ != rhs.dimZ) {
            throw std::invalid_argument("Matrices dimensions do not match");
        }
    
        ThreeDimensionalMatrix<T> result(dimX, dimY, dimZ);
        for (size_t i = 0; i < dimX; ++i) {
            for (size_t j = 0; j < dimY; ++j) {
                for (size_t k = 0; k < dimZ; ++k) {
                    result.set_value(i, j, k, this->get_value(i, j, k) + rhs.get_value(i, j, k));
                }
            }
        }
        return result;
    }
    
    ThreeDimensionalMatrix<T> operator-(const ThreeDimensionalMatrix<T>& rhs) {
        if (dimX != rhs.dimX || dimY != rhs.dimY || dimZ != rhs.dimZ) {
            throw std::invalid_argument("Matrices dimensions do not match");
        }
    
        ThreeDimensionalMatrix<T> result(dimX, dimY, dimZ);
        for (size_t i = 0; i < dimX; ++i) {
            for (size_t j = 0; j < dimY; ++j) {
                for (size_t k = 0; k < dimZ; ++k) {
                    result.set_value(i, j, k, this->get_value(i, j, k) - rhs.get_value(i, j, k));
                }
            }
        }
        return result;
    }
    
    ThreeDimensionalMatrix<T> operator*(const ThreeDimensionalMatrix<T>& rhs) {
        // Simplified multiplication for demonstration purposes
        if (dimY != rhs.dimX || dimZ != rhs.dimY) {
            throw std::invalid_argument("Matrices dimensions do not allow multiplication");
        }
    
        ThreeDimensionalMatrix<T> result(dimX, rhs.dimY, rhs.dimZ);
        for (size_t i = 0; i < dimX; ++i) {
            for (size_t j = 0; j < rhs.dimY; ++j) {
                for (size_t k = 0; k < rhs.dimZ; ++k) {
                    T sum = 0;
                    for (size_t l = 0; l < dimY; ++l) {
                        for (size_t m = 0; m < dimZ; ++m) {
                            sum += this->get_value(i, l, m) * rhs.get_value(l, j, m);
                        }
                    }
                    result.set_value(i, j, k, sum);
                }
            }
        }
        return result;
    }


private:
    std::vector<std::vector<std::vector<T>>> matrix;
    std::size_t dimX, dimY, dimZ;
};

#endif // THREE_DIMENSIONAL_MATRIX_HH
