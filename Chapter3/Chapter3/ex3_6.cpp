/*
*
*@author£ºAver Jing
*@description£ºUse a range for to change all the characters in a string to
*X.
*@date£ºJuly 11, 2018
*
*/

#include<iostream>
#include <string>

using namespace std;

int main() {
	string s("hello word!");

	cout << s << endl;

	for (auto &e : s) {
		e = 'X';
	}
	cout << s << endl;

	return 0;
}