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
#include <list>
#include <string>

using std::string;
using std::list;

void ex10_42(list<string>& words) {
	words.sort();
	words.unique();
}

int main(){
	list<string> l{ "aa", "aa", "aa", "aa", "aasss", "aa" };
	ex10_42(l);

	for (auto&e : l)
		std::cout << e << ' ';
}	