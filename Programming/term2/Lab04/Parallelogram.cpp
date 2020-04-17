#include "Parallelogram.h"

Parallelogram::Parallelogram(Vector2D A, Vector2D B, Vector2D C, Vector2D D) : A(A), B(B), C(C), D(D) {
	edgeA = (B - A).length();
	edgeB = (C - B).length();

	if (edgeA != (C - D).length() || edgeB != (A - D).length()) {
		throw std::runtime_error("Wrong parameters of parallelogram!\n");
	}
}

Parallelogram::Parallelogram() {}

bool Parallelogram::operator==(const IPhysObject& other) const
{
	return mass() == other.mass();
}

bool Parallelogram::operator<(const IPhysObject& other) const
{
	return mass() < other.mass();
}

double Parallelogram::square() const {
	return abs((A - B) * (C - B));
}

double Parallelogram::mass() const {
	return this->square();
}

double Parallelogram::perimeter() const {
	return (edgeA + edgeB) * 2;
}

Vector2D Parallelogram::position() const {
	return (C + A) / 2;
}

unsigned Parallelogram::size() {
	return sizeof(*this);
}
const char* Parallelogram::className() {
	return "Parallelogram";
}
void Parallelogram::initFromDialog() {
	std::cout << "Create a new parallelogram\nEnter points from left to right:\n";
	Vector2D points[4];
	for (int i = 0; i < 4; i++) {
		std::cout << "Enter coordinates of " << i + 1 << " point:";
		int x, y;
		std::cin >> x >> y;
		points[i] = Vector2D(x, y);
	}

	edgeA = (points[1] - points[0]).length();
	edgeB = (points[2] - points[1]).length();
    A = points[0];
    B = points[1];
    C = points[2];
    D = points[3];

    if (edgeA != (points[2] - points[3]).length() || edgeB != (points[0] - points[3]).length())
	{
		throw std::runtime_error("Wrong parameters of parallelogram!\n");
	}
}
void Parallelogram::draw() {
	std::cout << "Parallelogram's points:\n";
	std::cout << A << ' ' << B << ' ' << C << ' ' << D << '\n';
	std::cout << "With edges: " << edgeA << ' ' << edgeB << '\n';
}