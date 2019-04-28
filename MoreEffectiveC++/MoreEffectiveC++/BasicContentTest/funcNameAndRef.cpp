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

void print() {
	std::cout << "hello\n";
}

template<class T>
void fun(T t1) {
	t1();
}
//https://www.zhihu.com/question/293674445

template<bool Const, typename Class, typename RetType, typename... ArgsTypes>
struct TMemFunPtrType;

template<typename Class, typename RetType, typename... ArgsTypes>
struct TMemFunPtrType<false, Class, RetType(ArgsTypes...)> {
	typedef RetType(Class::* Type)(ArgsTypes...);
};

template<typename Class, typename RetType, typename... ArgsTypes>
struct TMemFunPtrType<true, Class, RetType(ArgsTypes...)> {
	typedef RetType(Class::* Type)(ArgsTypes...) const;
};

struct Test {
	void Print() {
		std::cout << "hello class\n";
	}
};

int main(){
	/*auto p1 = print;
	auto p2 = &print;
	fun(print);
	fun(&print);*/

	typedef void (Test:: * fun)();
	//using fun = void (Test::*)();
	//or typedef void (test::*fun)();
	//fun f = Test::Print; //error
	//https://www.zhihu.com/question/27738023
	fun f2 = &Test::Print;

	Test t;
	//(t.*f)();
	(t.*f2)();

	TMemFunPtrType<false, Test, void(void)>::Type f3 = &Test::Print;
	(t.*f3)();

	return 0;
}