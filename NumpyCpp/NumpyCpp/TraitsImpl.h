/*
*
*
*@author: Aver Jing
*@description��traits�������ڱ�������֤���Ͱ�ȫ
*@date��
*
*
*/
#pragma once

struct slice {
	slice() :start(-1), length(-1), stride(1) {}
	explicit slice(size_t s) :start(s), length(-1), stride(1) {}
	slice(size_t s, size_t l, size_t n = 1) :start(s), length(l), stride(n) {}

	size_t operator()(size_t i)const { return start + i * stride; }

	static slice all;

	size_t start;											//��һ������
	size_t length;											//������������Ŀ(�����ڷ�Χ���)
	size_t stride;											//������Ԫ�ؼ�ľ���
};

//ע���������
//https://docs.microsoft.com/zh-cn/cpp/cpp/conditional-operator-q?view=vs-2017
//��Ŀ�������������������������������ͣ���ִ������ת����������ת��Ϊͨ�����͡�
template<typename... V>
struct common_type;

template<typename T>
struct common_type<T> {
	using type = T;
};

template<typename T, typename U>
struct common_type<T, U> {
	using type = decltype(true ? std::declval<T>() : std::declval<U>());
};


template<typename T, typename U, typename... V>
struct common_type<T, U, V...> {
	using type = typename common_type<typename common_type<T, U>::type, V...>::type;
};

template<typename T, typename U>
using Common_type = typename common_type<T, U>::type;

template <bool B, typename T = void>
struct value_type {
	using type = T;
};

template<typename T>
struct value_type<false, T> {};

template<typename T>
using Value_type = typename value_type<std::is_arithmetic<T>::value, T>::type;

constexpr bool All() {
	return true;
}

template<typename ... Args>
constexpr bool All(bool b, Args... args) {
	return b && All(args...);
}

//����д�������ԣ����˸о��ڶ��ָ���
//template<typename... Args>
//constexpr bool Requesting_element() {
//	return All(std::is_convertible<Args, size_t>()...);
//}//ע��is_convertible��������ת��Ϊbool�ĳ�Ա����

template<typename... Args>
constexpr bool Requesting_element() {
	return All(std::is_convertible<Args, size_t>::value...);
}//ע��is_convertible��������ת��Ϊbool�ĳ�Ա����

//template<typename... Args>
//constexpr bool Requesting_element() {
//	return All(std::is_convertible<Args, size_t>()()...);
//}//ע��is_convertible��������ת��Ϊbool�ĳ�Ա����

constexpr bool Some() {
	return false;
}

template<typename... Args>
constexpr bool Some(bool b, Args... args) {
	return b || Some(args...);
}

template<typename... Args>
constexpr bool Requesting_slice() {
	return All((std::is_convertible<Args, size_t>() || std::is_same<Args, slice>())...) && Some(std::is_same<Args, slice>()...);
}


