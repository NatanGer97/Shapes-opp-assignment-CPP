#pragma once
#include"Figure2D.h"
#include"Point.h"
class Rectangle:public Figure2D
{
protected:
	Point p1;
	Point p2;
	double rec_len;
	double rec_height;

public:
	Rectangle(const char*name, Point&, Point&);
	Rectangle();
	Rectangle(const Rectangle&);
	virtual ~Rectangle();
	void setLen();
	void setHeight();
	double getLength();
	double getHeight();

	double Perimeter();
	double Area();
	virtual void Shift(double dx, double dy);
	//virtual void MoveTo(double newX, double newY);
	virtual void Resize(double newL, double newH);
	virtual void Scale(double kx, double ky);
	virtual void print();
	bool isInside(Figure2D *P);

};

