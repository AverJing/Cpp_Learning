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

int main(){
	int *p = nullptr;
	int i = 10;
	p = &i;
	*p = 20;

	std::cout << i << std::endl;
}	