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
// https://github.com/linw7/Skill-Tree/blob/master/%E9%94%99%E9%A2%98%E7%B2%BE%E8%A7%A3.md

//C++对象模型
//http://www.cnblogs.com/skynet/p/3343726.html
class ClassA {
public:
	virtual ~ClassA() {};
	virtual void FunctionA() {};
};
class ClassB {
public:
	virtual void FunctionB() {};
};
class ClassC :public ClassA, public ClassB {
public:
};

template<typename T>
void Print(T* a) {
	std::cout << a << std::endl;
}

void testMultiInherit() {
	ClassC Object;
	ClassA* pA = &Object;
	ClassB* pB = &Object;
	ClassC* pC = &Object;

	Print(pA);
	Print(pB);
	Print(pC);
}

int main(){

	return 0;
}