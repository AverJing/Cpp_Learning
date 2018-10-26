/*
*
*
*@author: Aver Jing
*@description：
*
*Placement new is a variation new operator in C++. Normal new operator does two things : 
*(1) Allocates memory (2) Constructs an object in allocated memory.
*
*Placement new allows us to separate above two things. 
*In placement new, we can pass a preallocated memory and construct an object 
*in the passed memory.
*
*source: https://www.geeksforgeeks.org/placement-new-operator-cpp/
*@date：Oct 14, 2018
*
*
*/
//上边介绍了 placement new 和new 的区别在于： new既分配内存还构造对象
//placement new可以把两个过程分离
//拓展：是否可以用allocator实现

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

void testPlacementNew() {
	// buffer on stack 
	//Attention： note this usage， allocate sizeof(int) * 2 to storage two int numbers
	//注意此处申请了sizeof(int) * 2 用来保存两个整数
	unsigned char buf[sizeof(int) * 2];

	cout << "sizeof buf :" << sizeof(buf) << endl;

	// placement new in buf 
	//可以用栈分配的空间，也可以用堆分配的空间
	int *pInt = new (buf) int(3);

	int *qInt = new (buf + sizeof(int)) int(5);
	int *pBuf = (int*)(buf + 0);
	int *qBuf = (int*)(buf + sizeof(int));
	cout << "Buff Addr             Int Addr" << endl;
	cout << pBuf << "             " << pInt << endl;
	cout << qBuf << "             " << qInt << endl;
	cout << "------------------------------" << endl;
	cout << "1st Int             2nd Int" << endl;
	cout << *pBuf << "                         "
		<< *qBuf << endl;
}

class Test {
public:
	Test() { cout << "call Test constructor" << endl; }
};

int main(){
	//testPlacementNew();
	//Test test[100];

	/*
	unsigned char data[sizeof(Test) * 5];

	auto placeNew = new (data)Test();*/
	//使用placement new 就是为了分配和构造分离
	//使用allocate同样可以

	std::allocator<Test> t1;
	auto p = t1.allocate(5);
	t1.construct(p);
	t1.construct(p + 1);
	t1.destroy(p + 1);
	t1.destroy(p);
	t1.deallocate(p, 5);
}	