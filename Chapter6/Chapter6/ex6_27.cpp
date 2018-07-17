/*
*
*@author£ºAver Jing
*@description£ºWrite a function that takes an initializer_list<int>
*and produces the sum of the elements in the list.
*@date£ºJuly 16, 2018
*
*/

#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> il)
{
	int sum = 0;
	for (auto i : il) sum += i;
	return sum;
}

int main(void)
{
	std::cout << sum({ 1, 2, 3, 4, 5 }) << std::endl;
	return 0;
}