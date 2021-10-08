#include "Rectangle.h"

Rectangle::Rectangle(const char*name, Point  &p_1, Point &p_2) :Figure2D(abs(p_1.getX() - p_2.getX()), abs(p_1.getY() - p_2.getY()), p_1.getX(), p_2.getY())
{
	this->p1.setX((p_1.getX() <= p_2.getX() ? p_1.getX() : p_2.getX()));
	this->p1.setY((p_1.getY() <= p_2.getY() ? p_1.getY() : p_2.getY()));

	this->p2.setY((p_1.getY() <= p_2.getY() ? p_2.getY() : p_1.getY()));
	this->p2.setX((p_1.getX() <= p_2.getX() ? p_2.getX() : p_1.getX()));

	this->setName(name);
	setHeight();
	setLen();
}

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(const Rectangle &rec)
{
	this->p1 = rec.p1;
	this->p2 = rec.p2;
	this->rec_len = rec.rec_len;
	this->rec_height = rec.rec_height;
	/*this->setName(rec.getName());*/

}

Rectangle::~Rectangle()
{
}

double Rectangle::Perimeter()
{
	return 2 * this->getHeight() + 2 * this->getLength();
}

void Rectangle::setHeight()
{
	this->rec_height =  (abs(p1.getY() - p2.getY()));
}

void Rectangle::setLen()
{
	this->rec_len =  (abs(p1.getX() - p2.getX()));
}



double Rectangle::Area()
{
	return this->getHeight() * this->getLength();
}
double Rectangle::getHeight() { return this->rec_height; }
double Rectangle::getLength() { return this->rec_len; }


void Rectangle::Shift(double dx, double dy)
{
	Figure2D::Shift(dx,dy);
	p1.MoveTo(p1.getX() + dx, p1.getY() + dy);
	p2.MoveTo(p2.getX() + dx, p2.getY() + dy);

}

void Rectangle::Resize(double newL, double newH)
{
	Figure2D::Resize(newL, newH);
	p2.MoveTo(p2.getX() + (newL - this->getLength()), p2.getY() + (newH - this->getHeight()));
	this->rec_height = newH; this->rec_len = newL;

}



void Rectangle::Scale(double kx, double ky)
{
	Figure2D::Scale(kx, ky);
	this->rec_height = rec_height * ky;
	this->rec_len = rec_len * kx;
	p2.MoveTo(p1.getX() + this->getLength(), p1.getY() + this->getHeight());

}

void Rectangle::print()
{
	cout << this->getName() << ": " << p1<<"-" << p2 << endl;

}

bool Rectangle::isInside(Figure2D * P)
{
	if (p1.getX() <= P->getX() && P->getX() <= p2.getX())
	{
		if (p1.getY() <= P->getY() && P->getY() <= p2.getY())
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
