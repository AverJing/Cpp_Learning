/*
*
*@author£ºAver Jing
*@description£ºRead a sequence of words from cin and store the values a
*vector. After you¡¯ve read all the words, process the vector and change
*each word to uppercase. Print the transformed elements, eight words to a
*line.
*@date£ºJuly 12, 2018
*
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string s;
	vector<string> svec;
	while (cin >> s) {
		for (auto &e : s) {
			if (isalpha(e))
				e = toupper(e);
		}
		svec.push_back(s);
	}
	for (const auto &e : svec)
		cout << e << endl;

	return 0;
}