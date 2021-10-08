#pragma once
#include"Figure2D.h"
#include<iostream>
using namespace std;

class Point: public Figure2D
{
	friend  ostream &operator<<(ostream &o, const Point &p);
public:
	
	virtual ~Point();

	Point(char*name, double = 0, double = 0);
	Point(const  char * name, double x, double y);
	Point(const Point &P);
	Point();
	const Point&  operator=(const Point & d);

	virtual void Shift(double dx, double dy);
	virtual void MoveTo(double newX, double newY);
	virtual void Resize(double newL, double newH);
	virtual void Scale(double kx, double ky);
	void print();
	double getX();
	double getY();
	void setX(double);
	void setY(double);

protected:
	double x;
	double y; 

};

