#include <iostream>
#include <stdlib.h>
using namespace std;

class A
{
public:
	A();
	~A();
//private:
	int a;
};

A::A()
{
	cout << "A::A()" << endl;
}
A::~A()
{
	cout << "A::~A()" << endl;
}

class B : virtual public  A
{
public:
	B();
	~B();
private:
	int b;
};

B::B()
{
	cout << "B::B()" << endl;
}
B::~B()
{
	cout << "B::~B()" << endl;
}

class C : virtual public  A
{
public:
	C();
	~C();
private:
	int c;
};

C::C()
{
	cout << "C::C()" << endl;
}
C::~C()
{
	cout << "C::~C()" << endl;
};

class D : public  B,public  C
{
public:
	D();
	~D();
private:
	int d;
};

D::D()
{
	cout << "D::D()" << endl;
}
D::~D()
{
	cout << "D::~D()" << endl;
};

int main()
{
	D d;
	d.B::a = 10;
	d.C::a = 20;
	cout << d.B::a << endl;
	cout << d.C::a << endl;
	cout << d.a << endl;
	//cout << sizeof(d) << endl;

	system("pause");
	return 0;
}