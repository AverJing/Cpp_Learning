/*
*
*@author£ºAver Jing
*@description£ºWrite a program to read a sequence of strings and ints,
*storing each into a pair. Store the pairs in a vector
*@date£ºJuly 24, 2018
*
*/

#include<iostream>

#include "base_tool.h"

using namespace std;

void ex11_12_13() {
	vector<pair<string, int>> pvec;
	string s;
	int i;
	while (cin >> s >> i) {
		//1.
		//pvec.push_back({ s, i });
		//2.
		//pvec.push_back(pair<string, int>(s, i));
		//3.
		//pvec.push_back(make_pair(s, i));
		//4. easiest way
		pvec.emplace_back(s, i);
	}

	for (const auto& e : pvec) {
		cout << e.first << ' ' << e.second << endl;
	}

}

int main() {

	return 0;
}