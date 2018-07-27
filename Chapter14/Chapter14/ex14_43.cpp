/*
*
*@author£ºAver Jing
*@description£º
* Using library function objects, determine whether a given int value is divisible by
*any element in a container of ints.
*@date£ºJune 20, 2018
*
*/

#include<iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	auto data = { 2, 3, 4, 5 };
	int input;
	std::cin >> input;
	std::modulus<int> mod;
	auto predicator = [&](int i) { return 0 == mod(input, i); };
	//auto is_divisible = std::any_of(data.begin(), data.end(), predicator);
	auto is_divisible = std::all_of(data.begin(), data.end(), predicator);
	std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;

	return 0;
}