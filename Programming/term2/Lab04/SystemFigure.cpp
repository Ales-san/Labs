#include "SystemFigure.h"
#include <algorithm>

void SystemFigure::start() {
	while (true) {
		menu();
	}
}
void SystemFigure::menu() {
	std::cout << "Enter the number of command to do:\n";
	std::cout << "1) Get information about all created figures\n";
	std::cout << "2) Add figure\n";
	std::cout << "3) Get total perimeter\n";
	std::cout << "4) Get total square\n";
	std::cout << "5) Get total size\n";
	std::cout << "6) Get center of the mass\n";
	std::cout << "7) Sort figures by the mass\n";
	std::cout << "8) Exit\n";

	int number;
	std::cin >> number;
	do_command(number);

}

void SystemFigure::add() {
	std::cout << "Enter 1, if you want to create the ELLIPSE\n";
	std::cout << "Enter 2, if you want to create the PARALLELOGRAM\n";
	int number;
	std::cin >> number;
	if (number != 1 && number != 2) {
		throw std::runtime_error("Wrong number of the command");
	}
	if (number == 1) {
		figures.push_back(new Ellipse());
	} else {
		figures.push_back(new Parallelogram());
	}
	figures.back()->initFromDialog();
}

void SystemFigure::draw() {
	for (auto figure : figures) {
		figure->draw();
	}
}

void SystemFigure::square() {
	double sum = 0;
	for (auto figure : figures) {
		sum += figure->square();
	}
	std::cout << "Total square of figures: " << sum << '\n';
}

void SystemFigure::perimeter() {
	double sum = 0;
	for (auto figure : figures) {
		sum += figure->perimeter();
	}
	std::cout << "Total perimeter of figures: " << sum << '\n';
}

void SystemFigure::center() {
	Vector2D res(0, 0);
	double sum = 0;
	for (auto figure : figures) {
		double mass = figure->mass();
		Vector2D pos = figure->position();
		sum += mass;
		res = res + pos * mass;
	}
	res = res / sum;
	std::cout << "Center of the mass of the system: " << res << '\n';
}
void SystemFigure::size() {
	int sum = 0;
	for (auto figure : figures) {
		sum += figure->size();
	}
	std::cout << "Total size of figures: " << sum << '\n';
}
void SystemFigure::figure_sort() {
	sort(figures.begin(), figures.end());
}
void SystemFigure::do_command(int number) {
	switch (number)
	{
	case 1:
		draw();
		break;
	case 2:
		add();
		break;
	case 3:
		perimeter();
		break;
	case 4:
		square();
		break;
	case 5:
		size();
		break;
	case 6:
		center();
	case 7:
		figure_sort();
		break;
	case 8:
		exit(0);
		break;
	default:
		throw std::runtime_error("Wrong number of the command!");
	}
}