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
#include <chrono>

using namespace std::chrono;

int main(){
	auto t1 = high_resolution_clock::now();
	std::cout << "hello\n";
	auto t2 = high_resolution_clock::now();
	std::cout << duration_cast<nanoseconds>(t2 - t1).count() << "nanosec\n";
}	