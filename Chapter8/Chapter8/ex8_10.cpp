/*
*
*@author£ºAver Jing
*@description£ºWrite a program to store each line from a file in a vector<string>.
*Use isstringstream to read each element from the vector a word at a time.
*
*@date£ºJuly 18, 2018
*
*/

#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void ex8_10(const string &fileName, vector<string> &svec) {
	ifstream ifile(fileName);
	if (ifile) {
		string str;
		while (getline(ifile, str))
			svec.push_back(str);
	}
	for (auto &e : svec) {
		istringstream iss(e);
		string word;
		while (iss >> word) cout << word << ' ';
		cout << endl;
	}
}

int main() {
	vector<string> s;
	ex8_10("Person.txt", s);

	return 0;
}