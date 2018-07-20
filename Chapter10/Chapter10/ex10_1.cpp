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
#include <algorithm>

using namespace std;

void ex10_1(vector<int> &ivec, int number) {
	cout << " The number of " << number << " occurs " << 
		count(ivec.cbegin(), ivec.cend(), number) << " time(s). " << endl;
}

int main() {
	vector<int> ivec{ 1,1,1,1,1,1,5,5,5,7,7,7,7,8 };

	ex10_1(ivec, 1);
	return 0;
}