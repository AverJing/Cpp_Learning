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

struct Foo {
	Foo() { std::cout << "Foo constructor." << std::endl; }
	~Foo() { std::cout << "Foo destructor." << std::endl; }

	//重载operator new
	//注意必须是static的
	void* operator new(size_t size) {//返回值必须是void*
		std::cout << "Foo new." << std::endl;
		return malloc(size);
	}

	void* operator new(size_t size, size_t extra) {//返回值必须是void*
		std::cout << "Foo new." << std::endl;
		return malloc(size+extra);
	}

	void operator delete(void* ptr) {
		std::cout << "Foo delete." << std::endl;
		free(ptr);
	}

	void* operator new[](size_t size) {//返回值必须是void*
		std::cout << "Foo new[]." << std::endl;
		return malloc(size);
	}
	void operator delete[](void* ptr) {
		std::cout << "Foo delete[]." << std::endl;
		free(ptr);
	}
};

int main(){
	auto p1 = new Foo();
	//先调用类内重载的operator new
	//执行指针类型转化
	//执行类构造
	delete p1;

	auto p2 = new Foo[5];
	delete[] p2;

	auto p3 = new(10)Foo;
	delete p3;
}	