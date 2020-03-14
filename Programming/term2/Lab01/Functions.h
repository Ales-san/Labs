#pragma once

struct complex {
	double real;
	double imaginary;
};

struct matrix {
	int matrix[3][3];
};

//***
//Task 1
//Swap two variables

void swap_pointers(int *a, int *b);

void swap_address(int &a, int &b);

//***
//Task 2

void round_pointer(double *a);

void round_address(double &a);

//***
//Task 3
//Multiply complex number to the second argument
void complex_multiply_pointer(complex *a, const double b);


void complex_multiply_address(complex &a, const double b);

//***
//Task 4
//Transpose matrix 3 x 3
void transpose_pointer(matrix *a);

void transpose_address(matrix &a);


