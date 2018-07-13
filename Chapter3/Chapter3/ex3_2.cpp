/*
*
*@author£ºAver Jing
*@description£ºWrite a program to read the standard input a line at a time.
*Modify your program to read a word at a time.
*@date£ºJuly 11, 2018
*
*/

#include<iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
	string s;
	/*	//read a line at a time
	while (getline(cin, s)) {
		cout << s << endl;
	}*/
		//read a word at a time
	while (cin >> s) {
		cout << s << endl;
	}


	return 0;
}