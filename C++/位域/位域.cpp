#include "stdafx.h"
#include <iostream>
struct S {
	// 三位无符号位域，
	// 允许值为 0...7
	unsigned int b : 3;.
	//int b:3; 可拥有值范围 0..7 或 -4..3 。
	unsigned int a = 0;
};
int main()
{
	S s = { 7,1};//列表初始化
	++s.b; // 无符号上溢（保证回卷）
	std::cout << s.b << '\n'; // 输出： 0
	std::cout << s.a << "\n";//输出：1
}
详见 https://zh.cppreference.com/w/cpp/language/bit_field
https://msdn.microsoft.com/zh-cn/library/ewwyfdbe.aspx