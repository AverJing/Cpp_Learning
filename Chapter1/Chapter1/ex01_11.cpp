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

void ex01_11(int lower, int upper) {
	if (lower > upper) std::swap(lower, upper);
	while (lower <= upper)
		std::cout << lower++ << ' ';
}

int main(){
	ex01_11(0, 11);
}	