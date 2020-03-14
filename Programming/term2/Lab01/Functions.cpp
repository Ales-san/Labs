#pragma once
#include "Functions.h"
//***
//Task 1
//Swap two variables

void swap_pointers(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void swap_address(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

//***
//Task 2
//Round real number
void round_pointer(double *a) {
	if (*a - (int)(*a) < 0.5) {
		*a = (int)(*a);
	}
	else {
		*a = (int)(*a) + 1;
	}
}

void round_address(double &a) {
	if (a - (int)(a) < 0.5) {
		a = (int)(a);
	}
	else {
		a = (int)(a)+1;
	}
}

//***
//Task 3
//Multiply complex number to the second argument
void complex_multiply_pointer(complex *a, const double b) {
	a->real *= b;
	a->imaginary *= b;
}


void complex_multiply_address(complex &a, const double b) {
	a.real *= b;
	a.imaginary *= b;
}

//***
//Task 4
//Transpose matrix 3 x 3

void transpose_pointer(matrix *a) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			swap_address(a->matrix[j][i], a->matrix[i][j]);
		}
	}
}

void transpose_address(matrix &a) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			swap_address(a.matrix[j][i], a.matrix[i][j]);
		}
	}
}


