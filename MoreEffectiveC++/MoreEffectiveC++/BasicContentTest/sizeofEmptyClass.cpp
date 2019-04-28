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

struct empty {

};

struct Inherit :empty {

};

int main(){
	std::cout << sizeof(empty) << ' ' << sizeof(Inherit) << '\n';
	
	return 0;
}