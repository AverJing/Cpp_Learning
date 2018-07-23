/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>
#include <functional>
#include "base_tool.h"


//Rewrite the program to count words of size 6 or less using functions in place of the lambdas.
bool splitBysz(const string& s, string::size_type sz) {
	return s.size() < sz;
}
void ex10_22() {
	vector<string> v{ "Never", "let", "your", "fear","decide", "your", "fate", "AverJing" };
	cout << count_if(v.begin(), v.end(), bind(splitBysz, placeholders::_1, 6))
		<< endl;
}

int main() {

	return 0;
}