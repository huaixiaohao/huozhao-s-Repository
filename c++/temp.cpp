#include <iostream>
#include <stdlib.h>
using namespace std;

class A
{
public:
	A();
	A(int a);

//private:
	int m_a;
};

A::A()
{
	cout << "A::A()" << endl;
	m_a = 0;
}
A::A(int a)
{
	cout << "A::A(int a)" << endl;
	m_a = a;
}

class B : public A
{
public:
	B(int b);
private:
	int m_b;
};

B::B(int b):A(b)
{
	cout << "B::B(int b)" << endl;
}

int main()
{
	B b(5);
	cout << b.m_a << endl;
	system("pause");
	return 0;
}