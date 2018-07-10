/*
*
*@author£ºAver Jing
*@description£º Our program used the addition operator, +, to add two
*numbers. Write a program that uses the multiplication operator, *, to print
*the product instead.
*@date£ºJuly 10, 2018
*
*/

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	cout << "Enter two numbers: " << endl;
	int v1 = 0, v2 = 0;	//It's better to initialize them.
	cin >> v1 >> v2;

	cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << endl;

	return 0;
}