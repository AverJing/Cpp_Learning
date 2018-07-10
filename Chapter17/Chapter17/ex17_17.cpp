/*
*
*@author£ºAver Jing
*@description£º
*	 Update your program so that it finds all the words in an input sequence
*that violiate the "ei" grammar rule.
*@date£ºJuly 5, 2018
*
*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	string s;
	cout << "Please inout a sequence of words;" << endl;
	getline(cin, s);
	cout << endl;
	cout << "Word(s) that violiate the \"ei\" grammar rule:" << endl;
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	for (sregex_iterator it(s.begin(), s.end(), r), end_it;
		it != end_it; ++it)
		cout << it->str() << endl;

	return 0;
}