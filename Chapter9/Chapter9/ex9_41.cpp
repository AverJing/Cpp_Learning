/*
*
*@author��Aver Jing
*@description��Write a program that initializes a string from a
*vector<char>.
*@date��July 19, 2018
*
*/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main()
{
	vector<char> vec{ 'p', 'e', 'z', 'y' };
	string str(vec.begin(), vec.end());

	cout << str << endl;

	return 0;
}