/*
*
*@author£ºAver Jing
*@description£º Rewrite biggies to use partition instead of find_if.
*We described the partition algorithm in exercise 10.13 in ¡ì 10.3.1 (p.
*387).
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

void ex10_18(vector<string> &vs, size_t sz) {
	elimDups(vs);
	//sort by size, but maintain alphabetical order for same size
	//stable_sort(vs.begin(), vs.end(), [](string const& a, string const& b) {return a.size() < b.size(); });
	//get an iterator to the first one whose size() is >= a
	auto pivot = partition(vs.begin(), vs.end(), [sz](string& a) {return a.size() >= sz; });
	// Reorders the elements in the range [first, last) in such a way 
	//that all elements for which the predicate p returns true precede 
	//the elements for which predicate p returns false

	//print the result
	for_each(vs.begin(), pivot, [](string& a) {cout << a << ' '; });
}

//Use stable_partition to rewrite the previous program.
void ex10_19(vector<string> &vs, size_t sz) {
	elimDups(vs);
	//sort by size, but maintain alphabetical order for same size
	//stable_sort(vs.begin(), vs.end(), [](string const& a, string const& b) {return a.size() < b.size(); });
	//get an iterator to the first one whose size() is >= a
	auto pivot = stable_partition(vs.begin(), vs.end(), [sz](string& a) {return a.size() >= sz; });
	//print the result
	for_each(vs.begin(), pivot, [](string& a) {cout << a << ' '; });
}


int main() {

	return 0;
}