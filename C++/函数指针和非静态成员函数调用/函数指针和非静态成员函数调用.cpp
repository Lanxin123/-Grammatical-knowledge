#include "stdafx.h"
#include<iostream>
using namespace std;

class A
{
public:
	//静态成员函数
	static void function(int i)
	{
		cout << ++i << endl;
	}
	//非静态成员函数
	void fun(int i)
	{
		cout << --i << endl;
	}
};
//普通函数
void Fun(int i)
{
	cout << i << endl;
}

//非静态成员函数
typedef void (A::*FuncPointer)(int i);
//静态成员函数
typedef void(*FuncP)(int i);

int main()
{
	FuncP f = A::function;
	FuncPointer ff = &A::fun;
	FuncP fff = Fun;
	A a;
	//静态成员函数指针
	f(7);
	//非静态成员函数指针
	(a.*ff)(7);
	//普通函数指针
	fff(7);
	return 0;
}