/*
*
*@author£ºAver Jing
*@description£ºImplement your own version of elimDups. Test your
*program by printing the vector after you read the input, after the call to
*unique, and after the call to erase
*@date£ºJuly 20, 2018
*
*/

#include<iostream>

#include "base_tool.h"

//using namespace std;

void elimDups(vector<string> &svec) {
	sort(svec.begin(), svec.end());
	auto end_unique = unique(svec.begin(), svec.end());
	svec.erase(end_unique, svec.end());
}

int main() {
	vector<string> svec{ "a", "c", "b", "a", "c" };
	elimDups(svec);
	Print(svec);
	return 0;
}