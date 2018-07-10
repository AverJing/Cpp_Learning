/*
*
*@author£ºAver Jing
*@description£º
*	Write a regular expression to find zip codes. A zip code can
*have five or nine digits. The first five digits can be separated from the
*remaining four by a dash.
*@date£ºJuly 6, 2018
*
*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	string code = "(\\d{5})([-]?)(\\d{4})?";
	regex r(code);
	string s;
	smatch results;
	while (cin >> s) {
		/*
		for (sregex_iterator it(s.begin(), s.end(), r), end; it != end; ++it) {
			cout << "valid: " << it->str() << endl;
		}*/
		if(regex_search(s, results, r))
			cout << "valid: " << results.str() << endl;
	}

	return 0;
}