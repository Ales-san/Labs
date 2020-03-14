#include "Matrix.h"
#include <algorithm>
#include <iostream>

Matrix::Matrix() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->data[i][j] = 0;
		}
	}
}

Matrix::Matrix(int a[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->data[i][j] = a[i][j];
		}
	}
}

Matrix& Matrix::operator+(const Matrix& b) {
	Matrix res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.data[i][j] = this->data[i][j] + b.data[i][j];
		}
	}
	return res;
}

Matrix& Matrix::operator-(const Matrix& b) {
	Matrix res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.data[i][j] = this->data[i][j] - b.data[i][j];
		}
	}
	return res;
}

Matrix& Matrix::operator*(int b) {
	Matrix res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.data[i][j] = this->data[i][j] * b;
		}
	}
	return res;
}

Matrix& Matrix::operator*(const Matrix& b) {
	Matrix res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				res.data[i][j] += this->data[i][j] * b.data[i][j];
			}
		}
	}
	return res;
}

bool operator==(const Matrix& a, const Matrix& b) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a.data[i][j] != b.data[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool operator!=(const Matrix& a, const Matrix& b) {
	return !(a == b);
}
bool operator>(const Matrix& a, const Matrix& b) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a.data[i][j] > b.data[i][j]) {
				return true;
			} else if (a.data[i][j] < b.data[i][j]) {
				return false;
			}
		}
	}
	return false;
}
bool operator<(const Matrix& a, const Matrix& b) {
	return !(a > b);
}

void Matrix::show() {
	std::cout << '\n';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << this->data[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
