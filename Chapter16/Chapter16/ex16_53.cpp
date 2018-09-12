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
#include <string>

using std::string;

template<typename T>
std::ostream &print(std::ostream &os, const T& t) {
	return os << t;
}

template<typename T, typename ... Args>
std::ostream &print(std::ostream &os, const T& t, const Args& ... rest) {
	os << t << ',';
	return print(os, rest...);
}

int main(){
	print(std::cout, 15, 42.5, "hello");
}	