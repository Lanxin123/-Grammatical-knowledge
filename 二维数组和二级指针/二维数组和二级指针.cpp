int main()
{
	int a[2][3] = { 1,2,3,4,5,6 };//2行3列的int型数组
	//数组可以转换为指针，但这是一维的关系
	//一级指针的含义就是取一次地址
	//而二级指针的意思是取两次地址
	//这有本质区别
	//所以二维数组其实相当于指针数组
	//即指针指向的数组，指针为行数组为列
	//所以数组的定义必须有列
	//一级指针可以存取二维数组
	//二级指针是指向指针的指针，是指针指针
	int(*p)[3] = a;
	for (int i=0;i<2;i++)
	{
		for (int j =0;j<3;j++)
		{
			cout << p[i][j];
		}
	}
}

int main()
{
	char *str[2] = { "hello","world" };
	char **pp;
	pp = str;

	cout << pp << endl;
	cout << *++pp << endl;//解引用一次仅知道是hello还是world
	cout << *++*pp << endl;//第二次时才能当成字符 然后在第一次的指针下进行改动
}


详见：https://blog.csdn.net/yongheng_1999/article/details/52765130