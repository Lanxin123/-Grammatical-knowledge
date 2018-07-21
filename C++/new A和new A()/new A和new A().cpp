调用new分配的内存有时候会被初始化，而有时候不会，
这依赖于A的类型是否是POD（Plain old data）类型，
或者它是否是包含POD成员、使用编译器生成默认构造函数的类。

详见https://blog.csdn.net/xiajun07061225/article/details/8796257