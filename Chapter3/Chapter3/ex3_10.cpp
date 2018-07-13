/*
*
*@author£ºAver Jing
*@description£ºWrite a program that reads a string of characters including
*punctuation and writes what was read but with the punctuation removed.
*@date£ºJuly 11, 2018
*
*/

#include<iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
	string s;
	if (getline(cin, s)) {
		/*
		for (auto& e : s) {
			if (!ispunct(e)) cout << e;
		}*/
		//Attention: when you erase elements. remember update the iterator!!
		for (auto beg = s.begin(); beg != s.end(); ) {
			if (ispunct(*beg)){
				s.erase(std::find(s.begin(), s.end(), *beg));
				continue;
			}
			++beg;
		}
	}
		cout << s << endl;

	return 0;
}