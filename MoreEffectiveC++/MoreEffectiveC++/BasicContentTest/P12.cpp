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
//https://github.com/linw7/Skill-Tree/blob/master/%E7%BC%96%E7%A8%8B%E8%AF%AD%E8%A8%80C%2B%2B.md#oop
// https://www.zhihu.com/question/29798061

typedef const char * p_char;
#define p_char2 const char *

#define para (int*)

void print para{
	std::cout << "hahahahah" << "\n";
}

int main(){
	p_char a="abc";
	p_char2 b = "abc";

	std::cout << a << '\n' << b << '\n';
	int* i = new int(10);
	print(i);
	
	delete i;

	return 0;
}