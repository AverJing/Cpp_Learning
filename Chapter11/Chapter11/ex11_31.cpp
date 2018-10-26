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
#include <map>
#include <string>

using std::string;
using std::multimap;

//Write a program that defines a multimap of authors and their works. Use find to find an element
//in the multimap and erase that element. Be sure your program works correctly if the element you
//look for is not in the map.
void ex11_31(string index, string pwork) {
	multimap<string, string> author_work;
	string author, work;
	while (std::cin >> author >> work) {
		author_work.emplace(author, work);
	}
	auto result = author_work.equal_range(index);
	for (auto iter = result.first; iter != result.second; ++iter) {
		if (iter->second == pwork)
			iter = author_work.erase(iter);
	}
	for (const auto &e : author_work) {
		std::cout << e.first << ' ' << e.second << std::endl;
	}
}

int main(){
	ex11_31("jing", "hello");
}	