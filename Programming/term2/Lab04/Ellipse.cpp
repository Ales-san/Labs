#define _USE_MATH_DEFINES
#include "Ellipse.h"

Ellipse::Ellipse(Vector2D center, double a, double b) : center(center), a(a), b(b) {
	
	if (a < 0 || b < 0 || a < b) {
		throw std::runtime_error("Wrong parameters of ellipse!\n");
	}
}

Ellipse::Ellipse() {}

bool Ellipse::operator==(const IPhysObject& other) const
{
	return mass() == other.mass();
}

bool Ellipse::operator<(const IPhysObject& other) const
{
	return mass() < other.mass();
}

double Ellipse::square() const {
	return (M_PI * a * b);
}

double Ellipse::mass() const {
	return this->square();
}

double Ellipse::perimeter() const {
	return 4 * (M_PI * a * b + (a - b) * (a - b)) / (a + b);
}

Vector2D Ellipse::position() const {
	return center;
}

unsigned Ellipse::size() {
	return sizeof(*this);
}
const char* Ellipse::className() {
	return "Ellipse";
}
void Ellipse::initFromDialog() {
	std::cout << "Create a new ellipse\nEnter center, semi-major axis and semi-minor axis:\n";
	std::cout << "Enter coordinates of center of the ellipse:";
	int x, y;
	std::cin >> x >> y;
	center = Vector2D(x, y);

	std::cout << "Enter semi - major axis and semi - minor axis:";
	std::cin >> x >> y;
	a = x;
	b = y;

	if (a < 0 || b < 0 || a < b) {
		throw std::runtime_error("Wrong parameters of ellipse!\n");
	}
}
void Ellipse::draw() {
	std::cout << "Ellipse's center:\n";
	std::cout << center << '\n';
	std::cout << "With semi-major axis: " << a << ", and semi-minor axis: " << b << '\n';
}