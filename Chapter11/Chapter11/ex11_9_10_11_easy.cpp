/*
*
*@author£ºAver Jing
*@description£ºDefine a map that associates words with a list of line
*numbers on which the word might occur.
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include <list>
#include "Sales_data.h"
#include "base_tool.h"

using namespace std;

bool compareIsbn(Sales_data &lhs, Sales_data &rhs) {
	return lhs.ISBN() < rhs.ISBN();
}

void ex11_9_10_11() {
	//ex11_9
	map<string, list<int>> word_line;

	//! ex 11.10
	//! can be declared.
	std::map<std::vector<int>::iterator, int> mv;
	std::map<std::list<int>::iterator, int> ml;

	std::vector<int> vi;
	mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

	//! but when using this one the compiler complained that
	//! error: no match for 'operator<' in '__x < __y'
	std::list<int> li;
	ml.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));
	//  vector<int>::iterator to int is ok ,because < is defined
	//  list<int>::iterator to int is not ok,as no < is defined.

	//ex11_11
	using compareType = bool(*) (Sales_data &lhs, Sales_data &rhs);
	multiset<Sales_data, compareType> bookstore(compareIsbn);

	multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
}

int main() {

	return 0;
}