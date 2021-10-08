#include "Segment.h"


Segment::Segment(const char*name, Point p1, Point p2) :Figure2D(abs(p1.getX() - p2.getX()), abs(p1.getY() - p2.getY()), p1.getX(), p2.getY()),p_1(p1),p_2(p2)
{
	setName(name);

}


Segment::Segment( Point p1, Point p2) :Figure2D(abs(p1.getX() - p2.getX()), abs(p1.getY() - p2.getY()), p1.getX(), p2.getX())
{
	//setName(name);
	;
}
Segment::Segment()
{
	;
}
void Segment::Resize(double newl, double newh)
{

	p_1.MoveTo(p_1.getX() ,p_1.getY()+ (newh-this->getHeight()));
	p_2.MoveTo(p_2.getX() + (newl - this->getLength()), p_2.getY());
	Figure2D::Resize(newl, newh);


}
void  Segment::Shift(double dx, double dy)
{
	Figure2D::Shift(dx, dy);
	p_1.MoveTo(p_1.getX() + dx, p_1.getY() + dy);
	p_2.MoveTo(p_2.getX() + dx, p_2.getY() + dy);

}
void Segment::Scale(double kx, double ky)
{
	Figure2D::Resize(kx * this->getLength(), ky * this->getHeight());

	p_1.MoveTo(p_1.getX(), this->getHeight() + this->getY());
	p_2.MoveTo(this->getLength() + this->getX(), p_2.getY());

}

double Segment::Area() { return 0; }
double Segment::Perimeter()
{
	return (sqrt(pow( this->getLength(), 2) + pow( this->getHeight(), 2)));
}

void Segment::print()
{
	cout << this->getName() << ": " << p_1 << "-" << p_2 << endl;

}

bool Segment::isInside(Figure2D *P)
{
	/*double x_center = (p1.getX() + p2.getY()) / 2;
	double y_center = (p1.getY() + p2.getY()) / 2;
	Point center("center", x_center, y_center);
	if(P->getX()+center.getX())*/
	if (p_1.getX() <= P->getX() && P->getX() <= p_2.getX())
	{
		if (p_1.getY() >= P->getY() && P->getY() >= p_2.getY())
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}