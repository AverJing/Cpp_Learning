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
#include <random>

void Print_e() {
	unsigned int k = 0;
	std::default_random_engine e;
	for(auto i = 0; i < 2; ++i)
		for (unsigned int j = 0; j < e.max(); j += e())
			++k;

	std::cout << static_cast<double>(k) / 2 << std::endl;
}

int main(){
	/*
	unsigned int i, j, k = 0, n = 1e8;

	for (i = 0; i < n; ++i)
		for (j = 0; j < RAND_MAX; j += rand())
			++k;

	std::cout << static_cast<double>(k) / n << std::endl;*/

	Print_e();
}	