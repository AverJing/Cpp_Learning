/*
*
*@author：Aver Jing
*@description：
*@date：
*
*/

#include<iostream>
#include "ex16_28_shared_ptr.h"
#include <array>
#include <vector>
#include <new>

using namespace std;

//就是让编译器报错的
#define print hello world
#define sure 1

#if sure 
	#define wrong [[print("error")]]
#else
	#define wrong
#endif

using pointer = int *;

//This version shared_ptr has preoblems as followed.
int main() {
	//int *p = new int(19);
	//shared_pointer<int> i1(p);
	//{
	//	shared_pointer<int> i2(i1);
	//	//call operator bool() const { return ptr ? true : false; }
	//	//wrong
	//	//参考more effective C++ It28
	//	if (i2 == i1) { std::cout << "....." << std::endl; }

	//	cout << i1.use_count() << ' ' << i2.use_count(); 
	//	//cout << *i2.get();
	//}

	std::cout << alignof(int);

	return 0;
}