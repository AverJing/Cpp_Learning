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
#include <algorithm>

namespace Jcy_test {
	using std::sort;

	template<typename C>
	void sort(C& c) {
		sort(c.begin(), c.end());
	}
	template<typename C, typename Pred>
	void sort(C& c, Pred p) {
		sort(c.begin(), c.end(), p);
	}
}

int main(){
	
}	