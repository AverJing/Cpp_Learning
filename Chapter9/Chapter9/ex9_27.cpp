/*
*
*@author£ºAver Jing
*@description£ºWrite a program to find and remove the odd-valued
*elements in a forward_list<int>.
*@date£ºJuly 19, 2018
*
*/

#include<iostream>
#include <forward_list>

using namespace std;

void ex9_27(forward_list<int> &iflst) {
	auto prev = iflst.before_begin();
	auto curr = iflst.begin();
	while (curr != iflst.end()) {
		if (*curr % 2)
			curr = iflst.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}	
	}
	for (auto &e : iflst)
		cout << e << ' ';
	cout << endl;
	/*
	for (auto beg = iflst.cbegin(); beg != iflst.cend(); ++beg)
		cout << *beg << ' ';
	cout << endl;*/
}

int main() {
	forward_list<int> i{ 1,2,3,4,5,6,7,8,9 };
	ex9_27(i);
	return 0;
}