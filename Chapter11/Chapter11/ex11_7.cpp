/*
*
*@author£ºAver Jing
*@description£ºDefine a map for which the key is the family¡¯s last name and
*the value is a vector of the children¡¯s names. Write code to add new
*families and to add new children to an existing family.
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex11_7() {
	map<string, vector<string>> family;
	string last_name;
	string chld_name;

	while ([&]()->bool {
		cout << "Please enter last name\n";
		return cin >> last_name && last_name != "q";
	}()) {
		cout << "Enter children's name:\n";
		while (cin >> chld_name && chld_name != "q") {
			family[last_name].push_back(chld_name);
		}
	}

	for (const auto &e : family) {
		cout << e.first << ' ';
		Print(e.second);
	}
}

int main() {

	return 0;
}