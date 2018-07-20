/*
*
*@author£ºAver Jing
*@description£ºUse accumulate function to sum these emelents in a vector<int>. 
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include <vector>
#include <numeric>

using namespace std;

void ex10_3() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };

	int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);

	cout << "The sum of elements in vector<int> is " << sum << endl;
}

int main() {
	ex10_3();

	return 0;
}