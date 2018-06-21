/*
*
*@author£ºAver Jing
*@description£º
* Revise the previous program to report the count of words that are sizes 1 through 9 and 10
or more.
*@date£ºJune 19, 2018
*
*/

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Check {
public:
	Check(size_t low = 0, size_t up = 0) :low(low), up(up) {}
	bool operator()(string s) {
		return s.size() >= low && s.size() <= up;
	}
private:
	size_t low;
	size_t up;
};

int main() {
	vector<string> svec;
	ifstream infile("input.txt");
	Check len9(1, 9), len10(1, 10);
	string word;
	while (infile >> word)
		svec.push_back(word);
	//stable_sort(svec.begin(), svec.end());
	//for (int i = 9, count = 0; i < 11; ++i) {
	//	for (vector<string>::iterator begin = svec.begin(); begin != svec.end(); ++begin) {
	//		if (len9(*begin))
	//			++count;
	//		else
	//			break;
	//	}
	//	cout << "the number of size " << i << " is " << count << endl;
	//}
	int count9 = 0, count10 = 0;
	for (vector<string>::iterator begin = svec.begin(); begin != svec.end(); ++begin) {
		if (len9(*begin))
			++count9;
		if (len10(*begin))
			++count10;
	}
	return 0;
}