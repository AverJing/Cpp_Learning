/*
*
*@author£ºAver Jing
*@description£ºUsing escape sequences, write a program to print 2M followed
*by a newline. Modify the program to print 2, then a tab, then an M, followed
*by a newline.
*@date£ºJuly 10, 2018
*
*/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//ASCII TABLE
//http://www.asciitable.com/
int main() {
	//cout << "2M" << endl;
	cout << "\062\115\012";

	//cout << "2" << "\t" << "M\n";
	cout << "\062\t\115\012";

	return 0;
}