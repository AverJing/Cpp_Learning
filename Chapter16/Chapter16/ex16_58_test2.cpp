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
#include <string>
#include "ex16_16_Vec.h"

using std::string;

int main(){
	Vec<string>  svec = { "hello", "hi", "nice" };
	string s = "cccccccc";
	svec.emplace_back(s);

	for (auto &e : svec)
		std::cout << e << ' ';
	std::cout << std::endl;
}	