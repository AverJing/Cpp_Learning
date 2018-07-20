/*
*
*@author£ºAver Jing
*@description£ºRewrite the program from the previous exercise to use a
*list. List the changes you needed to make.
*@date£ºJuly 18, 2018
*
*/

#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	list<string> input;
	for (string str; cin >> str; input.push_back(str))
		;
	for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
		cout << *iter << endl;

	return 0;
}