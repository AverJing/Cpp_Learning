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
/*
struct MyBase
{
	 static virtual void Print() { std::cout << '1' << std::endl; }
};

struct MySon : public MyBase
{

};
*/

//test size of static member class
struct MyTest {
	constexpr static int i = 10;
	int j;
	static MyTest my;
	MyTest* p;
};

constexpr int MyTest::i;

int main(){
	//MySon::Print();
	
	std::cout << sizeof(MyTest::my);  //涉及到内存对齐的问题
}	