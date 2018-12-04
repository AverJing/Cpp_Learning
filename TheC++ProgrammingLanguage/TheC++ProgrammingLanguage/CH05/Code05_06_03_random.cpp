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
#include <random>
#include <functional>
#include <chrono>

void test() {
	auto die = std::bind(std::uniform_int_distribution<int>{1, 10}, std::default_random_engine(clock()));
	std::cout << die() << ' ' << die();
}

int main(){
	test();
}	