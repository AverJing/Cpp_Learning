/*
*
*@author£ºAver Jing
*@description£ºWrite a lambda that takes two ints and returns their sum.
*@date£ºJuly 20, 2018
*
*/

#include <iostream>
#include "base_tool.h"

using namespace std;

void ex10_14() {
	auto add = [](int lhs, int rhs) {return lhs + rhs; };
	cout << add(10, 5) << endl;
}

int main() {
	ex10_14();
	return 0;
}