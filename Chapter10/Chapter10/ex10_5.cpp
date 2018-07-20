/*
*
*@author£ºAver Jing
*@description£ºIn the call to equal on rosters, what would happen if both
*rosters held C-style strings, rather than library strings?
*@date£ºJuly 10, 2018
*
*/

#include<iostream>
#include <vector>
#include <list>

using namespace std;

void  ex10_5() {
	/*vector<const char *> roster1{ "hello\0" };
	list<const char *> roster2{ "hello\0" };

	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;*/
	//The output is 1.

	char c1[10] = "hello";
	char c2[10] = "hello";
	vector<char *> roster1{ c1 };
	list<char *> roster2{ c2 };

	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;
	//The output is 0.
	//We need to keep in mind that when it comes to comparison of C-style strings, we need
	//to use 'strcmp' but not simply relational operators, for using relational operators is
	//just comparison between the address of two C-style strings but not their values.
}

int main() {

	return 0;
}