/*
*
*@author£ºAver Jing
*@description£ºUse find to find the last element in a list of ints with
*value 0.
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <list>

using namespace std;

void ex10_36() {
	list<int> ilst{ 0,1,20,3,4,0,5,6,7,0,2,3,4 };
	auto found = find(ilst.rbegin(), ilst.rend(), 0);
	cout << *found << "position is " << *found.base();
}

int main() {

	return 0;
}