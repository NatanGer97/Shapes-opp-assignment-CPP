#pragma once
#include"Figure2D.h"
#include"Point.h"
class Square :public Figure2D
{
	friend ostream &operator<<(ostream &o, Square &d);

protected:
	Point p1;
	Point p2;
	double side;
	Point Center;
public:

	Square(const char*, Point& ,Point&);
	Square();
	Square(const char*, Point& ,double);
	Square(Square& sq);
	const Square &operator=( Square & d);
	
	void setCenter();
	void setSide(double);
	double getSide();
	double Perimeter();
	double Area();
	virtual void Shift(double dx, double dy);
	//virtual void MoveTo(double newX, double newY);
	virtual void Resize(double newL, double newH);
	virtual void Scale(double kx, double ky);
	virtual void print();
	bool isInside(Figure2D *P);

};

