/*
*
*@author£ºAver Jing
*@description£º Use stream iterators, sort, and copy to read a sequence
*of integers from the standard input, sort them, and then write them back to
*the standard output
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <iterator>
#include "base_tool.h"

using namespace std;

void ex10_30() {
	istream_iterator<int> int_it(cin), eof;
	vector<int> ivec;
	//copy(int_it, eof, back_inserter(ivec));
	while (int_it != eof) ivec.push_back(*int_it++);
	sort(ivec.begin(), ivec.end());
	copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
}

int main() {

	return 0;
}