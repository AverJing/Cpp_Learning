/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>

using namespace std;

template <typename T, typename It>
It find(It beg, It end, T value) {//better, const T& value
	for (; beg != end; ++beg) {
		if (*beg == value)
			return beg;
	}
	else return end;
}

int main() {

	return 0;
}