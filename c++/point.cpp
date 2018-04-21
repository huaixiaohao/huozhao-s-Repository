#include <iostream>
#include <stdlib.h>
#define PI 3.14
using namespace std;

class Point
{
public:
	Point(int x, int y);
	int Getrea();

private:
	int m_x;
	int m_y;
};
class Circle : public Point
{
public:
	Circle(int r);           //���캯��������r��������x��y��  
	double GetArea();           //��Բ�������  
	double GetRadius();         //��ȡԲ�İ뾶��  
};

class Rectangle:public Point
{
public:
	Rectangle(double l, double w);      //���캯��������l��w��������x��y��  
	double GetArea();                   //����ε������  
	double GetLength();                 //��ȡ���εĳ���  
	double GetWidth();                  //��ȡ���εĿ�      
};

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}
int Point::Getrea()
{
	return 0;
}

Circle::Circle(int r) :Point(r, r) {}
double Circle::GetArea()
{
	return PI*r*r;
}
double Circle::GetRadius()
{
	return r;
}

int main()
{
	system("psuse");
	return 0;
}