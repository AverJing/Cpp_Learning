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

int ex01_9(int n) {
	int i = 50;
	int sum = 0;
	while (i <= n)
		sum += i++;
	return sum;
}
int main(){
	ex01_9(100);
}	