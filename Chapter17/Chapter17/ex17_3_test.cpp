/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>
#include "TextQueryTuple.h"

using namespace std;

int main()
{
	ifstream file("storyDataFile.txt");
	TextQueryTem tq(file);
	while (true) {
		std::cout << "Enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}