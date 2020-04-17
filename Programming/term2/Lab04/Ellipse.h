#pragma once
#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Figures.h"

class Ellipse : public IFigure {
public:
	Vector2D center;
	double a, b;

	Ellipse(Vector2D, double, double);
	Ellipse();

	double mass() const override;
	Vector2D position() const override;

	double square() const override;
	double perimeter() const override;

	unsigned size() override;
	const char* className() override;

	void initFromDialog() override;
	void draw() override;

	bool operator==(const IPhysObject&) const override;
	bool operator< (const IPhysObject&) const override;

};

#endif