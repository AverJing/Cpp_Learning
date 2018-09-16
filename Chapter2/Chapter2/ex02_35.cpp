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

int main(){
	const int i = 42;
	auto j = i; //int
	//设置一个类型为auto的引用时，初始值中的顶层常量属性仍然保留
	const auto &k = i; //cosnt int& 
	auto &k2 = i; //const int&
	auto *p = &i; // const int *
	const auto j2 = i, &k2 = i; //const int; const int&
	
}	