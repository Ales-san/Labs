#include <iostream>

#include "Functions.h"

using namespace std;

int main() {
	int a = 278;
	int b = 872;
	cout << "First task:\nPointers: ";
	swap_pointers(&a, &b);
	cout << a << ' ' << b << "\nRefs: ";
	swap_address(a, b);
	cout << a << ' ' << b << "\n\nSecond task:\n";

	double c = 9.87;
	cout << "Number is: " << c << "\nPointers: ";
	round_pointer(&c);
	cout << c << "\nRefs: ";
	round_address(c);
	cout << c << "\n\nThird task:\n";

	complex d;
	d.real = 5.1;
	d.imaginary = 9.2;
	cout << "Number is: " << d.real << " + " << d.imaginary << "i\nPointers: ";
	complex_multiply_pointer(&d, 0.5);
	cout << d.real << " + " << d.imaginary << "i\nRefs: ";
	complex_multiply_address(d, 0.5);
	cout << d.real << " + " << d.imaginary << "i\n\nFourth task:\n";

	matrix e;
	e = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	cout << "Matrix is:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << e.matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	transpose_pointer(&e);
	cout << "Pointers:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << e.matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	transpose_address(e);
	cout << "Refs:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << e.matrix[i][j] << ' ';
		}
		cout << '\n';
	}

	system("pause");
}
