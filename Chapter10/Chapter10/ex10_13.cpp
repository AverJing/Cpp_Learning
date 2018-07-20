/*
*
*@author£ºAver Jing
*@description£ºThe library defines an algorithm named partition that
*takes a predicate and partitions the container so that values for which the
*predicate is true appear in the first part and those for which the predicate is
*false appear in the second part. The algorithm returns an iterator just past
*the last element for which the predicate returned true. Write a function that
*takes a string and returns a bool indicating whether the string has five
*characters or more. Use that function to partition words. Print the elements
*that have five or more characters.
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

bool split(const string &s) {
	return s.size() >= 5;
}

void ex10_13() {
	vector<string> svec{ "hello", "if", "you", "find", "me", "I", "will", "follow" };

	auto pivot = partition(svec.begin(), svec.end(), split);

	for (auto it = svec.begin(); it != pivot; ++it)
		cout << *it << ' ';
	cout << endl;
}
int main() {
	ex10_13();

	return 0;
}