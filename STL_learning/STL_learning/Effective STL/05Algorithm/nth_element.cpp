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

void test_nth_element() {
	vector<int> ivec{ 2,1,6,4,3,7,5 };
	//rearrange the previous three elements
	std::nth_element(ivec.begin(), ivec.begin() + 2, ivec.end());
	//std::partial_sort(ivec.begin(), ivec.begin() + 3, ivec.end());
	for (auto e : ivec)
		std::cout << e << ' ';
}

int main(){
	test_nth_element();
}	