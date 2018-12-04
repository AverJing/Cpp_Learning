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
#include <queue>

void test() {
	int id = 0;
	//auto f = [id]() mutable {std::cout << id << ' '; ++id; };
	auto f = [&id]() mutable {std::cout << id << ' '; ++id; };
	id = 42;
	f();
	f();
	std::cout << id << ' ';
}


int main(){
	test();

	auto cmp = [](int a, int b) {return a < b; };
	std::priority_queue<int, std::vector<int>, decltype(cmp)> s(cmp);
	std::priority_queue<int, std::vector<int>, std::greater<int>> s2;
}	