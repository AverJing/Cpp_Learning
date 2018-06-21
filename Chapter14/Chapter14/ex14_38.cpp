/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Check {
public:
	bool operator()(string s,int length) {
		return s.size() == length;
	}
};

int main() {
	vector<string> svec;
	ifstream infile("input.txt");
	string word;
	while (infile >> word)
		svec.push_back(word);
	stable_sort(svec.begin(), svec.end());
	for (int i = 1, count = 0; i < 11; ++i) {
		for (vector<string>::iterator begin = svec.begin(); begin != svec.end(); ++begin) {
			if (Check()(*begin, i))
				++count;
			else
				break;
		}
		cout << "the number of size " << i << " is " << count << endl;
	}
	return 0;
}