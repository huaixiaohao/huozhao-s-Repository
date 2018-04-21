#include <iostream>
#include <stdarg.h>
using namespace std;

class Myclass
{
public:
	Myclass(int a, int b);
	void getNumber();
	static void getSum();
private:
	int m_a;
	const	int m_b;
	static int sum;
};

int Myclass::sum = 100;

Myclass::Myclass(int a, int b)
{
	m_a = a;
	m_b = b;
	sum += m_a + m_b;
}

void Myclass::getNumber()
{
	cout << "Number = " << m_a << "," << m_b << endl;
}

void Myclass::getSum()
{
	cout << "sum = " << sum << endl;
}

int main()
{
	Myclass m(10, 20);
	m.getSum();

	system("pause");
	return 0;
}