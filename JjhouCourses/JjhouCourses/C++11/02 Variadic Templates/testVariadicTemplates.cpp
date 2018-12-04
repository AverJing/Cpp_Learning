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
#include <bitset>

void print() {

}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
	std::cout << firstArg << std::endl;
	print(args...);
}

template<typename... Types>
void print(const Types&... args) {
	/**/
}
//体会两者的差别

// sizeof...(args);
int main(){
	print(7.5, "hello", std::bitset<12>(377), 42);
}	