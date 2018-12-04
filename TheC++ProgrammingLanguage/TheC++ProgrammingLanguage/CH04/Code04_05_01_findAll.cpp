/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

template <class T>
using Iterator = typename T::const_iterator;  //书中有问题？

template <class Container, class V>
vector<Iterator<Container>> find_all(const Container& c,const V& v) {
	vector<Iterator<Container>> res;
	for (auto p = c.cbegin(); p != c.cend(); ++p)
		if (*p == v)
			res.push_back(p);

	return res;
}

int main(){
	string s{ "Mary had a little lamb" };
	for (auto p : find_all(s, 'a'))
		if (*p != 'a')
			std::cerr << "string bug\n";

	
	for (auto p : find_all(vector<string>{"red", "blue", "white"}, string("hello")))
		if (*p != string("red"))
			std::cerr << "vector bug\n";
}	