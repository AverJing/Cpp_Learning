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
	int l = 10;
	const int& i = 10;
	int& k = l;

	/*
	等价于 
	double lhs = 3.1424;
	const int temp = lhs;
	const int& ri = temp;
	*/
	double lhs = 3.1424;
	const int& ri = lhs;
	std::cout << &lhs << ' ' << &ri << std::endl;

	return 0;
}