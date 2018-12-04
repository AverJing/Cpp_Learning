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
#include <vector>
#include <iterator>
#include <string>
#include <deque>
#include <map>
#include <set>

template<class Container>
struct temTemPara {
	using _Type = Container::value_type;
};

template<class Container>
struct temTemPara_2 {
	using _Type = std::iterator_traits<typename Container::iterator>::value_type;
};

template<typename T, template<class> class Container>
struct temTemPara_3 {
	Container<T> c;
	using _Type = T;
};

//can not declare in function body
template<typename T>
	using Vec = std::vector<T, std::allocator<T>>;


int main(){
	std::vector<int>::value_type k1;
	std::string::value_type k2;
	std::deque<int>::value_type k3;
	std::map<int,int>::value_type k4;
	std::set<int>::value_type k5;

	temTemPara_2<std::vector<int>>::_Type k6;

	//temTemPara_3<int, std::vector<int>>::_Type k6;
	//Alias templates are never deduced by template argument deduction
	//when deducing a template template parameter

	temTemPara_3<int, Vec>::_Type k6;
}	