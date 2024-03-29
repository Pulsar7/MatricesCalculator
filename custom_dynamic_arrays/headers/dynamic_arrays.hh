#ifndef DYNAMIC_ARRAYS_HH
#define DYNAMIC_ARRAYS_HH
#include <stdlib.h>
#include <stdio.h>

//
template<typename T>
struct DynamicArrayNode {
    T element;
    struct DynamicArrayNode<T>* next_ptr;
    struct DynamicArrayNode<T>* previous_ptr;
};
//


template<typename T>
class DynamicArray {

public:
    DynamicArray(); // Constructor
    ~DynamicArray(); // Desctructor

    bool clear(); // Delete all elements in array
    bool append(T element); // Append element to array

    // Variables


private:

    // Variables
    DynamicArrayNode<T>* head_ptr = nullptr;
};


#endif // DYNAMIC_ARRAYS_HH