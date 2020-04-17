#pragma once
#include <vector>
#include "Ellipse.h"
#include "Parallelogram.h"

#ifndef SYSTEMFIGURE_H
#define SYSTEMFIGURE_H
class SystemFigure {
public:
	std::vector <IFigure *> figures;
	void start();
	void menu();
private:
	void add();
	void draw();
	void square();
	void perimeter();
	void center();
	void size();
	void figure_sort();
	void do_command(int);
};

#endif