/*
*
*@author£ºAver Jing
*@description£ºWrite a program that stores the excluded words in a vector
*instead of in a set. What are the advantages to using a set?
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex11_8() {
	map<string, size_t> word_count;
	vector<string> exclude{ "The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a" };
	string word;

	while (cin >> word) {
		if (find(exclude.begin(), exclude.end(), word) == exclude.end())
			++word_count[word];
	}
	for (const auto &e : word_count)
		cout << e.first << " occurs " << e.second << (e.second > 1 ? " times." : " time.") << endl;
}

int main() {

	return 0;
}