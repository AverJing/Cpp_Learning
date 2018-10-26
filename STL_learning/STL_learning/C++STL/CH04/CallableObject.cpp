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
#include <functional>
#include <memory>
#include <vector>
#include <future>

void func(int x, int y) {
	std::cout << x << ' ' << y << std::endl;
}

auto l = [](int x, int y) {std::cout << x << ' ' << y << std::endl; };

class C {
public:
	void operator()(int x, int y) {
		std::cout << x << ' ' << y << std::endl;
	}
	void member(int x, int y) { std::cout << x << ' ' << y << std::endl; }
};

int main(){
	C c;
	std::shared_ptr<C> sp(new C);

	std::vector<std::function<void(int, int)>> s;
	s.push_back(func); s.push_back(l); s.push_back(C()); //s.push_back(&C::member);
	for (auto &e : s) {
		e(70, 33);
	}

	std::bind(func, 77, 33)();
	std::bind(l, 77, 33)();
	std::bind(C(), 77, 33)();	//call C::operator()
	//must have object
	std::bind(&C::member, c, 77, 33)();    //call c.member
	std::bind(&C::member, sp, 77, 33)();	 //call sp->member

	std::async(func, 77, 33);
	std::async(l, 77, 33);
	std::async(C(), 77, 33);
	std::async(&C::member, &c, 77, 33); //or std::async(&C::member, &c, 77, 33);
	std::async(&C::member, sp, 77, 33);

}