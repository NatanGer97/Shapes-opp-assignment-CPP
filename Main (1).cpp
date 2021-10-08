#include "Figure2D.h"
#include "Point.h"
#include "Segment.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
int main()
{
	Point P("Point P", 10, 20);
	Point Q("Point Q", 20, 0);
	Point T1("Point T1", 15, 10);
	Point T2("Point T2", 15, -10);
	Segment S("Segment PQ", P, Q);
	Rectangle R("Rectangle P-Q", P, Q);
	Square Sq("Square P-Q", P, Q);
	Circle C("Circle P,5", P, 5);
	Square SP5("Square P,5", P, 5);
	cout << "object SP5: perimeter=" << SP5.Perimeter() << ", area=" << SP5.Area() << ", " << SP5 << endl;
	Square SP51=SP5;
	cout << "object SP51: perimeter=" << SP51.Perimeter() << ", area=" << SP51.Area() << ", " << SP51 << endl;
	Square SP52;
	SP52 = SP5;
	cout << "object SP52: perimeter=" << SP52.Perimeter() << ", area=" << SP52.Area() << ", " << SP52 << endl;
	Figure2D *figures[5] = { &S, &R, &Sq, &C};
	figures[4] = new Point("Pt", 2, 6);
	for (int i = 0; i < 5; i++)
	{
		figures[i]->print();
		figures[i]->Resize(2+figures[i]->getLength(), 4+figures[i]->getHeight());
		cout << "after Resize by +2, +4:" << endl;
		cout << *figures[i] << endl;
		figures[i]->print();
		figures[i]->Shift(i+1, i+1);
		cout << "after Shift("<<i+1<<", "<<i+1<<"):" << endl;
		cout << *figures[i] << endl;
		figures[i]->print();
		figures[i]->Scale(0.5, 2);
		cout << "after Scale(0.5, 2):" << endl;
		cout << *figures[i] << endl;
		figures[i]->print();
		cout << "area=" << figures[i]->Area() << ", perimeter=" << figures[i]->Perimeter() << "." << endl;
		T1.Shift(i, i);
		cout << "Point T1 lies inside figure = " << figures[i]->isInside(&T1)<<endl;
		cout << "Point T2 lies inside figure = " << figures[i]->isInside(&T2) << endl;
		cout << endl;
	}
	delete figures[4];
	return 0;
}