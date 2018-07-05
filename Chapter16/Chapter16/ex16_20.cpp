/*
*
*@author£ºAver Jing
*@description£º
* Rewrite the function from the previous exercise to use iterators returned from begin
*and end to control the loop.
*@date£º
*
*/

#include<iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

template<typename T> void Print(T&);

int main() {
	vector<int> ivec{ 1,2,3,4,5 };
	string s{ "abcdefg" };
	Print(ivec);
	cout << endl;
	Print(s);
	return 0;
}

template<typename T>
void Print(T &a)
{
	for (/*auto*/typename T::const_iterator i = a.cbegin(); i != a.cend(); ++i)
		cout << *i << ' ';
}
