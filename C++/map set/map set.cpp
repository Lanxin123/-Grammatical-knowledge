map和set结构上都是由红黑树构成的
map内元素为key-value set内元素为key
map和set内的元素（key）都是由小到大排好的
int main()
{
	map<int, string> mapStudent;

	mapStudent.insert(pair<int, string>(1, "student_one"));

	mapStudent.insert(pair<int, string>(3, "student_two"));

	mapStudent.insert(pair<int, string>(2, "student_three"));

	map<int, string>::iterator iter;

	for (iter = mapStudent.begin();iter!=mapStudent.end();++iter)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}

}

pair和set结合
以pair->first进行排序
#include "stdafx.h"
#include <string>  
#include<iostream>
#include <set>
#include <utility>
using namespace std;

int main()
{
	pair<int, string> p;
	

	set<pair<int, string>> ps;

	ps.insert(make_pair(1, "1"));
	ps.insert(make_pair(3, "3"));
	ps.insert(make_pair(2, "2"));


	for (auto it = ps.cbegin();it!=ps.cend();++it)
	{
		cout << it->first << " " << it->second<<endl;
	}
}
//OutPut  
//1 1
//2 2
//33
详见：https://blog.csdn.net/xy913741894/article/details/55252743