/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>
#include <fstream>
#include "StrBlob.h"

using namespace std;

void ex12_20() {
	ifstream ifle("test.txt");
	string line;
	StrBlob str;
	while (getline(ifle, line)) {
		str.push_back(line);
	}
	StrBlobPtr sptr(str);
	/*for (int i = 0; i < str.size(); ++i) {
	cout << sptr.deref();
	sptr.incr();
	}*/
	for (StrBlobPtr beg(str.begin()), end(str.end()); beg != end; beg.incr())
		cout << beg.deref() << endl;
}

int main() {

	return 0;
}