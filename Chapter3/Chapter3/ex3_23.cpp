/*
*
*@author£ºAver Jing
*@description£º Write a program to create a vector with ten int elements.
*Using an iterator, assign each element a value that is twice its current value.
*Test your program by printing the vector.
*@date£ºJuly 12, 2018
*
*/

#include<iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
	int i;
	for (auto &e : ivec) {
		e *= 2;
	}
	for (auto &e : ivec) {
		cout << e << ' ';
	}

	return 0;
}