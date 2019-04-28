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
#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include <memory>

using namespace std::chrono_literals;

std::mutex m;

void f(int n) {
	std::unique_lock<std::mutex> lck{ m };//获取m
	std::cout << n << std::endl;
}

/*
由于使用的是detch函数，新线程与主线程分离，在detch函数执行完成，主线程main函数结束，
my_thread对象销毁，还未执行一次打印线程也就结束了，这才造成这样的结果。
下面我们加上Sleep(1);这句话，观察结果，验证我们的说法。
*/

void doit(const std::shared_ptr<int>& t) {
	std::cout << "hello world!" << std::endl;
}

void testBind() {
	std::shared_ptr<int> i_ptr(std::make_shared<int>(10));
	auto test = std::bind(&doit, i_ptr);
	test();
	std::cout << i_ptr.use_count() << std::endl;
	//cout  2
	//注意，bind会拷贝参数，这回导致shared_ptr引用增加
	//如果要避免拷贝，使用std::ref
}

struct Foo {
	void Print(int i) {
		std::cout << i << std::endl;
	}
};

void testBindByClass() {
	Foo t;
	auto test = std::bind(&Foo::Print, &t, 10);
	//注意，当访问类成员函数时，要给出this指针
	test();
}
int main(){
	//for (int i = 0; i < 4; ++i) {
	//	std::thread t(f, i);
	//	std::this_thread::sleep_for(1s);//原因看上边
	//	t.detach();
	//}
	//testBind();
	
	return 0;
}