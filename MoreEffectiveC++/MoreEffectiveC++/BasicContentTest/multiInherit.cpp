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

struct Base1 {
	int i;
	virtual ~Base1() {};
	virtual void print() { std::cout << "Base1\n"; }
};

struct Base2 {
	int j;
	virtual ~Base2() {};
	virtual void print() { std::cout << "Base2\n"; }
};

struct Derived:public Base1,public Base2 {
	int i;
	virtual ~Derived() {};
	virtual void print() { std::cout << "Derived\n"; }
	virtual void testprint() { std::cout << "testprint Derived\n"; }
};

int main(){
	Derived d;

	Base2& b = d;
	b.print();

	Base1& a = d;
	a.testprint();
	//可以通过父类型的指针访问子类自己的虚函数

	return 0;
}