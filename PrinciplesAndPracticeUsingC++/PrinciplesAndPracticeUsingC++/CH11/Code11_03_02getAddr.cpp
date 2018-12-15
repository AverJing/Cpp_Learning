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

//获取对象内存第一个字节的地址
//没弄明白  看12和13章
void getAddr(int& i) {
	std::cout << "Address: " << &i << "\n";
	void* addr = &i;
	char* tmp = static_cast<char*>(addr);
	std::cout << "Starting Address: " <<  (void*)tmp << "\n";
	//注意，默认字符数组直接输出的字符串
}

int main(){
	int i = 1234;
	getAddr(i);
}	