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

class Vector {
public:
	Vector(size_t s) :next(new double[s]), size(s) {}
	//Vector(size_t s) :next{ new double[size] }, size{ s } {}
	//尽管下边的没报错，但是有问题的。next行为未定义
	double& operator[](size_t index) { return next[index]; }
	~Vector() { delete[] next; }
private:
	double* next;
	size_t size;
};

struct Test {
	//注意C++构造函数内部参数初始化顺序是按照声明顺序初始化的
	//存在问题，如果拿成员中变量初始化另一个变量，
	//注意a的值 未定义
	//最好，令构造函数初始化值的顺序和定义顺序一样。如果可能，尽量避免用某些成员初始化另一个成员
	int a;
	int b;
	int c;
	Test(int x1) :b(x1), a(b), c(a) {}
};

int main(){
	//Vector s(10);

	Test t(10);
	std::cout << t.a << ' ' << t.b;
}	