/*
*
*@author��Aver Jing
*@description��
*@date��
*
*/

#include<iostream>
#include "ex16_28_shared_ptr.h"
#include <array>

using namespace std;

//This version shared_ptr has preoblems as followed.
int main() {
	int *p = new int(19);
	shared_pointer<int> i1(p);
	{
		shared_pointer<int> i2(i1);
		//call operator bool() const { return ptr ? true : false; }
		//wrong
		//�ο�more effective C++ It28
		if (i2 == i1) { std::cout << "....." << std::endl; }

		cout << i1.use_count() << ' ' << i2.use_count(); 
		//cout << *i2.get();
	}

	return 0;
}