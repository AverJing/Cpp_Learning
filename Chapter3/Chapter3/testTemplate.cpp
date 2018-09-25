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
#include <typeinfo>

static int k = 0;

template<typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2) {
	f(std::forward<T2>(t2), t1);
}

void g(int&& i, int& j) {
	std::cout << i << ' ' << j << std::endl;
}

void test(int&& k, int& p) {
	g(k, p);
}

int main(){
	int i = 10;
	flip(g, i, 42);
}	