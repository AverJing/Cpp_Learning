/*
*
*@author£ºAver Jing
*@description£ºRewrite that function to use check_size and bind.
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <functional>
#include "base_tool.h"

using namespace std;

void elimDups(vector<string> &svec) {
	sort(svec.begin(), svec.end());
	auto end_unique = unique(svec.begin(), svec.end());
	svec.erase(end_unique, svec.end());
}

bool splitBysz(const string& s, string::size_type sz) {
	return s.size() < sz;
}

void ex10_25(vector<string> &words, size_t sz) {
	elimDups(words);
	auto iter = std::stable_partition(words.begin(), words.end(),
		bind(splitBysz, placeholders::_1, sz));
	for_each(words.begin(), iter,
		[](const string& s) { std::cout << s << " "; });
}

int main() {
	vector<string> v{ "1234", "1234", "1234", "hi~","alan", "alan", "cp" };
	ex10_25(v, 3);

	return 0;
}