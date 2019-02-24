/*
*
*
*@author: Aver Jing
*@description：测试程序
*@date：
*
*
*/
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "Matrix.h"
#include "Random.h"
/*
template<size_t N>
struct Test {
	template<size_t M = N>
	struct Print {
		static void print() {
			std::cout << "others" << std::endl;
		}
		static void print() const{
			std::cout << "others" << std::endl;
		}
	};
	template<>
	struct Print<1> {
		static int print() {
			std::cout << "111111111" << std::endl;
			return 1111;
		}
	};

	auto print() -> decltype(Print<N>::print()) {
		return Print<N>::print();
	}
};

void test() {

	//std::cout << Test<1>().print() << std::endl;
	//Test<3>().print();
}*/

//static int sum = 1;
//template<typename... Args>
//void hello(Args... args) {
//	//std::cout << sizeof...(Args) << std::endl;
//	//std::initializer_list<size_t> tmp{ size_t(args)... };
//	std::array<size_t, sizeof...(Args)> tmp{ size_t(args)... };
//	std::cout << std::accumulate(tmp.begin(),tmp.end(), 1, std::multiplies<size_t>()) << std::endl;	
//}

//template<typename... Args>
//bool test(Args... args) {
//	return All(std::is_convertible<Args, size_t>()...);
//}

//template<size_t N>
//typename std::enable_if<(N>0), void>::type add_extents() {
//	if(N>1)
//		std::cout << "2222" << std::endl;
//	if(N==1)
//		std::cout << "1111" << std::endl;
//}
//
//auto hello(const std::vector<int>& s) {
//	return s.begin();
//}

//非模板参数的模板函数的递归
//注意函数模板没有参数部分具体化，因为函数可以重载。
//template<size_t N>
//void add() {
//	std::cout << "2222" << std::endl;
//	add<N - 1>();
//}
//
//template<>
//void add<1>() {
//	std::cout << "1111" << std::endl;
//}

//没问题，为什么Matrix_slice报错呢？
//template<size_t N>
//struct TestMultiPara {
//	template<typename... Args>
//	TestMultiPara(Args... args) {
//		std::cout << sizeof...(Args) << std::endl;
//	}
//};

template<typename... Args>
void print(Args... args) {
	std::cout << sizeof...(Args) << std::endl;
}

template<typename... Args>
void print(const slice& s, Args... args) {
	std::cout << sizeof...(Args) + 1 << std::endl;
}

int main(int argc, char* argv[])
{
	/*xt::xarray<int> arr
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	arr.reshape({ 3, 3 });
	xt::view_type testView = xt::view(arr, 1, 1);

	std::cout << arr << std::endl;;
	std::cout << testView;*/
	
	//hello(1, 2, 3, 4, 5);

	//std::cout << test(1, 1, 1, 1, 1, 1, 1);

	//add_extents<1>();

	/*Matrix_initializer<int, 2> type = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	Matrix<int, 2> tmp(type);

	auto shapeTest = reshape<int, 2>(slice(1, 10), 2, 5);
	std::cout << shapeTest;*/

	/*auto randomM1 = randomMatrix<double, 2>(0, 10, 2, 2);

	std::cout << randomM1;*/
	
	//std::cout << tmp(2, 2);
	//tmp += 1;
	//std::cout << tmp;

	/*auto m20 = tmp(slice(1, 2));
	m20 = {
		{10,11,12},
		{13,14,15}
	};

	std::cout << tmp;*/

	//Matrix_initializer<int, 3> type2 = 
	//{
	//	{
	//		{1,2,3},
	//		{4,5,6},
	//		{7,8,9}
	//	},

	//	{
	//		{10,11,12},
	//		{13,14,15},
	//		{16,17,18}
	//	}
	//};

	//Matrix<int, 3> tmp2(type2);

	////std::cout << tmp2;
	//auto m30 = tmp2(slice(0, 1), slice(0, 3), slice(1,1));
	//std::cout << m30 << std::endl;

	/*for (int i = 0; i < 10; ++i)
		std::cout << randomArithmetic<int>(0, 10) << ' ';
	std::cout << "\n";
	for (int i = 0; i < 10; ++i)
		std::cout << randomArithmetic<double>(0, 1) << ' ';*/
	return 0;
}