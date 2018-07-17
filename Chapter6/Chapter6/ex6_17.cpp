/*
*
*@author£ºAver Jing
*@description£ºWrite a function to determine whether a string contains
*any capital letters. Write a function to change a string to all lowercase. Do
*the parameters you used in these functions have the same type? If so, why?
*If not, why not?
*@date£ºJuly 16, 2018
*
*/

#include <iostream>
#include <string>

using std::string;

bool hasUppercase(const string& str)
{
	for (auto c : str)
		if (isupper(c)) return true;
	return false;
}

const string& makeLowercase(string& str)
{
	for (auto& c : str)
		if (isupper(c)) c = tolower(c);
	return str;
}

int main()
{
	string str("Hello World!");
	std::cout << std::boolalpha << hasUppercase(str) << std::endl;
	std::cout << makeLowercase(str) << std::endl;
}