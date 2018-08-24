#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	std::vector<int> v{ 1,2,3 };
	struct Local {
		bool operator()(int n, int m) {
			return n > m;
		}
	};
	std::sort(v.begin(), v.end(), Local()); // C++11 起 局部类
	//等价于std::sort(v.begin(), v.end(), [](int n, int m) {return n > m; });
	for (int n : v) std::cout << n << ' ';
}

https://zh.cppreference.com/w/cpp/language/class
