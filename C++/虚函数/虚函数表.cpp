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
/*
&操作符，获取地址
*操作符，获取指针指向的数据。
（类型名称）这样就是显示的类型转换。
(&b)
首先是&b获取b的地址
(int*)(&b)
将b的地址强制转换成int型指针
*(int*)(&b)
获取该int型指针指向的数据
(int*)*(int*)(&b)
将指向的数据转化成int型指针
可能你感觉这样，纯属胡折腾。
因为*&b这样就相当于b，但是如果知道b占用的空间远大于int就好理解了。
b应该是虚函数表，就是编译器对虚函数的一种实现。每个虚函数的地址占用四个字节。
换句话说，你把b右移4位，在进行上面的操作，就是第二个虚函数的地址了。
*/
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

https://blog.csdn.net/gggg_ggg/article/details/45915505
