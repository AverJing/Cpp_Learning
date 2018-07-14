/*
*
*@author£ºAver Jing
*@description£º Given two vectors of ints, write a program to determine
*whether one vector is a prefix of the other. For vectors of unequal
*length, compare the number of elements of the smaller vector. For
*example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
*8, respectively your program should return true.
*@date£ºJuly 13, 2018
*
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vec1{ 0, 1, 1, 2 };
	vector<int> vec2{ 0, 1, 1, 2, 3, 5, 8 };

	auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
	for (decltype(vec1.size()) i = 0; i != size; ++i) {
		if (vec1[i] != vec2[i]) {
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;
	return 0;
}