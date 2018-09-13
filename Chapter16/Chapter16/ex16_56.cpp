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
#include "ex16_48.h"

using std::string;

//ex16_53  
template<typename T>
std::ostream &print(std::ostream &os, const T& t) {
	return os << t;
}

template<typename T, typename ... Args>
std::ostream &print(std::ostream &os, const T& t, const Args& ... rest) {
	os << t << ',';
	return print(os, rest...);
}

template<typename ... Args>
std::ostream & errMsg(std::ostream& os, const Args& ... rest) {
	return print(os, debug_rep(rest)...);
}

int main(){
	string s = { "word" };
	errMsg(std::cout, "hello", s, &s);
}	