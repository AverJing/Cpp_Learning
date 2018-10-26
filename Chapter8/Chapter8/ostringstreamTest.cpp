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
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;

void test() {
	vector<string> svec{ "hello word", ", ","aver jing" };
	std::ostringstream s;
	for (auto &e : svec) {
		s << e;
	}
	std::cout << s.str() << std::endl;
}



int main(){
	test();
}	