/*
*
*@author£ºAver Jing
*@description£ºWrite a function to open a file for input and read its contents into a vector
of strings, storing each line as a separate element in the vector.
*@date£ºJuly 18, 2018
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void ex8_4(const string &fileName, vector<string> &svec) {
	ifstream ifile(fileName, ios::in);
	if (ifile) {
		string str;
		while (getline(ifile, str)) {
			svec.push_back(str);
		}
	}
}

//Rewrite the previous program to store each word in separate element
void ex8_4(const string &fileName, vector<string> &svec) {
	ifstream ifile(fileName, ios::in);
	if (ifile) {
		string str;
		while (ifile >> str) {
			svec.push_back(str);
		}
	}
}

int main() {
	vector<string> svec;
	ex8_4("input.txt", svec);

	return 0;
}