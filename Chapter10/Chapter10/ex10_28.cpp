/*
*
*@author£ºAver Jing
*@description£ºCopy a vector that holds the values from 1 to 9 inclusive,
*into three other containers. Use an inserter, a back_inserter, and a
*front_inserter, respectivly to add elements to these containers. Predict
*how the output sequence varies by the kind of inserter and verify your
*predictions by running your programs.
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <iterator>
#include <list>
#include "base_tool.h"

using namespace std;

void ex10_28() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	vector<int> ivec2, ivec3;
	list<int> ilst;
	copy(ivec.cbegin(), ivec.cend(), inserter(ivec2, ivec2.begin()));
	copy(ivec.cbegin(), ivec.cend(), back_inserter(ivec3));
	copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst));

	Print(ivec2);
	Print(ivec3);
	Print(ilst);
}

int main() {
	ex10_28();

	return 0;
}