/*
*
*@author£ºAver Jing
*@description£ºUsing the following definition of ia, copy ia into a vector
*and into a list. Use the single-iterator form of erase to remove the
*elements with odd values from your list and the even values from your
*vector.
*	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
*@date£ºJuly 19, 2018
*
*/

#include<iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
vector<int> ivec(begin(ia), end(ia));
list<int> ilst(begin(ia), end(ia));

template <class T>
void Print(T beg, T end) {
	while (beg != end)
		cout << *beg++ << ' ';
}

template <class T>
void Print(T &t) {
	for (auto beg = t.begin(); beg != t.end(); ++beg)
		cout << *beg << ' ';
}

void ex9_26() {
	for (auto beg = ivec.begin(); beg != ivec.end(); )
		if (*beg % 2 == 0)
			beg = ivec.erase(beg);
		else
			++beg;
	auto begin_list = ilst.begin();
	while (begin_list != ilst.end()) {
		if (*begin_list % 2) {
			begin_list = ilst.erase(begin_list);
		}
		else
			++begin_list;
	}
	cout << "The element of vector is ";
	Print(ivec);	cout << endl;
	cout << "The element of list is ";
	Print(ilst);	cout << endl;
}

int main() {
	ex9_26();
	return 0;
}