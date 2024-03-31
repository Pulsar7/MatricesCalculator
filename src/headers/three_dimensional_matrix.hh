#ifndef THREE_DIMENSIONAL_MATRIX_HH
#define THREE_DIMENSIONAL_MATRIX_HH
#include "two_dimensional_matrix.hh"

template <typename T, typename = std::enable_if_t<is_numeric<T>::value>>
class ThreeDimensionalMatrix {

public:
    ThreeDimensionalMatrix(); // Constructor
    ~ThreeDimensionalMatrix(); // Desctructor



};

#endif // THREE_DIMENSIONAL_MATRIX_HH