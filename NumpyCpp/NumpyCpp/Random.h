/*
*
*
*@author: Aver Jing
*@description�����ֵ����
*@date��
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

//���õľ��ȷֲ�ʵ�ֵ�

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type randomArithmetic(T start, T end) {
	std::uniform_int_distribution<T> u(start, end);//������
	std::default_random_engine e(++seed);
	
	return u(e);
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type randomArithmetic(T start, T end) {
	std::uniform_real_distribution<T> u(start, end);//������
	std::default_random_engine e(++seed);

	return u(e);
}

//��������Ϊ0��size���ַ���
void randomString(int size, string& data) {
	std::uniform_int_distribution<unsigned> u(0, size);//������
	std::default_random_engine e(++seed);
	data.resize(u(e), ' ');

	std::uniform_int_distribution<unsigned> u2('a', 'z');//������
	for (auto& p : data)
		p = u2(e);
}
