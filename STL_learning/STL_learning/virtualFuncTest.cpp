/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>
//https://blog.csdn.net/m0_37264397/article/details/76697237

/*
这里我们可以区分类和对象：
是编译期的概念，也是“访问权限”、“成员数据”、“成员函数”这几个概念的“作用域”。
而对象的作用域是运行期。它包括类的实例、引用和指针。  

---------------------

本文来自 痴情一笑恋红颜 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/m0_37264397/article/details/76697237?utm_source=copy
*/

class A {
public:
	virtual void f() { std::cout << "A" << std::endl; }
};

class B : public A {
private:
	void f() { std::cout << "B" << std::endl; }
};

int main(){
	A* pa = new B();
	pa->f();

	delete pa;
}	