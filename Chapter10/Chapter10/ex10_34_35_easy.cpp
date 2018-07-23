/*
*
*@author£ºAver Jing
*@description£º Use reverse_iterators to print a vector in reverse
*order.
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex10_34() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	for (auto r_iter = ivec.crbegin(); r_iter != ivec.crend(); ++r_iter)
		cout << *r_iter << ' ';
	cout << endl;
}

void ex10_35() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	for (auto it = ivec.end(); it != ivec.begin();) {
		cout << *--it << ' ';
	}
	cout << endl;
}

int main() {
	ex10_34();

	return 0;
}