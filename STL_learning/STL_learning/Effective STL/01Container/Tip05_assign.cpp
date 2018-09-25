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
#include <algorithm>

using std::vector;

int main(){
	vector<int> i1{ 1,2,3,4 };
	vector<int> i2{ 6,7,8,9,0 };
	/*
	std::cout << i1.capacity() << std::endl;
	i1.clear();
	std::cout << i1.capacity() << std::endl;
	std::copy(i2.begin(), i2.end(), std::back_inserter(i1));*/

	//better answer
	//i1.assign(i2.begin(), i2.end());

	//erase, is not really erase the element
	/*
	std::cout << i1.capacity() << std::endl;
	i1.erase(i1.begin(), i1.end());
	std::cout << i1.capacity() << std::endl;*/

	for (auto e : i1) {
		std::cout << e << ' ';
	}
}	