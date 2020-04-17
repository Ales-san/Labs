#ifndef FIGURES_H
#define FIGURES_H
#include <cmath>
#include <iostream>

class Vector2D {
public:
    double x, y;

    Vector2D(double = 0, double = 0);

    double length() const;
    Vector2D operator+(const Vector2D&) const;
    Vector2D operator-(const Vector2D&) const;
    Vector2D operator*(const double) const;
    double operator*(const Vector2D&) const;
    Vector2D operator/(const double) const;
};

std::ostream& operator<< (std::ostream&, const Vector2D&);

class IGeoFig {
public:
	virtual double square() const = 0;
	virtual double perimeter() const = 0;
};

class IPhysObject {
public:
	virtual double mass() const = 0;
	virtual Vector2D position() const = 0;

	virtual bool operator== (const IPhysObject& obj) const = 0;
	virtual bool operator< (const IPhysObject& obj) const = 0;
};

class IPrintable {
public:
	virtual void draw() = 0;
};

class IDialogInitiable {
public:
	virtual void initFromDialog() = 0;
};

class IBaseCObject {
public:
	virtual const char* className() = 0;
	virtual unsigned int size() = 0;
};

class IFigure: public IPhysObject, public IPrintable, public IDialogInitiable, public IGeoFig, public IBaseCObject {
};

#endif