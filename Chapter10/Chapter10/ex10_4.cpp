/*
*
*@author£ºAver Jing
*@description£ºAssuming v is a vector<double>, what, if anything, is
*wrong with calling accumulate(v.cbegin(), v.cend(), 0)?
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include <vector>
#include <numeric>

using namespace std;

void ex10_4() {
	vector<double> ivec{ 1.1,2.2,3.3 };

	double sum = accumulate(ivec.cbegin(), ivec.cend(), 0);

	cout << "The sum of elements in vector<double> is " << sum << endl;

	//The output is 6 rather than 6.6 as expected
	//The reason is std::accumulate is a template function. The third
	//parameter is _Ty
	//When "0", an integer, had ben specified here, the compiler deduced _Ty as integer
}

int main() {

	return 0;
}