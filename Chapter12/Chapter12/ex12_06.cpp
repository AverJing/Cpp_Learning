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

//思考，分配一个空的vector动态内存，但是当vector不断扩大时，p会改变吗
int main(){
	auto p = new vector<int>();
	std::cout << p << std::endl;
	std::cout << &*p << std::endl;

	for (auto i = 0; i < 100; ++i)
		p->push_back(i);
	std::cout << p << std::endl;
	std::cout << &*p << std::endl;
	delete p;

	//https://www.zhihu.com/question/36773826
	//这些只是指针，管理vector本身数据的存储空间的，就算vector发生了重新分配，不会影响到p
}	