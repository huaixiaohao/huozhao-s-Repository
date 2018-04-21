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
	Circle(int r);           //构造函数，并用r构造基类的x和y。  
	double GetArea();           //求圆的面积。  
	double GetRadius();         //获取圆的半径。  
};

class Rectangle:public Point
{
public:
	Rectangle(double l, double w);      //构造函数，并用l和w构造基类的x和y。  
	double GetArea();                   //求矩形的面积。  
	double GetLength();                 //获取矩形的长。  
	double GetWidth();                  //获取矩形的宽。      
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