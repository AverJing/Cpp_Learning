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

//注意constexpr函数可以接受非常量实参
constexpr int sum(int a, int b) {
	return a + b;
}

int main(){
	int a = 3;
	int b = 5;
	std::cout << sum(1, 2) << ' ' << sum(a, b);
}	