#include "stdafx.h"
#include <iostream>

using namespace std;

typedef void(*Fun)(void);

class Base {
private:
	virtual void f() { cout << "Base::f" << endl; }
};

class Derive : public Base {

};


int main()
{
	Derive d;

	Fun pFun = (Fun)*((int*)*(int*)(&d)+0);
	pFun();
}
