#pragma once

#include "Figures.h"
#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
class Parallelogram : public IFigure {
public:
	Vector2D A, B, C, D;
	double edgeA, edgeB;

	Parallelogram(Vector2D, Vector2D, Vector2D, Vector2D);
	Parallelogram();

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