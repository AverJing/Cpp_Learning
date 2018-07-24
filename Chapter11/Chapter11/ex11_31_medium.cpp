/*
*
*@author£ºAver Jing
*@description£ºWrite a program that defines a multimap of authors and
*their works. Use find to find an element in the multimap and erase that
*element. Be sure your program works correctly if the element you look for is
*not in the map
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex11_31(string index, string pwork) {
	multimap<string, string> author_work;
	string author, work;
	while (cin >> author >> work) {
		author_work.emplace(author, work);
	}
	for (auto ret = author_work.find(index); ret != author_work.cend() && ret->first == index;) {
		if (ret->second == pwork)
			author_work.erase(ret);
		else
			++ret;
	}
	for (const auto &e : author_work) {
		cout << e.first << ' ' << e.second << endl;
	}
}

int main() {

	return 0;
}