/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

//测试标准库string   如果采用写时拷贝会出现下边的问题
#include <iostream>
#include <string>

using std::string;

/**/
//copy on write
void test_string_COW() {
	string a = "hello world.";
	string b = a;
	auto result = a.data() == b.data();

	std::cout << result << std::endl;

	b.append("A");

	result = a.data() == b.data();
	std::cout << result << std::endl;
}

int main(){
	/*
	string s1("hello");

	auto p = &s1[2];

	string s2 = s1;

	*p = 'x';

	std::cout << s1 << ' ' << s2 << std::endl;*/
	//VC++  string没有采用引用计数？
	//是的，并没有采用引用计数
	//而是采用了 SSO， small string optimization，
	//足够小的字符串直接放在对象本身的栈内存中，避免了向Heap动态请求内存的开销

	//SSO对小字符串的高效是原因之一（程序中通常会有大量的短字符串），而COW本身的缺陷更是原因之一。


	//C++ 11 std::move的引入，也使得这种COW优化不再必要
	test_string_COW();
}	