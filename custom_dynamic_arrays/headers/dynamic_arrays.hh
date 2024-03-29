#ifndef DYNAMIC_ARRAYS_HH
#define DYNAMIC_ARRAYS_HH
#include <stdlib.h>

//
typedef struct DynamicArrayNode {
    void* element;
    struct DynamicArrayNode* next_ptr;
    struct DynamicArrayNode* previous_ptr;
} DynamicArrayNode;
//


class DynamicArray {

public:
    DynamicArray(); // Constructor
    ~DynamicArray(); // Desctructor

    bool clear(); // Delete all elements in array

    // Variables


private:

    // Variables
    DynamicArrayNode* head_ptr = nullptr;
};


#endif // DYNAMIC_ARRAYS_HH