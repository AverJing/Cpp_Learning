/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>
#include "ex16_28_shared_ptr.h"

using namespace std;

//This version shared_ptr has preoblems as followed.
int main() {
	int *p = new int(19);
	shared_pointer<int> i1(p);
	{
		shared_pointer<int> i2(p);
		cout << *i2.get();
	}

	return 0;
}