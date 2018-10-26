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
#include <list>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::list;
using std::cin;
using std::fill_n;

template <typename Sequence> void print(Sequence const& seq)
{
	for (const auto& i : seq) cout << i << " ";
	cout << endl;
}

int main()
{
	// (a)
	vector<int> vec;
	list<int> lst{1,2,3,4,5,6};
	vec.resize(lst.size());
	//vec.reserve(lst.size());
	// ^ Fixed: added this statement
	// Cause Algorithms that write to a destination iterator assume
	// the destination is large enough to hold the number of elements being
	// written.
	copy(lst.cbegin(), lst.cend(), vec.begin());

	// another way to fix bug
	// copy(lst.cbegin(), lst.cend(), back_inserter(vec));

	// (b)
	vector<int> v;
	v.reserve(10);
	//fill_n(v.begin(), 10, 0);
	fill_n(std::back_inserter(v), 10, 0);
	// ^ (b)No error, but not any sense. v.size() still equal zero.
	// Fixed: 1. use `v.resize(10);`
	//    or  2. use `fill_n(std::back_inserter(v), 10, 0)`

	print(v);
	print(vec);
}