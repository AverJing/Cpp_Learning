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

using std::string;
#include "ex16_48.h"

int main(){
	//debug_rep("hello, wolrd");//4 3

	const char* p = "nihao";
	//debug_rep(p);//4 3

	string s("blabla");
	//debug_rep(s);//3

	//error
	char s2[10] = "what?";
	//debug_rep(s2);//5 3 

	string* sp = &s;
	debug_rep(sp);// 2 3
}	