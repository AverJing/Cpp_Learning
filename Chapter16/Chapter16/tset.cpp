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

void debug_ret(const std::string& s) {
	std::cout << " you " << std::endl;
}

int main(){
	std::string s("sss");
	std::string * sp = &s;
	debug_ret(sp);
}	