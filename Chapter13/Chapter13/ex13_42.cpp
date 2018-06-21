/*
*
*@author£ºAver Jing
*@description£º
* Test StrVec class by using it in place of the vector<string> in your TextQuery and 
*QueryResult classes.
*@date£ºJune 11, 2018
*
*/

#include<iostream>
#include "ex13_42_TextQuery.h"

using namespace std;

void runQueries(std::ifstream& infile)
{
	TextQueryTem tq(infile);
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main()
{
	std::ifstream file("word_search.txt");
	runQueries(file);
}