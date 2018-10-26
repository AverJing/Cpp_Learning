/*
*
*@author£ºAver Jing
*@description£ºUse accumulate function to sum these emelents in a vector<int>. 
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void ex10_3() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };

	int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);

	cout << "The sum of elements in vector<int> is " << sum << endl;
}

template<typename T, typename Iter>
void ex10_3(Iter begin, Iter end) {

	T sum = accumulate(begin, end, T());

	cout << "The sum of elements is " << sum << endl;
}

int main() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	vector<string> s{ "hello", " ", "world", "!" };
	ex10_3<int>(ivec.cbegin(), ivec.cend());
	ex10_3<string>(s.cbegin(), s.cend());

	return 0;
}