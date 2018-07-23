/*
*
*@author£ºAver Jing
*@description£ºGiven a vector that has ten elements, copy the elements
*from positions 3 through 7 in reverse order to a list.
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <list>
#include "base_tool.h"

using namespace std;

void ex10_37() {
	vector<int> ilst{ 1,2,3,4,5,6,7,8,9,10 };
	list<int> dest;
	//reverse_copy(ilst.begin() + 3, ilst.begin() + 8, back_inserter(dest));
	copy(ilst.rbegin() + 2, ilst.rbegin() + 7, back_inserter(dest));
	Print(dest);
}

int main() {

	return 0;
}