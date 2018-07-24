/*
*
*@author£ºAver Jing
*@description£ºRewrite the word-counting program from ¡ì 11.1 (p. 421) to
*use insert instead of subscripting.Which program do you think is easier to
*write and read ? Explain your reasoning.
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex11_20() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		//++word_count[word];
		auto ret = word_count.insert({ word , 1 });
		if (!ret.second)
			++ret.first->second;
	}
	for (const auto &e : word_count)
		cout << e.first << " occurs " << e.second << (e.second > 1 ? " times." : " time.") << endl;
}

int main() {

	return 0;
}