/*
*
*@author��Aver Jing
*@description�� Write an expression that tests four values, a, b, c, and d,
*and ensures that a is greater than b, which is greater than c, which is
*greater than d.
*@date��July 13, 2018
*
*/

#include<iostream>

using namespace std;

int main() {
	int a, b, c, d;
	if (a > b&& b > c &&c > d)
		cout << a << b << c << d;

	return 0;
}