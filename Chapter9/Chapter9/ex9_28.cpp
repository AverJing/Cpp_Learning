/*
*
*@author£ºAver Jing
*@description£ºWrite a function that takes a forward_list<string> and
*two additional string arguments. The function should find the first string
*and insert the second immediately following the first. If the first string is
*not found, then insert the second string at the end of the list.
*@date£ºJuly 19, 2018
*
*/

#include<iostream>
#include <forward_list>
#include <string>
#include <algorithm>

using namespace std;

void ex9_28(forward_list<string> &sflst,const string &s1,const string &s2) {
	auto place = find(sflst.begin(), sflst.end(), s1);
	if (place != sflst.end()) {
		sflst.insert_after(place, s2);
	}
	else {
		sflst.insert_after(place, s2);
	}
	for (auto &e : sflst)
		cout << e << ' ';
	cout << endl;
}

int main() {
	forward_list<string> s{ "It's", "up", "to", "you", "how", "far", "you", "go" };
	ex9_28(s, "you", "...");

	return 0;
}