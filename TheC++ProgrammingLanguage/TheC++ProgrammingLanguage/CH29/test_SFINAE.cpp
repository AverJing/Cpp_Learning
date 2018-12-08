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

//SFINAE
template <typename T> constexpr bool F(int T::*) { return true; }
template <typename T> constexpr bool F(...) { return false; }

template <typename T> constexpr bool IsClass = F<T>(0);


int main(){
	std::cout << IsClass<int>;
}	