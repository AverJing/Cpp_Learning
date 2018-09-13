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

template<typename T, typename F>
int count(const T& t, const F& f) {
	int num = 0;
	for (auto iter = t.begin(); iter != t.end(); ++iter)
		if (*iter == f) ++num;
	return num;
}

int main(){
	
}	