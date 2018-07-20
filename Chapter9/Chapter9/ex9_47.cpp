/*
*
*@author£ºAver Jing
*@description£º Write a program that finds each numeric character and then
*each alphabetic character in the string "ab2c3d7R4E6". Write two
*versions of the program. The first should use find_first_of, and the
*second find_first_not_of.
*@date£ºJuly 19, 2018
*
*/

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string numbers{ "0123456789" };
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string str{ "ab2c3d7R4E6" };

	cout << "numeric characters: ";
	for (string::size_type pos = 0;
		(pos = str.find_first_of(numbers, pos)) != string::npos; ++pos)
		cout << str[pos] << " ";
	cout << "\nalphabetic characters: ";
	for (string::size_type pos = 0;
		(pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos)
		cout << str[pos] << " ";
	cout << endl;

	cout << "numeric characters: ";
	for (string::size_type pos = 0;
		(pos = str.find_first_not_of(alphabet, pos)) != string::npos; ++pos)
		cout << str[pos] << " ";
	cout << "\nalphabetic characters: ";
	for (string::size_type pos = 0;
		(pos = str.find_first_not_of(numbers, pos)) != string::npos; ++pos)
		cout << str[pos] << " ";
	cout << endl;

	return 0;
}