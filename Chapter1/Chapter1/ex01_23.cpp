/*
*
*@author£ºAver Jing
*@description£ºWrite a program that reads several transactions and counts
*how many transactions occur for each ISBN.
*@date£ºJuly 10, 2018
*
*/

#include <iostream>
#include <map>
#include <string>
#include "Sales_item.h"

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;

int main() {
	map<string, int> item_map;
	Sales_item item;
	while (cin >> item) {
		++item_map[item.isbn()];
	}
	for (auto &e : item_map) {
		cout << "ISBN: " <<  e.first << " occur(s) " << e.second << " times. "<< endl;
	}

	return 0;
}