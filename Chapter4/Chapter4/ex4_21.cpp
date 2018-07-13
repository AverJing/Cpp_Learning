/*
*
*@author£ºAver Jing
*@description£º Write a program to use a conditional operator to find the
*elements in a vector<int> that have odd value and double the value of
*each such element.
*@date£ºJuly 13, 2018
*
*/

#include<iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	for (auto &e : ivec) {
		e % 2 ? e *= 2 : e;
	}
	for (auto &e : ivec) {
		cout << e << ' ';
	}
	return 0;
}