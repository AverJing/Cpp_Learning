/*
*
*@author£ºAver Jing
*@description£ºExtend the map of children to their family name that you
*wrote for the exercises in ¡ì 11.2.1 (p. 424) by having the vector store a
*pair that holds a child¡¯s name and birthday.
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex11_14() {
	map<string, vector<pair<string, string>>> family;
	string last_name;
	string chld_name;
	string chld_birth;
	/*1.
	while (cin >> last_name) {
	cout << "Enter children's name:";
	string name;
	while (cin >> name) {
	family[last_name].push_back(name);
	}
	}*/
	//2.
	while ([&]()->bool {
		cout << "Please enter last name\n";
		return cin >> last_name && last_name != "q"; //
	}()) {
		cout << "Enter children's name:\n";
		while (cin >> chld_name >> chld_birth && chld_name != "q" && chld_birth != "q") {
			family[last_name].emplace_back(chld_name, chld_birth);
		}
	}

	for (const auto &e : family) {
		cout << e.first << ' ';
		for (const auto& s : e.second)
			cout << s.first << ' ' << s.second << endl;
	}
}

int main() {

	return 0;
}