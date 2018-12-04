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
#include <algorithm>

int getMax() {
	return std::max({ 3,2,5,7,1,8,4 });
}

int Max(int n) {
	return n;
}

template<typename... T>
int Max(int n, T... Args) {
	return std::max(n, Max(Args...));
}

int main(){
	std::cout << Max(3, 2, 1, 7, 9, 10, -5);
}	