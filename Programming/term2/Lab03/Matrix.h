#pragma once
class Matrix {
	
public:
	int data[3][3];
	Matrix();
	Matrix(int a[3][3]);
	Matrix& operator+(const Matrix&);
	Matrix& operator*(int);
	Matrix& operator*(const Matrix&);
	Matrix& operator-(const Matrix&);

	void show();

	friend bool operator==(const Matrix& a, const Matrix& b);
	friend bool operator!=(const Matrix& a, const Matrix& b);
	friend bool operator>(const Matrix& a, const Matrix& b);
	friend bool operator<(const Matrix& a, const Matrix& b);
};
