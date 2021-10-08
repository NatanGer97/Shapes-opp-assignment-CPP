#pragma once
#include"Figure2D.h"
#include"Point.h"
class Segment: public Figure2D
{
	//friend class Point;

protected:
	//char* name;
	Point p_1;
	Point p_2;
	//double height_seg;
	//double lenght_seg;
	//int segment_direction; // 1-left-right,2 -right-left

public:
	//Segment(string, Point, Point);
	Segment(const char * name, Point p1, Point p2);
	Segment(Point p_1, Point p_2);
	//Segment(Point p_1, double num);
	Segment();

	virtual void Resize(double newL, double newH);
	virtual void Shift(double dx, double dy);
	virtual void Scale(double kx, double ky);
	double Perimeter();
	double Area();
	bool isInside(Figure2D *P);
	virtual void print();
	
};