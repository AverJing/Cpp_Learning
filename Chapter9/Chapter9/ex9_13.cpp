/*
*
*@author£ºAver Jing
*@description£ºHow would you initialize a vector<double> from a
*list<int>? From a vector<int>? Write code to check your answers.
*@date£ºJuly 18, 2018
*
*/

#include<iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	list<int>ilst{ 1,2,3,4,5,6,7,8,9 };

	vector<double> dvec(ivec.cbegin(), ivec.cend());
	vector<double> dvec2(ilst.cbegin(), ilst.cend());

	return 0;
}