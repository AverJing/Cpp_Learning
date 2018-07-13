/*
*
*@author£ºAver Jing
*@description£ºWrite a program to compare two strings. Now write a
*program to compare the values of two C-style character strings.
*@date£ºJuly 12, 2018
*
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	/*	
	string s1, s2;
	if (cin >> s1 >> s2) {
		cout << "s1: " << s1 << "  s2: " << s2 << endl;
		cout << "The less one is: " << endl;
		cout << (s1 < s2 ? s1 : s2) << endl;
	}*/
	
	char s3[6], s4[6];
	if (cin >> s3 >> s4) {
		cout << "s3: " << s3 << "  s4: " << s4 << endl;
		cout << "The less one is: " << endl;
		cout << (strcmp(s3, s4) ? s3 : s4) << endl;
	}

	return 0;
}