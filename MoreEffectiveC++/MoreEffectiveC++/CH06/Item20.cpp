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

//测试编译器对直接返回构造的临时对象的优化

class Test {
public:
	//version 1.0	
	friend inline const Test operator+(const Test& lhs, const Test& rhs) {
		return Test(lhs.num + rhs.num);
	}
	//version 2.0
	/*
	friend inline const Test operator+(const Test& lhs, const Test& rhs) {
		auto tmp = Test(lhs.num + rhs.num);
		return tmp;
	}*/

	Test() { std::cout << "hello" << std::endl; }
	Test(int x):num(x) { std::cout << "hello, Test(int x)" << std::endl; }
	Test(const Test& t) :num(t.num) { std::cout << "hello, Test(const Test& t)" << std::endl; }
private:
	int num;
};

const Test operator+(int lhs, const Test& rhs);

//C++ 规定每一个重载的operator必须带有一个用户定义类型的参数
//const Test operator+(int lhs, int rhs);


int main(){
	Test t1(10),t2(20);
	auto t3 = t1 + t2;
	/*
	注意两者的差别，verson1.0 更好有编译器优化，编译器会消除operator+临时变量，它们
	能在目标t3分配的内存中直接构造return定义的表达式
	*/
}	