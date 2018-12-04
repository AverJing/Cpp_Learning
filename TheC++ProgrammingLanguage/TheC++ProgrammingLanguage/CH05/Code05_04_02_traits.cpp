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
#include <type_traits>
#include <vector>
#include <iterator>
#include <algorithm>
#include <forward_list>

//简单实现以下如何判断类型是不是int
template<typename T>
struct IS_INT {
	constexpr bool operator()() {
		return false;
	}
	constexpr operator bool() const noexcept {
		return true;
	}
};

template<>
struct IS_INT<int> {
	constexpr bool operator()() {
		return true;
	}
	constexpr operator bool() const noexcept{
		return true;
	}
};

template <typename T>
void sort_helper(T& t, std::random_access_iterator_tag) {
	std::sort(t.begin(), t.end());
}

template <typename T>
void sort_helper(T& t, std::forward_iterator_tag) {
	std::vector<T::value_type> tmp(t.begin(), t.end());
	std::sort(tmp.begin(), tmp.end());
	std::copy(tmp.begin(), tmp.end(), t.begin());
}

template<typename T>
using iter = T::iterator;

template <typename T>
using Category = typename std::iterator_traits<T>::iterator_category;

template <typename T>
void sort(T& t) {	
	sort_helper(t, Category<T::iterator>());
}

void test() {
	bool t1 = IS_INT<int>(); //之所以可以这样用是因为重载了类型转换
	bool t2 = std::is_arithmetic<int>();

	std::cout << t1 << ' ' << t2;
}

int main(){
	test();
}	