//构造参数列表
//在以下情况必须使用
//1. 类成员为const类型
//2. 类成员为引用类型
#include <iostream>
using namespace std;

class A
{
    public:
        A(int &v) : i(v), p(v), j(v) {}
        void print_val() { cout << "hello:" << i << "  " << j << endl;}
    private:
        const int i;
        int p;
        int &j;
};

int main(int argc ,char **argv)
{
    int pp = 45;
    A b(pp);
    b.print_val();
}
//3. 类成员为没有默认构造函数的类类型
#include <iostream>
using namespace std;

class Base
{
    public:
        Base(int a) : val(a) {}
    private:
        int val;
};

class A
{
    public:
        A(int v) : p(v), b(v) {}
        void print_val() { cout << "hello:" << p << endl;}
    private:
        int p;
        Base b;
};

int main(int argc ,char **argv)
{
    int pp = 45;
    A b(pp);
    b.print_val();
}
//4. 如果类存在继承关系，派生类必须在其初始化列表中调用基类的构造函数
#include <iostream>
using namespace std;

class Base
{
    public:
        Base(int a) : val(a) {}
    private:
        int val;
};

class A : public Base
{
    public:
        A(int v) : p(v), Base(v) {}
        void print_val() { cout << "hello:" << p << endl;}
    private:
        int p;
};

int main(int argc ,char **argv)
{
    int pp = 45;
    A b(pp);
    b.print_val();
}
//详见：https://www.cnblogs.com/dobben/p/7501106.html
//详见：https://blog.csdn.net/qq_30366449/article/details/75274856
