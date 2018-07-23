/*
*
*@author：Aver Jing
*@description：
*@date：
*
*/

#include<iostream>
#include <list>
#include <iterator>
#include "base_tool.h"

using namespace std;

void ex10_27() {
	vector<int> ivec{ 1,1,5,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9 };
	list<int> ilst;
	//ilst.resize(ivec.size());

	sort(ivec.begin(), ivec.end());
	//unique_copy(ivec.cbegin(), ivec.cend(), ilst.begin());
	/*因为lst3最初为空链表，因此此时lst3.begin()为无效迭代器，
	而又因为此时链表为空，尾前，尾后迭代器相同，
	而尾后迭代器是始终能用的，所以此时所得到的迭代器就默认变成了尾后迭代器*/
	unique_copy(ivec.cbegin(), ivec.cend(), inserter(ilst, ilst.begin()));
	Print(ilst);
}

int main() {
	ex10_27();
	return 0;
}