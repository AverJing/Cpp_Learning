/*
*
*@author£ºAver Jing
*@description£ºWrite your own version of the biggies function using
*lambdas.
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

void biggies(vector<string> &vs, size_t sz) {
	elimDups(vs);
	//sort by size, but maintain alphabetical order for same size
	stable_sort(vs.begin(), vs.end(), [](string const& a, string const& b) {return a.size() < b.size(); });
	//get an iterator to the first one whose size() is >= a
	auto pivot = find_if(vs.begin(), vs.end(), [sz](string& a) {return a.size() >= sz; });
	//print the result
	for_each(pivot, vs.end(), [](string& a) {cout << a << ' '; });
}


int main() {

	return 0;
}