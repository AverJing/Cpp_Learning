/*
*
*@author��Aver Jing
*@description��Write a program to read strings from the standard input,
*concatenating what is read into one large string. Print the concatenated
*string. Next, change the program to separate adjacent input strings by a
*space.
*@date��July 11, 2018
*
*/

#include <iostream>
#include <string>

//It is not better, but it is easy.
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1) {
		s2 += s1 + ' ';
	}
	cout << s2 << endl;

	return 0;
}