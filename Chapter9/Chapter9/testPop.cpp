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

using std::queue;

int main(){
	queue<int> ique;
	ique.push(1);
	ique.push(2);
	ique.push(3);
	std::cout << ique.size() << ' ';
	ique.pop();
	std::cout << ique.size();
}	