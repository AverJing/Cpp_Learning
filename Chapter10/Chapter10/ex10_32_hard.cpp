/*
*
*@author£ºAver Jing
*@description£º Rewrite the bookstore problem from ¡ì 1.6 (p. 24) using a
*vector to hold the transactions and various algorithms to do the processing.
*Use sort with your compareIsbn function from ¡ì 10.3.1 (p. 387) to
*arrange the transactions in order, and then use find and accumulate to
*do the sum
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <iterator>
#include <numeric>
#include "Sales_item.h"
#include "base_tool.h"

using namespace std;

void ex10_32() {
	istream_iterator<Sales_item> in_iter(cin), in_eof;
	vector<Sales_item> vec;

	//copy(in_iter, in_eof, back_inserter(vec));
	while (in_iter != in_eof) vec.push_back(*in_iter++);
	sort(vec.begin(), vec.end(), [](Sales_item const& lhs, Sales_item const& rhs) {
		return lhs.isbn() < rhs.isbn(); });
	for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
		end = find_if(beg, vec.cend(), [beg](const Sales_item& item) {
			return item.isbn() != beg->isbn();
		});
		cout << accumulate(beg, end, Sales_item(beg->isbn()))
			<< endl;
	}
}

int main() {

	return 0;
}