#include "headers/dynamic_arrays.hh"


DynamicArray::DynamicArray() {

}

DynamicArray::~DynamicArray() {
    this->clear(); // Automatically deallocate space
}

bool DynamicArray::clear() {
    if (this->head_ptr == nullptr) {
        // Nothing to delete. Array is empty.
        return false;
    }

    DynamicArrayNode* current_ptr = this->head_ptr;
    while (current_ptr->next_ptr != nullptr) {
        current_ptr = current_ptr->next_ptr;
        free(current_ptr->previous_ptr);
    }

    free(current_ptr);

    return true;
}