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

using std::vector;


int main(){
	vector<int> ivec{ 1,2,3,4,5,6,7 };

	ivec.erase((ivec.rbegin() + 3).base());//erase 5

	for (auto e : ivec)
		std::cout << e << ' ';
	
}	