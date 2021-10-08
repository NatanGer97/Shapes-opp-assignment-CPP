#include "Point.h"
using namespace std;

ostream &operator<<(ostream& os, const Point &p)
{
	cout << "Point(" << p.x << ", " << p.y << ")";
	return cout;
}
Point::Point(const char* name, double x, double y) :Figure2D(0.0, 0.0, x, y)
{
	setName(name);
	this->x = x;
	this->y = y;

}
Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;

}
Point::Point()
{
	this->x = 0.0;
	this->y = 0.0;

}
const Point & Point::operator=(const Point & d)
{
	this->x = d.x;
	this->y = d.y;
	return *this;
}
Point::~Point() {}
void Point::MoveTo(double x, double y)
{
	this->x = x;
	this->y = y;
}
double Point::getX() { return this->x; }
double Point::getY() { return this->y; }
void Point::Resize(double newL, double newH) { ; }

void Point::Shift(double dx, double dy)
{
	MoveTo(this->getX() + dx, this->getY() + dx);
}
void Point::Scale(double k_x, double k_y)
{
	this->MoveTo(this->getX()*k_x, this->getY()*k_y);
}

void Point::print()
{
	cout << this->getName() << ":" << " (" << this->getX() << ", " << this->getY() << ")" << endl;
}

void Point::setX(double x)
{
	this->x = x;
}
void Point::setY(double y)
{
	this->y = y;
}

