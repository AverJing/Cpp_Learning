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
#include <initializer_list>
#include <array>

using Arr = std::array<int, 10>;

template<typename _Tp, std::size_t _Nm>
struct _array_traits {
	using _Type = _Tp[_Nm];
	//typedef  _Tp _Type[_Nm];
};

int main(){
	typename _array_traits<int, 10>::_Type hello;
}	