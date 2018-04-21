#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#pragma warning(disable:4996)  // strcpy可以使用

class Person
{
//private:
public:
	char *m_name;
	int m_age;
public:
	Person();	//无参的构造函数
	~Person();	//析构函数
	Person(const char *name, int age);  //有参的构造函数
	Person &operator = (const  Person &p);  //运算符重载，赋值函数
	Person(const Person &p);	//拷贝构造函数

	//成员函数
	void setName(const char *name);		
	void setAge(int age);
	void dis();
};

Person::Person()    //无参的构造函数
{
	cout << "Person::Person()" << endl;
	m_name = NULL;
	m_age = 0;
}

Person::~Person()   //析构函数
{
	cout << "Person::~Person()" << endl;
	if (m_name != NULL)
	{
  		delete[]m_name;
	}
}

Person::Person(const char *name, int age)     //有参的构造函数
{
	cout << "Person::Person(const char *name, int age)" << endl;
	this->m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	this->m_age = age;	
}

Person &Person::operator = (const  Person &p)   //运算符重载，赋值函数
{
	cout << "Person &Person::operator = (const  Person &p)" << endl;
	this->m_name = new char[strlen(p.m_name) + 1];
	strcpy(m_name, p.m_name);
	this->m_age = p.m_age;
	return *this;
}

Person::Person(const Person &p)    //拷贝构造函数
{
	cout << "Person::Person(const Person &p)" << endl;

	this->m_name = new char[strlen(p.m_name) + 1];
    strcpy(m_name, p.m_name);
	this->m_age = p.m_age;
}

/***************      成员函数的实现          *******************/

void Person::setName(const char *name)
{
	cout << "void Person::setName(const char *name)" << endl;
	if (m_name != NULL)
	{
		delete[]m_name;
		exit(1);
	}
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}
void Person::setAge(int age)
{
	cout << "void Person::setAge(int age)" << endl;
	m_age = age;
}

void Person::dis()
{
	cout << "void Person::dis()" << endl;
	cout << "NAME : " << m_name << endl;
	cout << "AGE : " << m_age << endl;
}
int main()
{
	Person p("ixaomin", 40);
	Person p1 = p;
	Person p2;
	p2.operator = (p1);


	system("pause");
	return 0;
}