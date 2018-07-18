/*
*
*@author��Aver Jing
*@description��Test your function by calling it, passing cin as an argument.
*@date��July 17, 2018
*
*/

#include<iostream>
#include <string>

using namespace std;

istream& func(istream& in) {
	string s;
	while (in >> s)
		cout << s << ' ';
	in.clear();
	return in;
}

int main() {
	istream& is = func(cin);
	cout << is.rdstate() << endl;

	return 0;
}