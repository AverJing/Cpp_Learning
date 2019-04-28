/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <cstring>

struct Test
{
	Test() {
		std::cout << "Base\n";
	}
	~Test() {
		std::cout << "Base de\n";
	}
	void hello(int a) {
		std::cout << a << " Test\n";
	}
	//int a;
	//char c;
};

struct Derived : Test
{
	Derived() {
		std::cout << "Derived con\n";
	}
	void hello(int a) {
		std::cout << a << " Derived\n";
	}
	~Derived() {
		std::cout << "Derived de\n";
	}
};

struct Test3 {
	int a;
	char c;
	int b;
	int d;
	char e;
	char f;
};

struct BaseVitual {
	virtual ~BaseVitual() {}
	virtual void fun(){}
	virtual void fun2() {}
};

struct DerivedVitual : BaseVitual {
};

//注意要想对该指针进行修改，要用二级指针
void func(char** p) {
	*p = (char*)malloc(10);
}

int main(){
	/*std::cout << sizeof(Test) << std::endl;
	Derived d;
	d.hello(10);*/
	//std::cout << sizeof(Test3) << std::endl;
	std::cout << sizeof(DerivedVitual) << std::endl;
	std::cout << sizeof(BaseVitual) << std::endl;

	char* p = nullptr;
	func(&p);
	strcpy(p, "hello");
	std::cout << p << std::endl;
	
	return 0;
}