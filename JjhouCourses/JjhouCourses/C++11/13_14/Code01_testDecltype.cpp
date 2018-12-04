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
#include <queue>
#include <vector>

template<class T1, class T2>
auto sum(T1 lhs, T2 rhs) ->decltype(lhs+rhs)
{
	return lhs + rhs;
}

int main(){
	auto cmp = [](int a, int b) {return a < b; };
	std::priority_queue<int, std::vector<int>, decltype(cmp)> s(cmp);
	

}	