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

template<typename T>
struct add_conference {
	typedef T& value;
};

//注意引用折叠
int main(){
	int j = 10;
	add_conference<int&>::value k = j;
}	