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
#include <vector>

struct StaticClass {
	static int a;
	int b;

	StaticClass(int x = 0) :b(x) { a = b; }

	static void print() {
		std::cout << a  << std::endl;
	}
};

int StaticClass::a = 10;

int main(){
	StaticClass s;
	s.print();
	std::vector
	return 0;
}