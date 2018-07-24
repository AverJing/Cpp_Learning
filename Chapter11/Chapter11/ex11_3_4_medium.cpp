/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

//Write your own version of the word-counting program.
void ex11_3() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		++word_count[word];
	}
	for (const auto &e : word_count)
		cout << e.first << " occurs " << e.second << (e.second > 1 ? " times." : " time.") << endl;
}

//Extend your program to ignore case and punctuation.
void ex11_4() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		word.erase(remove_if(word.begin(), word.end(), ispunct));
		for (auto &ch : word) ch = tolower(ch);
		++word_count[word];
	}
	for (const auto &e : word_count)
		cout << e.first << " occurs " << e.second << (e.second > 1 ? " times." : " time.") << endl;
}

int main() {

	return 0;
}