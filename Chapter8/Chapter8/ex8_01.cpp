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

using std::istream;
using std::string;
using std::cout;
using std::endl;

//Write a function that takes and returns an istream &
istream &ex8_1(istream &is) {
	string str;
	while (is >> str)
		cout << str << endl;
	is.clear();//reset  the stream
	return is;
}

int main(){
	
}	