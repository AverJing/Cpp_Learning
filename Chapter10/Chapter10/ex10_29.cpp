/*
*
*@author£ºAver Jing
*@description£ºWrite a program 
*using stream iterators to read a text file into a vector of strings
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <fstream>
#include <iterator>
#include "base_tool.h"

using namespace std;

void ex10_29() {
	vector<string> svec;
	ifstream in("test.txt");
	istream_iterator<string> str_it(in), eof_it;
	copy(str_it, eof_it, back_inserter(svec));

	copy(svec.cbegin(), svec.cend(), ostream_iterator<string>(cout, " "));
}

int main() {
	ex10_29();
	cout << endl;

	return 0;
}