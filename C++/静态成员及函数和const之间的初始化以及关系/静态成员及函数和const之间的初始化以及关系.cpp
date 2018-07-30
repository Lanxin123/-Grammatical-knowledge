静态成员函数不能用const修饰 ，也不能存取nonstatic数据
class AAA
{
public:
	AAA(){};
	AAA(int x):a(x){};//构造参数列表
					 //在以下情况必须使用
					 //1. 类成员为const类型
					 //2. 类成员为引用类型
					 //3. 类成员为没有默认构造函数的类类型
					 //4. 如果类存在继承关系，派生类必须在其初始化列表中调用基类的构造函数
					 //详见：https://www.cnblogs.com/dobben/p/7501106.html
					 //以及C++文件夹下的构造函数初始化列表
	static void display(void) const
	{
		printf("m_a1 value is %d\n", m_a1);
		// 没有const,运行OK.
		// 有了const,报以下错.
		// error C2272: 'display' : modifiers not allowed on static member functions
 
		//static成员函数没有this指针 不属于类内
		this->m_a1;//这是错的，static函数根本没有this指针 
		//因为我们在定义一个类对象的时候，实际上只给该对象的非静态的数据成员分配内存空间（假设没有虚函数），
		//而该类的静态成员数据以及该类的函数都在编译的时候分配到一个公共的空间里，所有，在定义一个对象并调用类对象的函数的时候，
		//函数根本不知道到底是哪个对象调用了他，怎么解决这个问题呢？ 
		//C++利用传递this指针的方式来实现，调用一个类对象里的函数的时候，将把这个对象的指针传递给他，
		//以便函数对该对象的数据进行操作，对于一个定义为const的函数，传递的是const的this指针，说明不能更改对象的属性，
		//而对 static成员的函数不需传递this指针，所有就不需要用const来修饰static的成员函数了！ 
		//就是说const属性的作用就是对被传递的this指针加以限定，而对static成员函数的调用根本不传递this指针，所有不需const来修饰static的成员函数。 
		//从对象模型上来说，类的非static成员函数在编译的时候都会扩展加上一个this参数，const的成员函数被要求不能修改this所指向的这个对象；
		//而static函数编译的时候并不扩充加上this参数，自然无所谓const。 
	}
 	
 	const int b = 0;		//可以直接初始化
 							//或者通过构造函数初始化列表初始化
 							//可同时，且初始化列表会覆盖掉b的值
	static int m_a1;
	const static int a;		//const static可以在类内初始化(类型不可为string float double)也可以在类外初始化 
						    //但是无法使用构造函数初始化列表初始化
						    //不可同时 同时会出现重定义
};
 
int AAA::m_a1 = 100;
const int AAA::a = 100;
 //为什么static成员一定要在类外初始化? 

 //这是因为被static声明的类静态数据成员，其实体远在main()函数开始之前就已经在全局数据段中诞生了(见《Inside   The   C++   Object   Model》page247)！
 //其生命期和类对象是异步的，（而且静态语意说明即使没有类实体的存在,其静态数据成员的实体也是存的）这个时候对象的生命期还没有开始，
 //如果你要到类中去初始化类静态数据成员,让静态数据成员的初始化依赖于类的实体,，那怎么满足前述静态语意呢?
 //难道类永远不被实例化，我们就永远不能访问到被初始化的静态数据成员吗? 

//所以我的朋友,为了满足C++的static语意,static成员一定要在类外初始化!

int _tmain(int argc, _TCHAR* argv[])
{
	AAA::display();
 
	return 0;
}
详见：https://blog.csdn.net/yusiguyuan/article/details/38369181