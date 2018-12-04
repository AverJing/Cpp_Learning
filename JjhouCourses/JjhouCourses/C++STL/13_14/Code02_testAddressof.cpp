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
#include <memory>

// Rvalue overload is deleted to prevent taking the address of const rvalues.
template<class T>
void print(T t) {
	std::cout << std::addressof(t) << ' ' << &t ;
}

int main(){
	int t = 10;
	print(t);
}	