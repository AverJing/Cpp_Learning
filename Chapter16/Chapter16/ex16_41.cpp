/*
*
*@author��Aver Jing
*@description��
*@date��
*
*/

#include <iostream>
#include <vector>
#include <string>

template<typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs)
{
	return lhs + rhs;
}

int main()
{
	auto s = sum(123456789123456789123456789123456789123456789, 123456789123456789123456789123456789123456789);
	return 0;
}