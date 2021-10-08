#pragma once
#include"Square.h"
class Circle:public Square
{
private:
	double Radius;

public:
	Circle(const char*name, Point &, double);
	void setRadius();
	double getRadius();
	double Perimeter();
	double Area();
	void print();
	virtual void Shift(double dx, double dy);
	//virtual void MoveTo(double newX, double newY);
	virtual void Resize(double newL, double newH);
	virtual void Scale(double kx, double ky);

};

