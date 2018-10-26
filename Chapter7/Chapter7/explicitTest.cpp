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

class ExplicitTest {
public :
	explicit ExplicitTest(string s) { std::cout << s; }
};

int main(){
	ExplicitTest s("hello");
}	