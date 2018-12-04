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
#include <memory>
#include <string>

using std::cout;
using std::endl;

//如何看到具体的执行过程？
//我只找到了声明。
//我觉得有很多东西是在编译时执行的。 可能有些已经提前编译好了，直接运行的，所以可能看不到源代码。
//从网上学习
void test() {
	void* p1 = malloc(512);
	free(p1);

	int* p2 = new int(512);
	new(p2)int(100);  //placement new 需要先把内存分配好，再调用构造函数。
	//再建立数组时，特别有用。
	std::cout << *p2 << endl;
	delete p2;

	auto p3 = ::operator new(512);
	::operator delete(p3);

	auto p4 = std::allocator<int>().allocate(5);
	std::allocator<int>().deallocate(p4, 5);
}

void testSize() {
	std::cout << sizeof(std::string) << std::endl;//40 ？？ 内容太多，没找到成员。。
	std::cout << sizeof(void*) << std::endl;//8
	std::cout << sizeof(std::shared_ptr<int>) << std::endl;//16
	//shared_ptr包括两个指针
	//private:
	//element_type * _Ptr{nullptr};
	//_Ref_count_base * _Rep{ nullptr };   引用计数
	std::cout << sizeof(std::shared_ptr<float>) << std::endl;//16
	std::cout << sizeof(int*) << std::endl;//8
}

void testPara() {
	//默认和8对齐，大小是8的整数倍
	struct {
		char a;
		double b;
	}mystruct;

	std::cout << sizeof mystruct << std::endl;
	std::cout << (int*)&mystruct.a << std::endl;
	std::cout << &mystruct.b << std::endl;
	//数据对齐
#pragma pack(4)//注意设置之后，在分配内存
	struct {
		char a;
		double b;
	}mystruct2;

	std::cout << sizeof mystruct2 << std::endl;
	std::cout << (int*)&mystruct2.a << std::endl;
	std::cout << &mystruct2.b << std::endl;

	//第一个例子时，最小值为8，填充7个字节到char a 之后。
	//第二个例子时，最小值为4，填充3个字节到char a之后。

#pragma pack(4)
	//整体对齐
	/*
	 如果数据对齐完成时struct的大小不是 struct内成员自身长度最大值（sizeof） 
	 与 #pragma pack(n)中的n的最小值的整数倍。
	 （注意这里是成员中长度最大的那个与n比较，而不是特定的一个成员。）
	 当设置n为4也就是min（sizeof(short), n） = 2
	*/
	struct {
		char a;
		short b;
		char c;
	} myStruct;
	cout << sizeof myStruct << endl;  // 6
	cout << (int *)&myStruct.a << endl;  
	cout << &myStruct.b << endl;  
	cout << (int *)&myStruct.c << endl;  

}

int main(){
	test();
	//testSize();
	//testPara();

	struct {
		char a;
		short b;
		char c;
	} myStruct;
	cout << sizeof myStruct << endl;  // 6
	cout << (void *)&myStruct.a << endl;
	cout << &myStruct.b << endl;
	cout << (void *)&myStruct.c << endl;
}	