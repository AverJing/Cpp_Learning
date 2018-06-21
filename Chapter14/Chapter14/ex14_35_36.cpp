/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PrintString {
public:
	//ex14_35
	/*
	string operator()(istream& in) {
		string word;
		if (getline(in, word))
			return word;
		else
			return "";
	}
	*/
	//ex14_36
	void operator()(istream& in) {
		string word;
		while(getline(in, word))
			svec.push_back(word);
	}
	void Print() {
		for (auto &e : svec)
			cout << e << ' ';
	}
private:
	vector<string> svec;
};

int main() {
	PrintString is;
	//cout << is(cin);
	/*
	is(cin);
	is.Print();*/

	return 0;
}