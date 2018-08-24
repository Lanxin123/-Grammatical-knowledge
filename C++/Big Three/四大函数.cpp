#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

class A
{
public:
	A(int a, int b, char *name) : x(a), y(b)
	{
		cout << "构造函数" << endl;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	};
	~A()
	{
		cout << "析构函数" << endl;
		if (name != NULL)
		{
			delete[] name;
			name = nullptr;
			x = 0;
			y = 0;
		}
	}
	A(const A &other)
	{
		cout << "拷贝构造函数" << endl;
		this->x = other.x;
		this->y = other.y;
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name)+1,other.name);
	}
	
	A &operator = (const A &other)
	{
		cout << "复制函数" << endl;
		if (&other!=this)
		{
			delete[] name;
			name = new char(strlen(other.name) + 1);
			this->x = other.x;
			this->y = other.y;
		}
		return *this;
	}

private:
	int x, y;
	char* name;
};



int main()
{
	char*p = "1,2,3";
	A a(1, 2, p);
	A c(1, 2, p);
	A b = a;
	b = c;
}



