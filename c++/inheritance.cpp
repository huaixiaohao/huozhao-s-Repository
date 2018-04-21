#include <iostream>
#include <stdlib.h>
using namespace std;
#pragma warning(disable:4996)

/**************    Mystring    *****************/

class Mystring
{
public:
	Mystring();
	Mystring(const char *str);
	Mystring(const Mystring &str);
	~Mystring();

	/*********     运算符"="重载里面的函数重载    ********/
	Mystring& operator= (const Mystring& str);
	Mystring& operator= (const char* str);
	Mystring& operator= (char c);

	/*********     运算符"+="重载里面的函数重载    ********/
	Mystring& operator+= (const Mystring& str);
	Mystring& operator+= (const char* str);
	Mystring& operator+= (char c);

	/*********     运算符"[]"重载里面的函数重载    ********/
	const char& operator[] (unsigned int pos) const;
	char& operator[] (unsigned int pos);

	/*********     数据流“<<”函数重载    ********/
	friend ostream& operator<< (ostream& os, Mystring& str);

	/*********     运算符" + "函数重载    ********/
	friend Mystring operator+ (const Mystring& str1, const Mystring& str2);
	friend Mystring operator+ (const char* lhs, const Mystring& rhs);
	friend Mystring operator+ (char lhs, const Mystring& rhs);
	friend Mystring operator+ (const Mystring& lhs, const char* rhs);
	friend Mystring operator+ (const Mystring& lhs, char rhs);

	/*********     运算符" == "函数重载    ********/
	friend bool operator== (const Mystring& lhs, const Mystring& rhs);
	friend bool operator== (const char* lhs, const Mystring& rhs);
	friend bool operator== (const Mystring& lhs, const char* rhs);

	/*********     运算符" > "函数重载    ********/
	friend bool operator> (const Mystring& lhs, const Mystring& rhs);
	friend bool operator> (const char* lhs, const Mystring& rhs);
	friend bool operator> (const Mystring& lhs, const char* rhs);

	void diaplay() const;
private:
	char *m_data;
	unsigned int m_size;
};

Mystring::Mystring()   //无参构造函数
{
	cout << "Mystring::Mystring()" << endl;
	m_data = NULL;
	m_size = 0;
}
Mystring::Mystring(const char *str)   // 有参构造函数
{
	cout << "Mystring::Mystring(const char *str)" << endl;
	m_size = strlen(str);
	m_data = new char[m_size + 1];
	strcpy(m_data, str);
}
Mystring::Mystring(const Mystring &str)  //拷贝构造函数
{
	cout << "Mystring::Mystring(const Mystring &str)" << endl;
	m_size = str.m_size;
	m_data = new char[m_size + 1];
	strcpy(m_data, str.m_data);
}
Mystring::~Mystring()
{
	cout << "Mystring::~Mystring()" << endl;
	if (m_data != NULL)
	{
		delete[]m_data;
		m_data = NULL;
	}
}

/*********     运算符"="重载里面的函数重载    ********/
Mystring& Mystring::operator= (const Mystring& str)
{
	cout << "Mystring& Mystring::operator= (const Mystring& str)" << endl;
	if (m_data != NULL)
	{
		delete[]m_data;
	}

	m_size = str.m_size;
	m_data = new char[m_size + 1];
	strcpy(m_data, str.m_data);

	return *this;
}
Mystring& Mystring::operator= (const char *str)
{
	cout << "Mystring& Mystring::operator= (const char *str)" << endl;
	if (m_data != NULL)
	{
		delete[]m_data;
	}

	m_size = strlen(str);
	m_data = new char[m_size + 1];
	strcpy(m_data, str);

	return *this;
}
Mystring& Mystring::operator= (char c)
{
	cout << "Mystring& Mystring::operator= (char c)" << endl;
	if (m_data != NULL)
	{
		delete[]m_data;
	}

	m_size = 1;
	m_data = new char[m_size + 1];
	m_data[0] = c;
	m_data[1] = '\0';

	return *this;
}

/*********     运算符"+="重载里面的函数重载    ********/
Mystring& Mystring::operator+= (const Mystring& str)
{
	cout << "Mystring& Mystring::operator+= (const Mystring& str)" << endl;
	m_size += str.m_size;
	char *data_cp = m_data;
	m_data = new char[m_size + 1];
	strcpy(m_data, data_cp);
	strcat(m_data, str.m_data);
	delete[]data_cp;

	return *this;
}
Mystring& Mystring::operator+= (const char* str)
{
	cout << "Mystring& Mystring::operator+= (const char* str)" << endl;
	m_size += strlen(str);
	char *data_cp = m_data;
	m_data = new char[m_size + 1];
	strcpy(m_data, data_cp);
	strcat(m_data, str);
	delete[]data_cp;

	return *this;

}
Mystring& Mystring::operator+= (char c)
{
	cout << "Mystring& Mystring::operator+= (char c)" << endl;
	m_size += 1;
	char *data_cp = m_data;
	m_data = new char[m_size + 1];
	strcpy(m_data, data_cp);
	//strcat(m_data, str);   strcat 不能连接字符进去
	m_data[m_size - 1] = c;
	m_data[m_size] = '\0';
	delete[]data_cp;

	return *this;
}

/*********     运算符"[]"重载里面的函数重载    ********/
char& Mystring::operator[] (unsigned int pos)
{
	cout << "char& Mystring::operator[] (unsigned int pos)" << endl;
	return m_data[pos];
}
const char& Mystring::operator[] (unsigned int pos) const
{
	cout << "const char& Mystring::operator[] (unsigned int pos) const" << endl;
	return m_data[pos];
}

/*********     数据流“<<”函数重载    ********/
ostream& operator<< (ostream& os, Mystring& str)
{
	//cout << "ostream& operator<< (ostream& os, Mystring& str)" << endl;
	return os << str.m_data;
}

/*********     运算符" > "函数重载    ********/
bool operator> (const Mystring& lhs, const Mystring& rhs)
{
	cout << "bool operator> (const Mystring& lhs, const Mystring& rhs)" << endl;
	//bool b = strcmp(lhs.m_data, rhs.m_data);
	if (strcmp(lhs.m_data, rhs.m_data) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool operator> (const char* lhs, const Mystring& rhs)
{
	cout << "bool operator> (const char* lhs, const Mystring& rhs)" << endl;
	//bool b = strcmp(lhs, rhs.m_data);
	if (strcmp(lhs, rhs.m_data) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool operator> (const Mystring& lhs, const char* rhs)
{
	cout << "bool operator> (const Mystring& lhs, const char* rhs)" << endl;
	//bool b = strcmp(lhs.m_data, rhs);
	if (strcmp(lhs.m_data, rhs) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*********     运算符" == "函数重载    ********/
bool operator== (const Mystring& lhs, const Mystring& rhs)
{
	cout << "bool operator== (const Mystring& lhs, const Mystring& rhs)" << endl;
	//bool b = strcmp(lhs.m_data, rhs.m_data);
	if (strcmp(lhs.m_data, rhs.m_data) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool operator== (const char* lhs, const Mystring& rhs)
{
	cout << "bool operator== (const char* lhs, const Mystring& rhs)" << endl;
	//bool b = strcmp(lhs, rhs.m_data);
	if (strcmp(lhs, rhs.m_data) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool operator== (const Mystring& lhs, const char* rhs)
{
	cout << "bool operator== (const Mystring& lhs, const char* rhs)" << endl;
	//bool b = strcmp(lhs.m_data, rhs);
	if (strcmp(lhs.m_data, rhs))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Mystring::diaplay() const
{
	cout << "void Mystring::diaplay() const" << endl;
	cout << "m_data : " << m_data << endl;
}

/**************   Person    *****************/

class Person
{
public:
	Mystring getName(void) const;
	int getAge() const;

	void setName(const Mystring &name);
	void setAge(int age);
	void display();

	Person();
	Person(const Mystring &name, int age);
	//~Person();    //没有指针，不需要东西释放，没有析构函数
private:
	Mystring m_name;
	int m_age;
};

Person::Person()
{
	cout << "Person::Person()" << endl;
	m_name = "xiaoming";
	m_age = NULL;
}
Person::Person(const Mystring &name, int age)
{
	cout << "Person::Person(const Mystring &name, int age)" << endl;
	m_name = name;
	m_age = age;
}

void Person::setName(const Mystring &name)
{
	cout << "void Person::setName(const Mystring &name)" << endl;
	m_name = name;
}
void Person::setAge(int age)
{
	cout << "void Person::setAge(int age)" << endl;
	m_age = age;
}

Mystring Person::getName(void) const
{
	return m_name;
}
int Person::getAge() const
{
	return m_age;
}

void Person::display()
{
	cout << "void Person::display()" << endl;
	cout << "name:  " << m_name << endl;
	cout << "age :  " << m_age << endl;
}

class Student : public Person
{
public:
	Student();
	Student(const char *name, int age, const char *sid, int totCred);
	~Student();

	void display();

private:
	Mystring m_sid;
	int m_totCred;
};

Student::Student()
{
	cout << "Student::Student()" << endl;
	m_sid = "00000";
	m_totCred = NULL;
}

Student::Student(const char *name, int age, const char *sid, int totCred):Person(name, age)
{
	cout << "Student::Student(const char *sid, int totCred)" << endl;
	m_sid = sid;
	m_totCred = totCred;
}

Student::~Student()
{
}

void Student::display()
{
	cout << "void Student::display()" << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " <<  getAge() << endl;
 	cout << "StuID:  " << m_sid << endl;
	cout << "TotCred :  " << m_totCred << endl;
}

int main()
{
	Student s( "xiaoming", 23, "123", 233);
	cout << endl;
	s.Person::display();  //显示隐藏的基类
	cout << endl;
	s.display(); 

	system("pause");
	return 0;
}