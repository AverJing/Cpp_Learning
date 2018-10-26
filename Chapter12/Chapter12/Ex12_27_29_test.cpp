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
#include <fstream>
#include "Ex12_27_29.h"

int main(){
	std::fstream ifle("word_search.txt");
	if (!ifle) std::cout << "fstream error" << std::endl;
	TextQuery t(ifle);
	while (true) {
		std::cout << "enter the word to look for, or q to quit:";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, t.query(s));
	}
}	