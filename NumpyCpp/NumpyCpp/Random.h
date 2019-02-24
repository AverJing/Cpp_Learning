/*
*
*
*@author: Aver Jing
*@description：随机值生成
*@date：
*
*
*/
#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
#include <cassert>

static unsigned int seed = std::time(0);
using std::string;

//采用的均匀分布实现的

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type randomArithmetic(T start, T end) {
	std::uniform_int_distribution<T> u(start, end);//闭区间
	std::default_random_engine e(++seed);
	
	return u(e);
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type randomArithmetic(T start, T end) {
	std::uniform_real_distribution<T> u(start, end);//闭区间
	std::default_random_engine e(++seed);

	return u(e);
}

//产生长度为0到size的字符串
void randomString(int size, string& data) {
	std::uniform_int_distribution<unsigned> u(0, size);//闭区间
	std::default_random_engine e(++seed);
	data.resize(u(e), ' ');

	std::uniform_int_distribution<unsigned> u2('a', 'z');//闭区间
	for (auto& p : data)
		p = u2(e);
}
