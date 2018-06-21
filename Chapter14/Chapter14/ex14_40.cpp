/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class ShortString {
public:
	bool operator()(const string& lhs, const string& rhs) {
		return lhs.size() < rhs.size();
	}
};

class BiggerString {
public:
	BiggerString(size_t n = 0) :sz(n) {  }
	bool operator()(const string& lhs) {
		return lhs.size() >= sz;
	}
private:
	size_t sz;
};

class PrintString {
public:
	void operator()(const string& lhs) {
		cout << lhs << ' ';
	}
};

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto p = unique(words.begin(), words.end());
	words.erase(p, words.end());
}

void Print(vector<string>& svec) {
	for (auto &e : svec)
		cout << e << ' ';
	cout << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), ShortString());
	//Print(words);
	auto wc = find_if(words.begin(), words.end(), BiggerString(sz));
	auto count = words.end() - wc;
	for_each(wc, words.end(), PrintString());
	cout << endl;
}

int main() {
	vector<string> svec{ "Change", "is", "the", "essence", "of", "life", "be", "willing"
	, "to", "surrender", "what", "you", "are", "for", "what", "you", "could", "become" };
	biggies(svec, 5);

	return 0;
}