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
//习题13
void f(const int x) {
	std::cout << x << "\n";
}
//没感觉什么副作用
//估计常量非引用参数，除了基本类型可以用
//其他都可以用常量引用参数代替，不用拷贝
int main(){
	f(10);
	int x = 10;
	const int y = 20;
	f(x);
	f(y);
}	