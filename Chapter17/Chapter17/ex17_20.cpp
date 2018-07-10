/*
*
*@author£ºAver Jing
*@description£ºWrite your own version of the program to validate phone numbers.
*@date£ºJuly 6, 2018
*
*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool valid(const smatch& s) {
	// if there is an open parenthesis before the area code
	if (s[1].matched) {
		// the area code must be followed by a close parenthesis
		// and followed immediately by the rest of the number or a space
		return s[3].matched && (s[4].matched == 0 || s[4].str() == " ");
	}	
	else {
		// then there can't be a close after the area code
		// the delimiters between the other two components must match		return !s[3].matched && (s[4].str() == s[6].str());
	}
}

int main() {
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";//"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	while (getline(cin, s)) {
		for (sregex_iterator it(s.begin(), s.end(), r), end; it != end; ++it) {
			if (valid(*it))
				cout << "valid: " << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;
		}
	}

	return 0;
}