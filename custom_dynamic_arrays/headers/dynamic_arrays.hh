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
    bool remove(int index); // Remove element from array by its index
    int get_len(); // Get amount of elements in array

    // Variables


private:

    // Variables
    DynamicArrayNode<T>* head_ptr = nullptr;
    bool cleared;
};


template<typename T>
DynamicArray<T>::DynamicArray() {
    this->cleared = false;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    if (!this->cleared) {
        this->clear(); // Automatically deallocate space
    }
}

template<typename T>
bool DynamicArray<T>::clear() {
    printf("CLEARING...\n");
    if (this->head_ptr == nullptr) {
        // Nothing to delete. Array is empty.
        return false;
    }

    DynamicArrayNode<T>* current_ptr = this->head_ptr;
    while (current_ptr->next_ptr != nullptr) {
        current_ptr = current_ptr->next_ptr;
        free(current_ptr->previous_ptr);
    }

    free(current_ptr);

    this->cleared = true;

    


    return true;
}

template<typename T>
bool DynamicArray<T>::append(T element) {
    // Initialize pointers
    DynamicArrayNode<T>* node_ptr = nullptr;
    DynamicArrayNode<T>* current_ptr = nullptr;
    DynamicArrayNode<T>* former_last_ptr = nullptr;

    // Allocate memory for the new node
    node_ptr = (DynamicArrayNode<T>*)calloc(1,sizeof(DynamicArrayNode<T>)); // or malloc(sizeof(DynamicArrayNode<T>)); - probably better
    if (node_ptr == nullptr) {
        printf("<AllocationError> Couldn't allocate new space for node!\n");
        return false;
    }

    // Append element at the end of the list
    if (this->head_ptr == nullptr) {
        // Initialization Node
        this->head_ptr = node_ptr;
    } else {
        current_ptr = this->head_ptr;
        while (current_ptr->next_ptr != nullptr) {
            current_ptr = current_ptr->next_ptr;
        }
        former_last_ptr = current_ptr;
        current_ptr->next_ptr = node_ptr; // Append new node to former last node
    }

    // Initialize the new node
    node_ptr->next_ptr = nullptr;
    if (former_last_ptr != nullptr) {
        node_ptr->previous_ptr = former_last_ptr;
    } else {
        node_ptr->previous_ptr = nullptr;
    }

    node_ptr->element = element;

    return true;
}

template<typename T>
int DynamicArray<T>::get_len() {
    int counter = 0;
    if (this->head_ptr == nullptr) {
        // No elements in array
        return counter;
    }

    DynamicArrayNode<T>* current_ptr = this->head_ptr;
    // Iterate whole list
    while (current_ptr != nullptr) {
        counter++;
        current_ptr = current_ptr->next_ptr;
    }
 
    return counter;
}

template<typename T>
bool DynamicArray<T>::remove(int index) {
    if (index > this->get_len()-1) {
        // Index is bigger than the actual length of the list
        return false;
    }

    int counter = 0;
    DynamicArrayNode<T>* current_ptr = this->head_ptr;
    while (current_ptr != nullptr) {
        if (counter == index) {
            break;
        }
        current_ptr = current_ptr->next_ptr;
        counter++;
    }

    if (current_ptr->next_ptr == nullptr) {
        // current_ptr is the last element in the list
        current_ptr->previous_ptr->next_ptr = nullptr; // previous_ptr is now the last element in the list
        free(current_ptr);
        return true;
    }

    if (current_ptr->previous_ptr == nullptr) {
        // current_ptr is the first element in the list
        current_ptr->next_ptr->previous_ptr = nullptr; // next_ptr is not the first element in the list
        free(current_ptr);
        return true;
    }

    // Current Node is between two nodes
    current_ptr->next_ptr->previous_ptr = current_ptr->previous_ptr;
    current_ptr->previous_ptr->next_ptr = current_ptr->next_ptr;
    free(current_ptr);

    return true;
}

#endif // DYNAMIC_ARRAYS_HH