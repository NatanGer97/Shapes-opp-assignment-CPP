#include "Circle.h"
 
Circle::Circle(const char*name, Point&p, double side) :Square(name, p, side*2)
{
	this->setName(name);
	Radius = this->side/2;
}

void Circle::setRadius()
{
	this->Radius = this->side / 2;
}

double Circle::getRadius()
{
	return this->Radius;
}
double Circle::Area() { return 3.1415926535897931*Radius * Radius; }
void Circle::print()
{
	cout << "Circle " << this->getName() << " with center " << "(" << Center.getX() << ", " << Center.getY() << ")" << " and radius = " << this->getRadius() << endl;

}
void Circle::Shift(double dx, double dy)
{
	Square::Shift(dx, dy);
	setRadius();
}
void Circle::Resize(double newL, double newH)
{
	Square::Resize(newL, newH);
	setRadius();

}
void Circle::Scale(double kx, double ky)
{	
	Square::Scale(kx,ky);
	setRadius();

}
double Circle::Perimeter() { return 2 * 3.1415926535897931*Radius; }
