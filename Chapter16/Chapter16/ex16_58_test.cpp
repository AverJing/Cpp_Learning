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

#include "ex16_58_StrVec.h"

using std::string;

int main(){
	StrVec s = { string("hello"), string("hi"), string("nice")  };
	s.emplace_back(10, 'c');
	//当把实参传递给construct函数时，会自动使用string的移动构造

	for (auto &e : s)
		std::cout << e << ' ';
	std::cout << std::endl;

	return 0;
}	