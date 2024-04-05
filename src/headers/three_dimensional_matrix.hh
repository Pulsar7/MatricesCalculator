#ifndef THREE_DIMENSIONAL_MATRIX_HH
#define THREE_DIMENSIONAL_MATRIX_HH
#include <type_traits>


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

template <typename T, typename = std::enable_if_t<is_numeric<T>::value>>
class ThreeDimensionalMatrix {

public:
    ThreeDimensionalMatrix(); // Constructor
    ~ThreeDimensionalMatrix(); // Desctructor



};

#endif // THREE_DIMENSIONAL_MATRIX_HH