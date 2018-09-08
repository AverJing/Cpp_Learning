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

int ex01_13(int n) {
	int sum = 0;
	for (int val = 1; val <= n; ++val)
		sum += val;
}

int main(){
	std::cout << ex01_13(10) << std::endl;
}	