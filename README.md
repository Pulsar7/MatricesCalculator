<h1 align="center">MatricesCalculator</h1>


<h2>Table of contents</h2>

- [Description](#description)
- [Custom Dynamic-Arrays](#custom-dynamic-arrays)
- [Examples (2D-matrices)](#examples-2d-matrices)
  - [Add two integer-matrices](#add-two-integer-matrices)
  - [Multiply two integer-matrices](#multiply-two-integer-matrices)
- [ToDo](#todo)


## Description

A C++ project that focuses on the calculation with matrices. Functions:

- Add two 2D matrices
- Subtract two 2D matrices
- Multiply two 2D matrices
- Export a given 2D matrix into a static-int array


The C++ file in which the actual arithmetic operations are performed is called `two_dimensional_matrix_operations.cpp` for the 2-dimensional matrices.

## Custom Dynamic-Arrays

At first I tried to store the matrices in my own programmed dynamic lists (concatenated lists), but then decided to use the `std::vector` **Container-Class from the Standard Template Library (STL) of C++** for efficiency and security reasons.
If you're still interested in using this project with custom Dynamic Array Management, you can explore the `custom_dynamic_arrays` directory.


## Examples (2D-matrices)


### Add two integer-matrices

```CPP
TwoDimensionalMatrix<int> matrixA; // Create Object

int Arow1[] = {23,201,2333};
int Arow2[] = {43,532,6348};

matrixA.add_row(Arow1,sizeof(Arow1)/sizeof(int)); // Add row 1
matrixA.add_row(Arow2,sizeof(Arow2)/sizeof(int)); // Add row 2
matrixA.show();

TwoDimensionalMatrix<int> matrixB; // Create Object

int Brow1[] = {13498,449,333};
int Brow2[] = {2393,500,1232};

matrixB.add_row(Brow1,sizeof(Brow1)/sizeof(int)); // Add row 1
matrixB.add_row(Brow2,sizeof(Brow2)/sizeof(int)); // Add row 2
matrixB.show();

TwoDimensionalMatrix<int> result_matrix = matrixA.calc_sum(matrixB);

result_matrix.show();
```

### Multiply two integer-matrices

```CPP
TwoDimensionalMatrix<int> matrixA; // Create Object

int Arow1[] = {23,201,2333}; 
int Arow2[] = {43,532,6348};

matrixA.add_row(Arow1,sizeof(Arow1)/sizeof(int)); // Add row 1
matrixA.add_row(Arow2,sizeof(Arow2)/sizeof(int)); // Add row 2
matrixA.show();

TwoDimensionalMatrix<int> matrixB; // Create Object

int Brow1[] = {13498,449};
int Brow2[] = {2393,500};
int Brow3[] = {234,634};

matrixB.add_row(Brow1,sizeof(Brow1)/sizeof(int)); // Add row 1
matrixB.add_row(Brow2,sizeof(Brow2)/sizeof(int)); // Add row 2
matrixB.add_row(Brow3,sizeof(Brow3)/sizeof(int)); // Add row 3
matrixB.show();

TwoDimensionalMatrix<int> result_matrix = matrixA.calc_product(matrixB);

result_matrix.show();
```


## ToDo

- [ ] Add arithmetic operations for 3-Dimensional matrices
  - [ ] Add multiplication of 3D-matrices
  - [ ] Add addition/subtraction of 3D-matrices