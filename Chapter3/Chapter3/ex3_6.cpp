/*
*
*@author��Aver Jing
*@description��Use a range for to change all the characters in a string to
*X.
*@date��July 11, 2018
*
*/

#include<iostream>
#include <string>

using namespace std;

int main() {
	string s("hello word!");

	cout << s << endl;

	for (char &e : s) {//or char: auto
		e = 'X';
	}
	cout << s << endl;

	return 0;
}