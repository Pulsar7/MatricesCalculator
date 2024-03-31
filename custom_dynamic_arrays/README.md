# Custom Dynamic-Arrays

As I explained before, I tried to implement the matrices-calulations with self-created dyanmic arrays, instead of the container-class from STL of C++.

**Current Problem**: In order to automatically free the allocated space, the destructor of the **DynamicArray** class calls the **clear()**-Function which tries to free every node in the list. But two-dimensional-matrices are saved within **DynamicArray**s (Nested DynamicArrays). So, there has to be a function that deallocates the space of the child-members and then the space of the „main”-List-Nodes.