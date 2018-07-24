/*
*
*@author£ºAver Jing
*@description£ºRewrite the map that stored vectors of children¡¯s names
*with a key that is the family last name for the exercises in ¡ì 11.2.1 (p. 424)
*to use a multimap.
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex11_23() {
	multimap<string, string> family;
	string last_name;
	string chld_name;
	while (cin >> last_name >> chld_name && last_name != "q" &&chld_name != "q") {
		family.emplace(last_name, chld_name);
	}
	for (const auto &e : family) {
		cout << e.first << ' ' << e.second;
	}
}

int main() {

	return 0;
}