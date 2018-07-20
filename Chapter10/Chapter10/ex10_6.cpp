/*
*
*@author£ºAver Jing
*@description£ºUsing fill_n, write a program to set a sequence of int
*values to 0
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include <algorithm>

using namespace std;

void ex10_6() {
	int a[] = { 1,2,3,4,5,6,7 };
	fill_n(begin(a), sizeof(a) / sizeof(*a), 6);
	for (auto &e : a)
		cout << e << ' ';
	cout << endl;
}

int main() {
	ex10_6();

	return 0;
}