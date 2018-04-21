#include <iostream>
#include <stdlib.h>
using namespace std;
#pragma warning(disable:4996)

class Person
{
public:
	void setName(const char *name);
	void setAge(int age);
	void display();

	Person();
	Person(const char *name, int age);
	~Person();
private:
	char *m_name;
	int m_age;
};

Person::Person()
{
	cout << "Person::Person()" << endl;
	m_name = NULL;
	m_age = 0;
}

Person::Person(const char *name, int age)
{
	cout << "Person::Person(const char *name, int age)" << endl;
	m_name = new char[100];
	if (m_name == NULL)
	{
		delete[]m_name;
		exit(1);
	}
	strcpy(m_name, name);
	m_age = age;
}

Person::~Person()
{
	cout << "Person::~Person()" << endl;
	if (m_name != NULL)
	{
		delete[]m_name;
		m_name = NULL;
	}
}

void Person::setName(const char *name)
{
	cout << "void Person::setName(const char *name)" << endl;
	if (m_name != NULL)
	{
		delete[]m_name;
	}
	m_name = new char[100];
	strcpy(m_name, name);
}

void Person::setAge(int age)
{
	cout << "void Person::setAge(int age)" << endl;
	m_age = age;
}

void Person::display()
{
	cout << "void Person::display()" << endl;
	cout << "name: " << m_name << endl;
	cout << "age " << m_age << endl;
}

int main()
{
	char name[100];
	int age;
	Person p;

	cout << "name :";
	cin >> name;
	cout << "age :";
	cin >> age;

	p.setName(name);
	p.setAge(age);
	p.display();

	system("pause");
	return 0;
}