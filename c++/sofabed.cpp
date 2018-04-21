#include <iostream>
#include <stdio.h>
using namespace std;

class Sofa
{
public:
	Sofa();
	~Sofa();

	void watchTV();
private:
	int m_weight;
};

class Bed
{
public:
	Bed();
	~Bed();

	void sleep();
private:
	int m_weight;
};

class SofaBed :public Sofa, public Bed
{
public:
	SofaBed();
	~SofaBed();

private:
};

Sofa::Sofa()
{
	cout << "Sofa::Sofa()" << endl;
}
Sofa::~Sofa()
{
	cout << "Sofa::~Sofa()" << endl;
}

void Sofa::watchTV()
{
	cout << "void Sofa::watchTV()" << endl;
}

Bed::Bed()
{
	cout << "Bed::Bed()" << endl;
}
Bed::~Bed()
{
	cout << "Bed::~Bed()" << endl;
}
void Bed::sleep()
{
	cout << "void Bed::sleep()" << endl;
}

SofaBed::SofaBed()
{
	cout << "SofaBed::SofaBed()" << endl;
}
SofaBed::~SofaBed()
{
	cout << "SofaBed::~SofaBed()" << endl;
}

int main()
{
	SofaBed s;
	system("pause");
	return 0;
}