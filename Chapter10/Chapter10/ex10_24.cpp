/*
*
*@author£ºAver Jing
*@description£º Use bind and check_size to find the first element in a
*vector of ints that has a value greater than the length of a specified
*string value
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <functional>
#include "base_tool.h"

using namespace std;

bool splitBysz(const string& s, string::size_type sz) {
	return s.size() < sz;
}
void ex10_24() {
	vector<int> v{ 1,2,3,4,5 };
	string s = "test";
	cout << *find_if(v.cbegin(), v.cend(), bind(splitBysz, s, placeholders::_1)) << endl;
}


int main() {
	ex10_24();

	return 0;
}