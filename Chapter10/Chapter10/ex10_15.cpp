/*
*
*@author£ºAver Jing
*@description£ºWrite a lambda that captures an int from its enclosing
function and takes an int parameter. The lambda should return the sum of
the captured int and the int parameter.
*@date£ºJuly 20, 2018
*
*/

#include<iostream>

using namespace std;

void ex10_15(int i) {
	auto add = [i](int v) {return i + v; };
	cout << add(10) << endl;
}

int main() {
	ex10_15(5);

	return 0;
}