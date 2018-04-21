#include <iostream>
#include <stdlib.h>
using namespace std;

class Time
{
public:
	Time(int h = 0, int m = 0 ,int s = 0);
	void display() const;

	//friend Ti	
	Time& operator++();   //函数重载 ++a   返回引用
	Time operator++ (int yum);  //函数重载  a++  写上函数参数区别a++和++a（构造函数）
								 //int yum 亚元，定义它，不用它
	//friend Time operator+(const Time& t1, const Time& t2);  //友元函数 c = a + b
	Time operator+(const Time& t);   //构造函数 c = a + b

	Time& operator+=(const Time &t);  //构造函数t += t1;
	friend bool operator>(const Time & t1, const Time &t2);  //构造函数 t1 > t2
private:
	int m_hour;
	int m_minute;
	int m_second;
};

Time::Time(int h, int m, int s)
{
	m_hour = h;
	m_minute = m;
	m_second = s;
}

Time& Time::operator+=(const Time &t)    //构造函数t += t1;
{
	m_second += t.m_second;	
	m_minute += t.m_minute;
	m_hour += t.m_hour;

	return *this;
}
bool operator>(const Time & t1, const Time &t2)    //构造函数 t1 > t2
{
	cout << "bool operator>(const Time & t1, const Time &t2)" << endl;
	bool b = t1.m_hour * 3600 + t1.m_minute * 60 + t1.m_second
			 > t2.m_hour * 3600 + t2.m_minute * 60 + t2.m_second;
	return b;
}

Time Time::operator+(const Time& t2)   //构造函数 c = a + b
{
	Time t;
	t.m_second = m_second + t2.m_second;
	t.m_minute = m_minute + t2.m_minute;
	t.m_hour = m_hour + t2.m_hour;

	return t; 
}

//Time operator+(const Time& t1, const Time& t2)  //友元函数 c = a + b
//{
//	Time t;
//	t.m_second = t1.m_second + t2.m_second;
//	t.m_minute = t1.m_minute + t2.m_minute;
//	t.m_hour = t1.m_hour + t2.m_hour;
//
//	return t;
//}

//Time& operator++(Time &t)  // friend : ++a
//{
//	t.m_second++;
//	if (t.m_second == 60)
//	{
//		t.m_second = 0;
//		t.m_minute++;
//		if (t.m_minute == 60)
//		{
//			t.m_minute = 0;
//			t.m_hour++;
//		}
//	}
//	return t;
//}

Time& Time::operator++()   //函数重载 ++a   返回引用（++a使它的返回值改变）
{
	m_second++;
	if (m_second == 60)
	{
		m_second = 0;
		m_minute++;
		if (m_minute == 60)
		{
			m_minute = 0;
			m_hour++;
		}
	}
	return *this;
}

Time Time::operator++ (int yum)  //函数重载  a++  写上函数参数区别a++和++a（构造函数）
                                 //int yum 亚元，定义它，不用它
{
	Time t = *this;
	m_second++;
	return t;
}

void Time::display() const
{
	cout << m_hour << ":" << m_minute << ":" << m_second << endl;
}

int main()
{
	Time t(12, 25, 30);
	cout << "Original:" << endl;;
	t.display();
	cout << endl;

	Time t1 = ++t;
	cout << "++a" << endl;
	t.display();
	t1.display();
	cout << endl;

	Time t2 = t++;
	cout << "a++" << endl;
	t2.display();
	t.display();
	cout << endl;

	Time t3 = t + t1;
	cout << "c = a + b" << endl ;
	t.display();
	t1.display();
	t3.display();
	cout << endl; 

	bool flag;
	flag = t > t1;
	cout << flag << endl;
	  
	system("pause");
	return 0;
}