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
#include <list>
#include <string>
#include <vector>

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

//Write a program to assign the elements from a list<char *> pointers to a vector<string>
void ex9_14() {
	list<const char *> clist = { "hello", "hi" };//should be const 
	vector<string> svec(clist.cbegin(), clist.cend()); //ok
	for (auto &s : svec)
		cout << s << ' ';
	cout << endl;
	clist.push_back("Bye");

	svec.assign(clist.cbegin(), clist.cend());
	for (auto &s : svec)
		cout << s << ' ';
	cout << endl;
}

int main(){
	
}	