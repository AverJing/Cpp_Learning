/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include "ex16_29_Blob.h"
#include <iostream>
#include <string>

int main()
{
	Blob<std::string> sb1{ "a", "b", "c" };
	Blob<std::string> sb2 = sb1;

	sb2[2] = "b";

	if (sb1 > sb2) {
		for (auto iter = sb2.begin(); iter != sb2.end(); ++iter) {
			std::cout << *iter << " ";
		}
		std::cout << std::endl;
	}


	std::vector<std::string> vec{ "good", "for", "you" };
	Blob<std::string> sb3(vec.begin(), vec.end());

	for (auto&& s : sb3) {
		std::cout << s << " ";
	}
	std::cout << "\n";
}