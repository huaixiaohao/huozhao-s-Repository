#include <iostream>
#include <cstring>

using namespace std;

class Node
{
public:
	Node(string name, int age, string sclass);
	string getName();
	int getAge();
	string getClass();
	Node *next;

private:
	string n_name;
	int n_age;
	string n_class;
	int gread;
};

/*¹¹Ôìº¯Êý*/
Node::Node(string name = "wu", int age = 0, string class_ = "NT")
{
	n_name = name;
	n_age = age;
	n_class = class_;
	next = NULL;
}

string Node::getName()
{
	
	return n_name;
}

int Node::getAge()
{
	return n_age;
}

string Node::getClass()
{
	return n_class;
}
