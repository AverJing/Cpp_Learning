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

void ex01_10(int i) {
	while (i >= 0)
		std::cout << i-- << ' ';
}

int main(){
	ex01_10(10);
}	