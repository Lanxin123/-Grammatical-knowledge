#include "stdafx.h"
#include <iostream>

using namespace std;

typedef void(*Fun)(void);

class Base {
public:
	virtual void f() {
		cout << "Base::f" << endl;
	}
	virtual void g() {
		cout << "Base::g" << endl;
	}
	virtual void h() {
		cout << "Base::h" << endl;
	}
};
class Derive : public Base {
public:
	virtual void f() {
		cout << "Derive::f" << endl;
	}
	virtual void g() {
		cout << "Derive::g" << endl;
	}
	virtual void h() {
		cout << "Derive::h" << endl;
	}
	void g2()	{
		cout << "Derive::g2" << endl;
	}
};

int main()
{
	Derive b;
	Fun pFun = NULL;
	int a = 6;
	cout << (int*)*(int*)&a << endl;;
	cout << "类的地址" << &b << endl;
	cout << "虚函数表地址: " << (int*)(&b) << endl;
	cout << "虚函数表第一个函数地址" << (int*)*(int*)(&b) << endl;
	pFun = (Fun)*((int*)*(int*)(&b)+2);
	pFun();
}


