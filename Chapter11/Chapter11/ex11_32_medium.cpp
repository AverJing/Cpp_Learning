/*
*
*@author£ºAver Jing
*@description£ºUsing the multimap from the previous exercise, write a
*program to print the list of authors and their works alphabetically.
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex11_32() {
	multimap<string, string> author_work{ { "a","aa" },{ "b", "bb" },{ "c", "cc" },{ "a", "abc" } };
	map<string, set<string>> order_author;
	for (const auto& e : author_work) {
		order_author[e.first].insert(e.second);
	}
	for (const auto &e : order_author) {
		cout << e.first << ':';
		for (const auto& work : e.second)
			cout << work << ' ';
		cout << endl;
	}
}

int main() {
	return 0;
}