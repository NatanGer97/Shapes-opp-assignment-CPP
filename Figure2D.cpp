
#include "Figure2D.h"
#include<iostream>


ostream &operator<<(ostream &o, Figure2D &d)
{
	

		cout << d.getName() << ":";
		cout << " x=" << d.getX();
		cout << ", y=" << d.getY();
		cout << ", length=" << d.getLength() << ",";
		cout << " height=" << d.getHeight() /*<< endl*/;
	
	return cout;
}

void Figure2D::MoveTo(double newX, double newY)
{
	this->x = newX;
	this->y = newY;

}

Figure2D::Figure2D(double l, double h, double x, double y)
{
	this->height = h;
	this->length = l;
	MoveTo(x, y);
}
Figure2D::Figure2D() { ; }

Figure2D::Figure2D(Figure2D &fig)
{
	this->x = fig.getX();
	this->y = fig.getY();
	this->height = fig.getHeight();
	this->length = fig.getLength();
	this->name = fig.name;
}
Figure2D::~Figure2D() {}
const Figure2D & Figure2D::operator=( const Figure2D & d)
{
	this->x = d.x;
	this->y = d.y;
	this->height = d.height;
	this->length = d.length;
	this->setName(d.name);
	return *this;
}

void Figure2D::setName(const char* str)
{
	int size_str = 0;
	int i = 0;
	while (str[size_str]) { size_str++; }
	
	this->name = new char[size_str + 1];
	while (str[i])
	{
		this->name[i] = str[i];
		i++;
	}
	name[i] = '\0';
}
char*Figure2D::getName() { return this->name; }

double Figure2D::getX() { return this->x; }
double Figure2D::getY() { return this->y; }

double Figure2D::getHeight() { return this->height; }
double Figure2D::getLength() { return this->length; }

double Figure2D::Area() { return this->length*this->height; }
double Figure2D::Perimeter() { return this->length * 2 + this->height * 2; }

bool Figure2D::isInside(Figure2D *p)
{
	return 0;
}

void Figure2D::Resize(double newL, double newH)
{
	//MoveTo((newL - (this->getLength()) + this->getX()), newH - (this->getHeight()) + this->getY());
	this->height = newH;
	this->length = newL;

}

void Figure2D::Shift(double dx, double dy)
{
	MoveTo(dx + getX(), dy + getY());
}
void Figure2D::Scale(double kx, double ky)
{
	this->length = kx * this->length;
	this->height = ky * this->height;
}

