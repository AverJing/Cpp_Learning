/*
*
*@author£ºAver Jing
*@description£ºWrite a program to read two strings and report whether the
*strings are equal. If not, report which of the two is larger. Now, change
*the program to report whether the strings have the same length, and if
*not, report which is longer.
*@date£º
*
*/

#include<iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1 == s2) {
			cout << "equal" << endl;
		}
		else if (s1 < s2) {
			cout << s1 << " is less than " << s2 << endl;
		}
		else {
			cout << s1 << " is more than " << s2 << endl;
		}
	}

	return 0;
}