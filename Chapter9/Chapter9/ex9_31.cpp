/*
*
*@author£ºAver Jing
*@description£º The program on page 354 to remove even-valued elements
*and duplicate odd ones will not work on a list or forward_list. Why?
*Revise the program so that it works on these types as well.
*@date£ºJuly 19, 2018
*
*/

#include<iostream>
#include <list>
#include <forward_list>

using namespace std;

template<class a>
void Print(const a &v) {
	for (auto &i : v)
		cout << i << ' ';
	cout << endl;
}

void ex9_31_list(list<int> &ilst) {
	auto iter = ilst.begin();
	while (iter != ilst.end()) {
		if (*iter % 2) {
			iter = ilst.insert(iter, *iter);
			/*++iter
			++iter;*/
			advance(iter, 2);
		}
		else
			iter = ilst.erase(iter);
	}
	Print(ilst);
}

void ex9_31_list(forward_list<int> &fwd_lst) {
	auto iter2 = fwd_lst.begin();
	auto iter2_pre = fwd_lst.before_begin();
	while (iter2 != fwd_lst.end()) {
		if (*iter2 % 2) {
			iter2 = fwd_lst.insert_after(iter2, *iter2);
			iter2_pre = iter2;
			++iter2;
		}
		else
			iter2 = fwd_lst.erase_after(iter2_pre);
	}
	Print(fwd_lst);
}

int main() {

	return 0;
}