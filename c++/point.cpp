#include <iostream>
#include <cstdlib>
using namespace std;
#define PI 3.1415926

/**************  Point  ***************/
class Point
{
public:
	Point(const int x = 0, const int y = 0);
	void print();
	void setX(int x);
	void setY(int y);
	virtual double area() = 0;
	virtual double vol() = 0;

protected:
	int p_x;
	int p_y;

};

Point::Point(const int x, const int y)
{
	p_x = x;
	p_y = y;
}

void Point::setX(int x)
{
	p_x = x;
}

void Point::setY(int y)
{
	p_y = y;
}

void Point::print()
{
	cout << "x = " << p_x << "y = " << p_y << endl;
}

/**************  Circle  ***************/

class Circle : public Point
{
public:
	Circle(double r = 0.0, int x = 0, int y = 0);
	double area();
	void c_print();

protected:
	double c_r;

};

Circle::Circle(double r, int x, int y) : Point(x, y)
{
	c_r = r;
}

double Circle::area()
{
	cout << c_r << endl;
	return PI * c_r * c_r;
}

void Circle::c_print()
{
	cout << "circle's area is " << area() << endl;
}

/**************  Cylinder  ***************/
class Cylinder : public Circle
{
public:
	Cylinder(double h, double r, int x, int y);
	double vol();
	void cy_setH(double h);
	void cy_print();

private:
	double cy_h;

};

Cylinder::Cylinder(double h, double r, int x, int y):Circle(r, x, y)
{
	cy_h = h;
}

double Cylinder::vol()
{
	cout << cy_h << endl;
	return area() * cy_h;
}

void Cylinder::cy_setH(double h)
{
	cy_h = h;
}

void Cylinder::cy_print()
{
	cout << "cylinder's vol is " << vol() << endl;
}

int main()
{
	Cylinder cylin(5.0, 2.0, 1, 1);
	cylin.c_print();
	cylin.cy_print();
	system("pause");
	return 0;
}
