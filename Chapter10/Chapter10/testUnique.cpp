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
#include <algorithm>
#include <vector>

using std::vector;

//Eliminates all but the first element from every consecutive group of equivalent elements 
//from the range [first, last) and returns a past-the-end iterator for the new logical end of the range.
int main(){
	vector<int> ivec{ 1,2,3,4,2,5,1,2,3,1 };
	//注意unique虽然不要求序列全局有序，但相同的值必须连续
	//every consecutive group of equivalent elements
	ivec.erase(std::unique(ivec.begin(), ivec.end()), ivec.end());
	for (auto e : ivec)
		std::cout << e << ' ';
}	