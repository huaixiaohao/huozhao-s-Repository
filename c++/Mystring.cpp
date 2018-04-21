#include <iostream>
#include <string.h>
#include <stdlib.h>
//#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

class Mystring 
{
public:
	Mystring();
	Mystring(const char *str);
	Mystring(const Mystring &str);
	~Mystring();

	/*********     �����"="��������ĺ�������    ********/
	Mystring& operator= (const Mystring& str);
	Mystring& operator= (const char* str);
	Mystring& operator= (char c);

	/*********     �����"+="��������ĺ�������    ********/
	Mystring& operator+= (const Mystring& str);
	Mystring& operator+= (const char* str);
	Mystring& operator+= (char c);

	/*********     �����"[]"��������ĺ�������    ********/
	const char& operator[] (unsigned int pos) const;
	char& operator[] (unsigned int pos);

	/*********     ��������<<����������    ********/
	friend ostream& operator<< (ostream& os, Mystring& str);

	/*********     �����" + "��������    ********/
	friend Mystring operator+ (const Mystring& str1, const Mystring& str2);
	friend Mystring operator+ (const char* lhs, const Mystring& rhs);
	friend Mystring operator+ (char lhs, const Mystring& rhs);
	friend Mystring operator+ (const Mystring& lhs, const char* rhs);
	friend Mystring operator+ (const Mystring& lhs, char rhs);

	/*********     �����" == "��������    ********/
	friend bool operator== (const Mystring& lhs, const Mystring& rhs);
	friend bool operator== (const char* lhs, const Mystring& rhs);
	friend bool operator== (const Mystring& lhs, const char* rhs);

	/*********     �����" > "��������    ********/
	friend bool operator> (const Mystring& lhs, const Mystring& rhs);
	friend bool operator> (const char* lhs, const Mystring& rhs);
	friend bool operator> (const Mystring& lhs, const char* rhs);

	void diaplay() const;
private:
	char *m_data;
	unsigned int m_size;
};

Mystring::Mystring()   //�޲ι��캯��
{
	cout << "Mystring::Mystring()" << endl;
	m_data = NULL;
	m_size = 0;
}
Mystring::Mystring(const char *str)   // �вι��캯��
{
	cout << "Mystring::Mystring(const char *str)" << endl;
	m_size = strlen(str);
	m_data = new char[m_size + 1];
	strcpy(m_data, str);
}
Mystring::Mystring(const Mystring &str)  //�������캯��
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

/*********     �����"="��������ĺ�������    ********/
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

/*********     �����"+="��������ĺ�������    ********/
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
	//strcat(m_data, str);   strcat ���������ַ���ȥ
	m_data[m_size - 1] = c;
	m_data[m_size] = '\0';
	delete[]data_cp;

	return *this;
}

/*********     �����"[]"��������ĺ�������    ********/
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

/*********     ��������<<����������    ********/
ostream& operator<< (ostream& os, Mystring& str)
{
	cout << "ostream& operator<< (ostream& os, Mystring& str)" << endl;
	return os << str.m_data;
}

/*********     �����" > "��������    ********/
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
	if(strcmp(lhs.m_data, rhs) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*********     �����" == "��������    ********/
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
	if(strcmp(lhs, rhs.m_data) == 0)
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
	if(strcmp(lhs.m_data, rhs))
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
int main()
{
	Mystring str1;     // �޲εĹ��캯��
	cout << endl;

	/*********    �вεĹ��캯��     ********/
	Mystring str2("Hello");  
	str2.diaplay();
	cout << endl;

	Mystring str3 = str2; 
	str3.diaplay();
	cout << endl;

	/*********    �������=������     ********/
	Mystring str4("12344");  
	str4.diaplay();
	str4 = "asdf";
	str4.diaplay();
	cout << endl;

	Mystring str5("12344");   
	str5.diaplay();
	str5 = 'a';
	str5.diaplay();
	cout << endl;

	Mystring str6;   
	str6 = str2;
	str2.diaplay();
	cout << endl;

	/*********    �������+=������     ********/
	Mystring str7("123456");  
	str7 += "asd";
	str7.diaplay();
	cout << endl;

	Mystring str8("zxc");    
	str8 += str2;
	str8.diaplay();
	cout << endl;

	Mystring str9("123");     
	str9 += 'H';
	str9.diaplay();
	cout << endl;

	/*********    �������[]������     ********/
	Mystring str0("123456");    //  ���޸Ķ����ֵ
	str0.diaplay();
	str0[3] = 'H';
	str0.diaplay();
	cout << endl;
	
	const Mystring str11("123456");    // �����޸Ķ����ֵ  ֻ��
	str11.diaplay();
	//cout << str11[4] << endl;   //���������
	cout << str11.operator[](4) << endl;  //��Ա����
	//str11[4] = 'H';    ��������ó����ã�������ֻ��
	str11.diaplay();
	cout << endl;


	/*********   �������>>������      ********/
	Mystring str12("123456");   
	cout << str12 << " ++++" << endl;
	cout << endl;

	/*********     �����" > "��������    ********/
	bool flag1;
	flag1 = str12 > str11;        //��Ƚϵ��������󣬴���Ϊ1 �� ������Ϊ 0 
	cout << flag1 << endl;
	cout << endl;

	bool flag2;
	flag2 = "1234567" > str11;     //��Ƚϵ���������,����Ϊ1 �� ������Ϊ 0  
	cout << flag2 << endl;
	cout << endl;

	bool flag3;
	flag3 = str12 > "123456";     //��Ƚϵ���������,����Ϊ1 �� ������Ϊ 0 
	cout << flag3 << endl;
	cout << endl;

	/*********     �����" == "��������    ********/
	bool flag4;
	flag4 = str12 == str11;       //��Ƚϵ���������,���Ϊ 1 �� ����Ϊ 0 
	cout << flag4 << endl;
	cout << endl;

	bool flag5;
	flag5 = "12345" == str11;     //��Ƚϵ���������,���Ϊ 1 �� ����Ϊ 0 
	cout << flag5 << endl;
	cout << endl;

	bool flag6;
	flag6 = str12 == "123456";     //��Ƚϵ���������,���Ϊ 1 �� ����Ϊ 0 
	cout << flag6 << endl;
	cout << endl;

	system("pause");
	return 0;

}