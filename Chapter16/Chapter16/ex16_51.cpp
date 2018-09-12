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

template<typename T, typename ... Args>
inline void foo(const T&t, const Args& ... rest) {
	std::cout << sizeof...(Args) << ' ';
	std::cout << sizeof...(rest) << std::endl;
}


int main(){
	int i = 0; double d = 3.14; string s = "how now brown cow";
	foo(i, s, 42, d); // three parameters in the pack
	foo(s, 42, "hi"); // two parameters in the pack
	foo(d, s); // one parameter in the pack
	foo("hi"); // empty pack
}	