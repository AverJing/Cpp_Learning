/*
*
*@author£ºAver Jing
*@description£ºWrite a program to initialize a vector from an array of
*ints.
*@date£ºJuly 13, 2018
*
*/

#include<iostream>
#include <vector>

using namespace std;

int main() {
	int a[] = { 1,2,3,4,5,6,7,8 };
	vector<int> ivec(begin(a), end(a));

	return 0;
}