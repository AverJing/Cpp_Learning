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
#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;

shared_ptr<vector<int>> dynamic_vector_generator() {
	return std::make_shared<vector<int>>();
}

void dynamic_vector_input(const shared_ptr<vector<int>>& p) {
	int i;
	while (std::cin >> i) p->push_back(i);
}

void dynamic_vector_input(const shared_ptr<vector<int>>& p) {
	for (const auto e : *p)
		std::cout << e << ' ' ;
}


int main(){
	auto p = dynamic_vector_generator();
	dynamic_vector_input(p);
	dynamic_vector_input(p);
}	