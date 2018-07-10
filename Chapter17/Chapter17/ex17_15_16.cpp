/*
*
*@author£ºAver Jing
*@description£º
* Write a program using the pattern that finds word that violate the
*"i before e except after c" rule. Have your program prompt the user to
*supply a word and indicate whether the word is okay or not. Test your
*program with words that do and do not violate the rule.
*@date£º
*
*/

#include<iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	//regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);
	regex r("[^c]ei", regex::icase);
	string s;
	cout << "Please input a word! Input 'q' to quit!" << endl;
	while (cin >> s && s != "q")
	{
		if (std::regex_match(s, r))
			cout << "Input word " << s << " is okay!" << endl;
		else
			cout << "Input word " << s << " is not okay!" << endl;

		cout << "Please input a word! Input 'q' to quit!" << endl;
	}

	cout << endl;

	return 0;
}