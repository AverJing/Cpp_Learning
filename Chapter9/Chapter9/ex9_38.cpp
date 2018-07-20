/*
*
*@author£ºAver Jing
*@description£ºWrite a program to explore how vectors grow in the library you use.
*@date£ºJuly 19, 2018
*
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> v;
	std::string word;

	while (std::cin >> word) {
		v.push_back(word);
		std::cout << v.capacity() << "\n";
	}

	return 0;
}