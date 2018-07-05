/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include <iostream>
#include <vector>

#include "ex16_12_Blob.h"


int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	Blob<int> b(v.begin(), v.end());
	return 0;
}