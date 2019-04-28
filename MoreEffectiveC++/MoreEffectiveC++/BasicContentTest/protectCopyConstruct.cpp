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

struct Test {
	Test() = default;
protected:
	Test(const Test&) {}
};

int main(){
	Test a;
	Test b(a);

	return 0;
}