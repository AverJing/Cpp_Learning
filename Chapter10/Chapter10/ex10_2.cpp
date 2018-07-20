/*
*
*@author£ºAver Jing
*@description£ºRepeat the previous program, but read values into a list of strings.
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include <list>
#include <string>

using namespace std;

void ex10_2(list<string> &slst,const string &comp) {
	cout << " The string of " << comp << " occurs " <<
		count(slst.cbegin(), slst.cend(), comp) << " time(s). " << endl;
}


int main() {
	list<string> slst{ "hi", "hi", "hello", "hi", "height" };

	ex10_2(slst, "hi");
	return 0;
}