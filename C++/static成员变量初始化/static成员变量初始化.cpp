为什么static成员一定要在类外初始化? 

 这是因为被static声明的类静态数据成员，其实体远在main()函数开始之前就已经在全局数据段中诞生了(见《Inside   The   C++   Object   Model》page247)！
 其生命期和类对象是异步的，（而且静态语意说明即使没有类实体的存在,其静态数据成员的实体也是存的）这个时候对象的生命期还没有开始，
 如果你要到类中去初始化类静态数据成员,让静态数据成员的初始化依赖于类的实体,，那怎么满足前述静态语意呢?
 难道类永远不被实例化，我们就永远不能访问到被初始化的静态数据成员吗? 

所以我的朋友,为了满足C++的static语意,static成员一定要在类外初始化!
class A
{
public:
	const static int a = 0;
	static int b;
	const int c = 0;
};
int A::b = 1;

int main()
{
	A::a;
}
详见：https://www.cnblogs.com/dongsheng/p/3327498.html