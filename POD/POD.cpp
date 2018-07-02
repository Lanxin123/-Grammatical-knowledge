POD是Plain old data的缩写，它是一个struct或者类，且不包含构造函数、析构函数以及虚函数。

维基百科给出了更加详细的解释：

C++的POD类型或者是一个标量值，或者是一个POD类型的类。
POD class没有用户定义的析构函数、拷贝构造函数和非静态的非POD类型的数据成员。
而且，POD class必须是一个aggregate，没有用户定义的构造函数，没有私有的或者保护的非静态数据，
没有基类或虚函数。它只是一些字段值的集合，没有使用任何封装以及多态特性。