#include <iostream>
#include <stdlib.h>
using namespace std;

class Time
{
public:
	Time(int h = 0, int m = 0 ,int s = 0);
	void display() const;

	//friend Ti	
	Time& operator++();   //�������� ++a   ��������
	Time operator++ (int yum);  //��������  a++  д�Ϻ�����������a++��++a�����캯����
								 //int yum ��Ԫ����������������
	//friend Time operator+(const Time& t1, const Time& t2);  //��Ԫ���� c = a + b
	Time operator+(const Time& t);   //���캯�� c = a + b

	Time& operator+=(const Time &t);  //���캯��t += t1;
	friend bool operator>(const Time & t1, const Time &t2);  //���캯�� t1 > t2
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

Time& Time::operator+=(const Time &t)    //���캯��t += t1;
{
	m_second += t.m_second;	
	m_minute += t.m_minute;
	m_hour += t.m_hour;

	return *this;
}
bool operator>(const Time & t1, const Time &t2)    //���캯�� t1 > t2
{
	cout << "bool operator>(const Time & t1, const Time &t2)" << endl;
	bool b = t1.m_hour * 3600 + t1.m_minute * 60 + t1.m_second
			 > t2.m_hour * 3600 + t2.m_minute * 60 + t2.m_second;
	return b;
}

Time Time::operator+(const Time& t2)   //���캯�� c = a + b
{
	Time t;
	t.m_second = m_second + t2.m_second;
	t.m_minute = m_minute + t2.m_minute;
	t.m_hour = m_hour + t2.m_hour;

	return t; 
}

//Time operator+(const Time& t1, const Time& t2)  //��Ԫ���� c = a + b
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

Time& Time::operator++()   //�������� ++a   �������ã�++aʹ���ķ���ֵ�ı䣩
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

Time Time::operator++ (int yum)  //��������  a++  д�Ϻ�����������a++��++a�����캯����
                                 //int yum ��Ԫ����������������
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