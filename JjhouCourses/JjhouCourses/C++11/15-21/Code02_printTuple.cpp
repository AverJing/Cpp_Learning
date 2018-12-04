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
#include <tuple>

//为什么出错？？？
/*
template<int n, int MAX, typename... Args>
void print_tuple(const std::tuple<Args...>& t) {	
	std::cout << std::get<n>(t) << (n + 1 == MAX ? "" : " ");
	if (n + 1 == MAX) return;
	print_tuple<n + 1, MAX, Args...>(t);
}

template<typename... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) {
	os << "[";
	print_tuple<1, sizeof...(Args), Args...>(t);
	return os << "]";
}*/
template<int n, int MAX, typename... Args>
struct print;

template<int MAX, typename... Args>
struct print<MAX, MAX, Args...> {
	static void print_tuple(const std::tuple<Args...>& t) {
	}
};

template<int n, int MAX, typename... Args>
struct print {
	static void print_tuple(const std::tuple<Args...>& t) {
		std::cout << std::get<n>(t) << (n + 1 == MAX ? "" : " ");
		print<n + 1, MAX, Args...>::print_tuple(t);
	}
};

template<typename... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) {
	os << "[";
	print<0, sizeof...(Args), Args...>::print_tuple(t);
	return os << "]";
}


//为什么出错？？？
//非模板类型参数  它的初始化是在编译期
//而函数是在运行期
//猜测。
//https://stackoverflow.com/questions/13820782/calling-templated-function-recursively-c
template<int N>
void getN() {
	if (N == 10)return;
	if (N < 10) {
		std::cout << N << ' ';
	}		
	getN<N + 1>();
}

template<int N>
struct test;

template<>
struct test<10> {
	static void print() {
	}
};

template<int N>
struct test {
	static void print() {
		//注意模板的使用
		//它的递归结束条件是特化版本决定的
		//而不是函数中的终止条件
		//if (N == 10)return;
		std::cout << N << ' ';
		test<N + 1>::print();
	}
};

void getN(int n) {
	if (n == 10) return;
	if (n < 10) {
		std::cout << n << ' ';
	}		
	getN(n+1);
}

int main(){
	std::cout << std::make_tuple("hello", " world.", 20181119, 3.1415926);
	//getN<0>();
	//test<0>::print();
}	