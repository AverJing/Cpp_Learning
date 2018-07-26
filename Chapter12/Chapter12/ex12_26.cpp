/*
*
*@author£ºAver Jing
*@description£º Rewrite the program on page 481 using an allocator.
*@date£ºJuly 26, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex12_26(const int n) {
	allocator<string> alloc;
	auto p = alloc.allocate(n);
	auto q = p;
	string s;
	while (cin >> s && p != p + n)
		alloc.construct(p++, s);

	while (q != p) {
		cout << *--p << ' ';
		alloc.destroy(p);
	}

	alloc.deallocate(p, n);
}

int main() {

	return 0;
}