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

template<typename T>
struct Test {
	void operator()(T x) {
		std::cout << x << ' ';
	}
};

int main(){
	vector<int> ivec{ 1,2,3,4,5,6 };
	std::for_each(ivec.begin(), ivec.end(), Test<int>());
}	