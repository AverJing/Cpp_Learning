/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include<iostream>
#include<functional>


class A {
public:
	A() {}
	A(const A&) = delete;
	A& operator=(const A&) = delete;
	A(A&&) { std::cout << "A&&" << std::endl; }
};
void f(A &&a) {}

int main() {
	A a;
	//auto g = [&a]()mutable->void {f(std::move(a)); };

	auto g = [b{std::move(a)}]()mutable->void {f(std::move(b)); };
	//只是通过移动构造新建了一个左值对象
}
