/*
*
*@author£ºAver Jing
*@description£ºuse count function(in algorithm header) to print the count of 
*how many elements have a given value in vector<int>
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using std::string;
using std::vector;
using std::list;
using std::cout;
using std::endl;

/*
void ex10_1(vector<int> &ivec, int number) {
	cout << " The number of " << number << " occurs " << 
		count(ivec.cbegin(), ivec.cend(), number) << " time(s). " << endl;
}*/

template<typename Iter, typename T>
void ex10_1(Iter begin, Iter end, const T& t) {
	cout << " The element of " << t << " occur(s) " <<
		count(begin, end, t) << " time(s). " << endl;
}

int main() {
	vector<int> ivec{ 1,1,1,1,1,1,5,5,5,7,7,7,7,8 };
	list<string> slst{ "hi", "hi", "hello", "hi", "height" };

	ex10_1(ivec.begin(), ivec.end(), 1);
	ex10_1(slst.begin(), slst.end(), "hi");
	return 0;
}