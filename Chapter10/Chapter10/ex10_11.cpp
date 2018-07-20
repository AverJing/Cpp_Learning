/*
*
*@author£ºAver Jing
*@description£ºWrite a program that uses stable_sort and isShorter
*to sort a vector passed to your version of elimDups. Print the vector to
*verify that your program is correct.
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void elimDups(vector<string> &svec) {
	sort(svec.begin(), svec.end());
	auto end_unique = unique(svec.begin(), svec.end());
	svec.erase(end_unique, svec.end());
}

bool isShoter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void ex10_11() {
	vector<string> svec{ "111", "111" , "111" , "a", "b", "a", "b" };
	elimDups(svec);
	stable_sort(svec.begin(), svec.end(), isShoter);
	Print(svec);
}

int main() {
	ex10_11();

	return 0;
}