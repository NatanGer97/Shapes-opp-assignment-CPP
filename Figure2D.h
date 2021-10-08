#pragma once
#include<string>
using namespace std;
#include <math.h>
#include<typeinfo>

class Figure2D {
private:
	double x;
	double y;
	double length;
	double height;
	char*  name = NULL;//=NULL Needed for compiler of the testing engine
public:
	Figure2D(double l, double h, double x = 0, double y = 0);
	Figure2D(Figure2D &f);
	Figure2D();
	virtual ~Figure2D();
	const Figure2D &operator=(const Figure2D &d);
	void setName(const char* str);
	virtual double getY();
	virtual double getX();
	virtual double getLength();
	virtual double getHeight();
	/*const*/ char*getName();
	virtual double Area();
	virtual double Perimeter();
	virtual void Shift(double dx, double dy) = 0;
	virtual void MoveTo(double newX, double newY);
	virtual void Resize(double newL, double newH) = 0;
	virtual void Scale(double kx, double ky) = 0;
	virtual bool isInside(Figure2D *P);//Point(P->getX(),P->getY()) lies inside the figure
	virtual void print() = 0;
	friend ostream &operator<<(ostream &o, Figure2D &d);
};
