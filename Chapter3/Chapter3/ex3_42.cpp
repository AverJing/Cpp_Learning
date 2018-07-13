/*
*
*@author£ºAver Jing
*@description£ºWrite a program to copy a vector of ints into an array of
*ints.
*@date£ºJuly 13, 2018
*
*/

#include<iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	auto a = new int[ivec.size()];
	for (decltype(ivec.size()) i = 0; i != ivec.size(); ++i)
		a[i] = ivec[i];

	return 0;
}