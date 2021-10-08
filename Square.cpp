#include "Square.h"

 ostream &operator<<(ostream &o, Square &d) 
{
	 d.print();
	 //cout << /*endl*/;
	 return cout;
}
 
 const Square& Square:: operator=( Square & d)
 {
	 this->Center = d.Center;
	 this->p1 = d.p1;
	 this->p2 = d.p2;
	 this->side = d.side;
	this-> setName(d.getName());
	 return *this;
 }
Square::Square(const char*name , Point &p_1, Point &p_2):Figure2D(abs(p_1.getX()- p_2.getX()),abs(p_1.getY()-p_2.getY()),p_1.getX(),p_2.getY())
{
	this->setName(name);
	this->p1.MoveTo(this->getX(),this->getY());
	this->p2.MoveTo((this->getX() + this->getLength()), (this->getY() + this->getHeight()));
	this->setCenter();
	setSide(this->getLength());

}

Square::Square()
{
}

Square::Square(const char*name, Point &p, double side):Figure2D(side,side,p.getX(),p.getY())
{
	
	this->setName(name);
	this->p1.MoveTo(p.getX(), p.getY());
	this->p2.MoveTo(p1.getX() + side, p1.getY() + side);
	this->setCenter();
	setSide(side);
}

Square::Square(Square & sq)
{
	this->Center = sq.Center;
	this->p1 = sq.p1;
	this->p2 = sq.p2;
	this->side = sq.side;
	this->setName(sq.getName());
	
}

double Square::Area() { return side * side; }
double Square::Perimeter() { return 4 * side; }

void Square::setSide(double value) { this->side = value; }
double Square::getSide()
{
	return this->side;
}
void Square::setCenter()
{
	this->Center.MoveTo(((p1.getX()+p2.getX()) / 2), ((p1.getY()+p2.getY())/2));

}

void Square::Resize(double newL, double newH)
{
	p2.MoveTo(p2.getX() + (newL - this->getLength()), p2.getY() + (newH - this->getHeight()));
	Figure2D::Resize(newL, newH);
	this->setCenter();
	setSide(this->getLength());



	



}

void Square::Shift(double dx, double dy)
{
	Figure2D::Shift(dx, dy);
	p1.MoveTo(p1.getX() + dx, p1.getY() + dy);
	p2.MoveTo(p2.getX() + dx, p2.getY() + dy);

	this->setCenter();
	setSide(this->getLength());



}

void Square::Scale(double kx, double ky)
{
	Figure2D::Scale(kx, ky);
	p2.MoveTo(p1.getX() + this->getLength(), p1.getY() + this->getHeight());

	//p1.MoveTo(p1.getX(), this->getHeight() + this->getY());
	//p1.MoveTo(this->getLength() + this->getX(), p2.getY());
	this->setCenter();
	setSide(this->getLength());



}
void Square::print()
{
	cout <<"Square "<< this->getName() << " with center " <<"("<< Center.getX() << ", " << Center.getY()<<")" << " and side = "<<this->getSide()<<endl;

}

bool Square::isInside(Figure2D *P)
{
	/*double x_center = (p1.getX() + p2.getY()) / 2;
	double y_center = (p1.getY() + p2.getY()) / 2;
	Point center("center", x_center, y_center);
	if(P->getX()+center.getX())*/
	if (P->getX() >= (Center.getX() - (side / 2)) && P->getX() <= (Center.getX()) + (side / 2))
	{
		if ((P->getY() >= Center.getY() - (side / 2)) && (P->getY() <= Center.getY() + (side / 2)))
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

