/*
*
*@author：Aver Jing
*@description：
* Define a vector<String> and call push_back several times on that vector. Run your program
*and see how often Strings are copied.
*@date：June 11, 2018
*
*/

#include <iostream>
#include <vector>
#include "ex13_44_String.h"

using namespace std;

void foo(String x)
{
	std::cout << x << std::endl;
}

void bar(const String& x)
{
	std::cout << x << std::endl;
}

String baz()
{
	String ret("world");
	return ret;
}

int main() {
	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	String s4(text);
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s5 = baz();

	std::vector<String> svec;
	svec.reserve(8);
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
	svec.push_back(s4);
	svec.push_back(s5);
	svec.push_back(baz());//调用两次移动构造  一次是baz的返回时，一次是构造vec中的元素
	svec.push_back("good job");//调用一次

	for (const auto& s : svec) {
		std::cout << s << std::endl;
	}
		


	return 0;
}