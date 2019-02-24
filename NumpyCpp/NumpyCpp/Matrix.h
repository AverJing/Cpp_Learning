/*
*
*
*@author: Aver Jing
*@description��Nά���飨Matrix�������壬����Matrix_initializer,Matrix_slice,Matrix,Matrix_ref
*@date��
*
*
*/
#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <initializer_list>
#include <array>
#include <cassert>
#include <type_traits>
#include <numeric>
#include "TraitsImpl.h"
#include "MatrixImpl.h"
#include "Random.h"

//�����ʵ�������ж�һ��ģ�����Ϊĳ����
//https://blog.csdn.net/10km/article/details/50845588

template<typename T, size_t N>
struct Matrix_init {
	using type = std::initializer_list<typename Matrix_init<T, N - 1>::type>;
};

template<typename T>
struct Matrix_init<T, 1> {
	using type = std::initializer_list<T>;
};

template<typename T>
struct Matrix_init<T, 0>;									//��������Ϊδ�����

template<typename T, size_t N>
using Matrix_initializer = typename Matrix_init<T, N>::type;

template<size_t N>
struct Matrix_slice {
	Matrix_slice() = default;								//�վ�����Ԫ��
	Matrix_slice(const Matrix_slice<N>&) = default;
	Matrix_slice(Matrix_slice<N>&&) = default;
	
	Matrix_slice(size_t s, std::initializer_list<size_t> exts); //ά�ȴ�С
	Matrix_slice(size_t s, std::initializer_list<size_t> exts, std::initializer_list<size_t> strs);//ά�ȴ�С�Ϳ��

	template<typename... Dims>
	Matrix_slice(Dims... dims);								//N��ά�ȴ�С

	template<typename T>//T = Matrix_initializer<Type, N>
	Matrix_slice(const T& init);

	template<typename... Dims,
		typename = std::enable_if<All(std::is_convertible<Dims, size_t>()...)>>
		size_t operator()(Dims... dims) const;				//��һ���±�������� 
	
	size_t size;											//Ԫ������
	size_t start;											//��ʼƫ����
	std::array<size_t, N> extents;							//ÿ��ά�ȴ�С
	std::array<size_t, N> strides;							//ÿ��ά����Ԫ�ؼ��ƫ����

	//�±���������Ч�����Կ���������1ά��2ά
	/*
	size_t operator()(size_t i) const { return i; }

	size_t operator()(size_t i, size_t i) const { return i*strides[0]+j; }
	*/
private:
	void initStrides() {
		strides[N - 1] = 1;
		for (int i = N - 2, mul = 1; i >= 0; --i) {
			mul *= extents[i + 1];
			strides[i] = mul;
		}
	}

	inline size_t calcSize() {
		return std::accumulate(extents.begin(), extents.end(), 1, std::multiplies<size_t>());
	}
};

template<size_t N>
inline Matrix_slice<N>::Matrix_slice(size_t s, std::initializer_list<size_t> exts)
	:size(s), start(0), extents(exts) {
	initStrides();
} //stridesĬ�ϳ�ʼ��
//��ʱ������������û����֤

template<size_t N>
inline Matrix_slice<N>::Matrix_slice(size_t s, std::initializer_list<size_t> exts, std::initializer_list<size_t> strs)
	: size(s), start(0), extents(exts), strides(strs) {}


template<size_t N>
template<typename T>
inline Matrix_slice<N>::Matrix_slice(const T& init)
{
	Matrix_impl::derive_extents<N>(init, extents);
	size = calcSize();
	start = 0;
	initStrides();
}

template<size_t N>
template<typename ...Dims>
inline Matrix_slice<N>::Matrix_slice(Dims ...dims) :extents{ size_t(dims)... }
{
	static_assert(N == sizeof...(Dims), "dimensions error!");
	size = calcSize();
	initStrides();
	start = 0;
}

template<size_t N>
template<typename ...Dims, typename>
inline size_t Matrix_slice<N>::operator()(Dims ...dims) const
{
	static_assert(sizeof...(Dims) == N, "");

	size_t args[N]{ size_t(dims)... };

	return std::inner_product(args, args + N, strides.begin(), size_t(0));
}

/*
template<typename T, size_t N>
class Matrix_base {

private:
	Matrix_slice<N> desc;
};*/

//���Կ�����Matrix_ref��Matrix�̳���ĳ������
//��ʵ�ֲ�û�п���Matrix_ref���ö����Ƿ���Ч��������ʹ�õ���Ҫȷ��ԭMatrix������Ч��
template<typename T, size_t N>
class Matrix_ref {
public:
	Matrix_ref(const Matrix_slice<N>& s, T* p) :desc(s), ptr(p) {}

	friend std::ostream& operator<<(std::ostream& os, Matrix_ref<T, N>& m) {
		Matrix_impl::pretty_print<N>(os, 1, m.desc, m.ptr, m.desc.start);
		return os;
	}

	Matrix_ref& operator=(const Matrix_initializer<T, N>&);

	T* begin() { return ptr; }
	T* end() { return ptr + desc.size; }
private:
	Matrix_slice<N> desc;
	T* ptr;
};

template<typename T, size_t N>
inline Matrix_ref<T, N> & Matrix_ref<T, N>::operator=(const Matrix_initializer<T, N>& elems)
{
	Matrix_impl::update_ref<N>(1, desc, ptr, elems.begin(), desc.start);
	return *this;
}

template <typename T, size_t N>
class Matrix {
public:
	static constexpr size_t order = N;
	using value_type = T;
	using iterator = typename std::vector<T>::iterator;
	using const_iterator = typename std::vector<T>::const_iterator;

	friend std::ostream& operator<<(std::ostream& os, Matrix<T, N>& m) {
		m.desc.start = 0;//�����ʵ��������ʼλ��
		Matrix_impl::pretty_print<N>(os, 1, m.desc, m.elems, m.desc.start);
		return os;
	}

	Matrix() = default;
	Matrix(Matrix&&) = default;
	Matrix& operator=(Matrix&&) = default;
	Matrix(const Matrix&) = default;
	Matrix& operator=(const Matrix&) = default;
	~Matrix() = default;

	template<typename U>
	Matrix(const Matrix_ref<U, N>&);						//��Matrix_ref����,��ô�����أ��Ǹ�����Ƭ��Ľ�����¹��죿
	template<typename U>
	Matrix& operator=(const Matrix_ref<U, N>&);				//��Matrix_ref��ֵ

	template<typename ...Exts>
	explicit Matrix(Exts... exts);							//ָ��ÿһά��С

	template<typename... Dims>
	explicit Matrix(const slice& s, Dims... dims);

	Matrix(const Matrix_initializer<T, N>&);				//�б��ʼ��
	Matrix& operator=(const Matrix_initializer<T, N>&);		//�б�ֵ

	template<typename U>
	Matrix(std::initializer_list<U>) = delete;				//��Ԫ���ⲻʹ��{}
	template<typename U>
	Matrix& operator=(std::initializer_list<U>) = delete;
	 
	//static constexpr size_t orders() { return N; }			//ά��
	size_t extent(size_t n) const { return desc.extents[n]; }//��nάԪ����
	size_t size() const { return elems.size(); }			//Ԫ������
	const Matrix_slice<N>& descriptor() const { return desc; }//�����±��������Ƭ

	T* data() { return elems.data(); }						//Ԫ�ط���
	const T* data() const { return elems.data(); }

	template<typename... Args>								//m(i,j,k)�����������±����
	typename std::enable_if<Requesting_element<Args...>(), T&>::type
		operator()(Args... args);
	template<typename... Args>								//m(i,j,k)�����������±����
	typename std::enable_if<Requesting_element<Args...>(), const T&>::type
		operator()(Args... args) const;

	template<typename... Args>								//m(s1,s2,s3)����Ƭ�����±����
	typename std::enable_if<Requesting_slice<Args...>(), Matrix_ref<T, N>>::type
		operator()(const Args&... args);
	template<typename... Args>
	typename std::enable_if<Requesting_slice<Args...>(), Matrix_ref<const T, N>>::type
		operator()(const Args&... args) const;

	Matrix_ref<T, N - 1> operator[](size_t i)				//��m[i]�з���
	{
		return row(i);
	}
	Matrix_ref<const T, N - 1> operator[](size_t i)const
	{
		return row(i);
	}

	//Matrix_ref<T, N - 1> row(size_t n);						//�з���
	//Matrix_ref<const T, N - 1> row(size_t n) const;

	//���Ƿ���Matrix<T,1>��
	//����������������дһ��struct��ƫ�ػ������ڿ����ˣ�����
	//Ȼ����д������redirect���Ǹ�struct��static�������棬������
	//���Ƿ���ֵ�أ���  ���Կ����ú��÷������͡���
	//T& Matrix<T, 1>::row(size_t n) { return &elems[n]; }
	//T& Matrix<T, 0>::row(size_t n) = delete;

	//��ά���趨��  ҳ+��+�У������ά�����У�
	size_t rows() { return N == 1 ? 1 : desc.extents[desc.extents.size() - 2]; }

	template<size_t M = N>
	struct Row {
		static Matrix_ref<T, N - 1> row(size_t n) {
			//undefined
			assert(n < rows());
			Matrix_slice<N - 1> row;
			Matrix_impl::slice_dim<0>(n, desc, row);
			return { row, data() };
		}
	};
	template<>
	struct Row<1> {
		static T& row(size_t n) { return elems[n]; }
		//error
		//https://docs.microsoft.com/zh-cn/cpp/error-messages/compiler-errors-1/compiler-error-c2272?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev15.query%3FappId%3DDev15IDEF1%26l%3DZH-CN%26k%3Dk(C2272)%26rd%3Dtrue&view=vs-2017
		//static T& row(size_t n) const { return elems[n]; }
	};
	template<>
	struct Row<0> {
		static T& row(size_t n) = delete;
	};

	auto row(size_t n) -> decltype(Row<N>::row(n)) {
		return Row<N>::row(n);
	}

	//Matrix_ref<T, N - 1> colomn(size_t n);					//�з���
	//Matrix_ref<const T, N - 1> colomn(size_t n) const;

	template<typename F>
	Matrix& apply(F f);										//��ÿ��Ԫ��xִ��f(x)
	template<typename M, typename F>
	Matrix& apply(const M& m, F f);							//���ض�Ԫ��ִ��f(x,mx)

	auto begin()  { return elems.begin(); }
	auto end() { return elems.end(); }

	//Matrix& operator=(const T& value);						//�ñ�����ֵ
	//
	Matrix& operator+=(const T& value);							//������
	Matrix& operator-=(const T& value);							//������
	Matrix& operator*=(const T& value);							//������
	Matrix& operator/=(const T& value);							//������

	//
	template<typename M>
	Matrix& operator+=(const M& m);							//�����
	template<typename M>
	Matrix& operator-=(const M& m);							//�����

	//���ж�Ԫ+��-��*��/���㶨��Ϊ�ǳ�Ա����

	//undefined
	template<typename M>//std::enable_if<Matrix_type<M>(), Matrix<T, N>&>::type
	Matrix<T, N>& operator+=(const M&);
	
	void ReconstructByRandom(T start, T end) {
		for (auto &e : elems)
			e = randomArithmetic<T>(start, end);
	}
private:
	Matrix_slice<N> desc;									//ʵ��N��ά�ȴ�С����Ƭ
	std::vector<T> elems;									//Ԫ��
};

//��Ԫ�������ǳ�Ա����
template<typename T, size_t N>
Matrix<T, N> operator+(const Matrix<T, N>& m, const T& val) {
	Matrix<T, N> res = m;
	res += val;
	return res;
	//���û���ƶ����캯�����˴�������������ȱ�ݡ�
}

template<typename T, size_t N>
Matrix<T, N> operator+(const Matrix<T, N>& lhs, const Matrix<T, N>& rhs) {
	Matrix<T, N> res = lhs;
	res += rhs;
	return res;
	//���û���ƶ����캯�����˴�������������ȱ�ݡ�
}

template<typename T, typename T2, size_t N, typename RT = Matrix<Common_type<Value_type<T>, Value_type<T2>>, N>>
Matrix<RT, N> operator+(const Matrix<T, N>& lhs, const Matrix<T2, N>& rhs) {
	Matrix<RT, N> res = lhs;
	res += rhs;
	return res;
}

template<typename T, size_t N>
Matrix<T, N> operator+(const Matrix_ref<T, N>& lhs, const T& n) {
	Matrix<T, N> res = lhs;
	res += n;
	return res;
}

//N*1��1*M���
template<typename T>
Matrix<T, 2> operator*(const Matrix<T, 1>& lhs, const Matrix<T, 1>& rhs) {
	const size_t n = lhs.extent(0);
	const size_t m = rhs.extent(0);
	Matrix<T, 2> res(n, m);
	for (size_t i = 0; i != n; ++i)
		for (size_t j = 0; j != m; ++j)
			res(i, j) = lhs[i] * rhs[j];
	return res;
}

//N*M��M*1���
template<typename T>
Matrix<T, 2> operator*(const Matrix<T, 2>& lhs, const Matrix<T, 1>& rhs) {
	assert(lhs.extent(1) == rhs.extent(0));

	const size_t n = lhs.extent(0);
	Matrix<T, 1> res(n);
	for (size_t i = 0; i != n; ++i)
		for (size_t j = 0; j != n; ++j)
			res(i) += lhs(i, j) * rhs(j);
	return res;
}

//N*M��M*P���
template<typename T>
Matrix<T, 2> operator*(const Matrix<T, 2>& lhs, const Matrix<T, 2>& rhs) {
	const size_t n = lhs.extent(0);
	const size_t m = lhs.extent(1);
	assert(m == rhs.extent(0));

	const size_t p = rhs.extent(1);
	Matrix<T, 2> res(n, p);
	for (size_t i = 0; i != n; ++i)
		for (size_t j = 0; j != p; ++j)
			for (size_t k = 0; k != m; ++k)
				res(i, j) += lhs(i, k) * rhs(k, j);
	return res;

	//������
	//res(i,j)=dot_product(lhs[i], rhs.column(j));
}

/*
template<typename T>
T dot_product(const Matrix<T,1>& a, const Matrix<T,1>& b){
	return std::inner_product(a.begin(),a.end(),b.begin(), 0.0);
}
*/

template<typename T, size_t N>
template<typename U>
inline Matrix<T, N>::Matrix(const Matrix_ref<U, N>& x)
	:desc(x.desc), elems{ x.begin(), x.end() }				//����desc��Ԫ��		
{
	static_assert(std::is_convertible<U, T>(), "Matrix constructor:incompatible element types");
}

template<typename T, size_t N>
template<typename U>
inline Matrix<T, N> & Matrix<T, N>::operator=(const Matrix_ref<U, N>& x)
{
	static_assert(std::is_convertible<U, T>(), "Matrix =:incompatible element types");

	desc = x.desc;
	elems.assign(x.begin(), x.end());
	return *this;
}

template<typename T, size_t N>
template<typename... Exts>
inline Matrix<T, N>::Matrix(Exts... exts)
	:desc(exts...),											//����ά�ȴ�С
	elems(desc.size)										//����size��Ԫ�أ��������ǽ���Ĭ�ϳ�ʼ��
{}

template<typename T, size_t N>
template<typename... Exts>
inline Matrix<T, N>::Matrix(const slice& s, Exts... exts)
	:desc(exts...),											//����ά�ȴ�С
	elems(desc.size)										//����size��Ԫ�أ��������ǽ���Ĭ�ϳ�ʼ��
{
	assert(s.length == desc.size, "elements length error");
	for (auto i = 0; i < elems.size(); ++i) {
		elems[i] = s.start + i * s.stride;
	}
}

template<typename T, size_t N>
template<typename ...Args>
inline typename std::enable_if<Requesting_element<Args...>(), T&>::type Matrix<T, N>::operator()(Args ...args)
{
	static_assert(N == sizeof...(Args), "dimension error");
	auto len = desc.operator()(args...);					//������Ƭʵ�ַ���
	assert(len < size(), "index error!");
	return elems[len];
}

template<typename T, size_t N>
template<typename ...Args>
inline typename std::enable_if<Requesting_element<Args...>(), const T&>::type Matrix<T, N>::operator()(Args ...args) const
{
	static_assert(N == sizeof...(Args), "dimension error");
	auto len = desc.operator()(args...);					//������Ƭʵ�ַ���
	assert(len < size, "index error!");
	return elems[len];
}

template<typename T, size_t N>
template<typename ...Args>
inline typename std::enable_if<Requesting_slice<Args...>(), Matrix_ref<T, N>>::type Matrix<T, N>::operator()(const Args & ...args)
{
	Matrix_slice<N> d(desc);
	d.start = Matrix_impl::do_slice<sizeof...(Args)>(desc, d, args...);
	d.size = desc.size;
	return { d, data() };
}

template<typename T, size_t N>
template<typename ...Args>
inline typename std::enable_if<Requesting_slice<Args...>(), Matrix_ref<const T, N>>::type Matrix<T, N>::operator()(const Args & ...args) const
{
	Matrix_slice<N> d(desc);
	d.start = Matrix_impl::do_slice<sizeof...(Args)>(desc, d, args...);
	d.size = desc.size;
	return { d, data() };
}

template<typename T, size_t N>
inline Matrix<T, N>::Matrix(const Matrix_initializer<T, N>& init):desc(init)
{
	//Matrix_impl::derive_extents<N>(init, desc.extents);		//�ӳ�ʼ���б����ƶϳ�ά�ȴ�С
	elems.reserve(desc.size);								//Ϊ��Ƭ�����ռ�
	Matrix_impl::insert_flat(init, elems);					//�ó�ʼ���б���г�ʼ��
	assert(elems.size() == desc.size);
}

template<typename T, size_t N>
inline Matrix<T, N>& Matrix<T, N>::operator=(const Matrix_initializer<T, N>& init)
{
	//Matrix_impl::derive_extents<N>(init, desc.extents);		//�ӳ�ʼ���б����ƶϳ�ά�ȴ�С
	
	elems.reserve(desc.size);								//Ϊ��Ƭ�����ռ�
	Matrix_impl::insert_flat(init, elems);					//�ó�ʼ���б���г�ʼ��
	assert(elems.size() == desc.size);
	return *this;
}

template<typename T, size_t N>
inline Matrix<T, N> & Matrix<T, N>::operator+=(const T & value)
{
	return apply([&](T& a) {a += value; });
}

template<typename T, size_t N>
inline Matrix<T, N>& Matrix<T, N>::operator-=(const T & value)
{
	return apply([&](T& a) {a -= value; });
}

template<typename T, size_t N>
inline Matrix<T, N> & Matrix<T, N>::operator*=(const T & value)
{
	return apply([&](T& a) {a *= value; });
}

template<typename T, size_t N>
inline Matrix<T, N> & Matrix<T, N>::operator/=(const T & value)
{
	assert(value != 0, "divide zero");
	return apply([&](T& a) {a /= value; });
}

template<typename T, size_t N>
template<typename F>
inline Matrix<T, N>& Matrix<T, N>::apply(F f)
{
	for (auto& x : elems) f(x);
	return *this;
}

template<typename T, size_t N>
template<typename M, typename F>
inline Matrix<T, N> & Matrix<T, N>::apply(const M & m, F f)
{
	assert(desc.extents == m.descriptor().extents);
	for (auto i = begin(), j = m.begin(); i != end(); ++i, ++j) {
		f(*i, *j);
	}
	return *this;
}

template<typename T, size_t N>
template<typename M>//enable_if<Matrix_type<M>() �ȵȿ���ʵ��
inline Matrix<T, N>& Matrix<T, N>::operator+=(const M &m)
{
	static_assert(m.order() == N, "+=: mismatched Matrix dimensions");
	assert(desc.extents == m.descriptor().extents);			//ȷ����Сƥ��

	return apply(m, [](T& a, Value_type<M>& b) {a += b; });
}

template<typename T, size_t N>
template<typename M>
inline Matrix<T, N>& Matrix<T, N>::operator-=(const M & m)
{
	static_assert(m.order() == N, "+=: mismatched Matrix dimensions");
	assert(desc.extents == m.descriptor().extents);			//ȷ����Сƥ��

	return apply(m, [](T& a, Value_type<M>& b) {a -= b; });
}

//�������ʵ�֣���ô���ظ���ֵһ�Ρ�
template<typename T, size_t N, typename... Args>
Matrix<T, N> randomMatrix(T s, T e, Args... args) {
	Matrix<T, N> tmp(args...);	
	tmp.ReconstructByRandom(s, e);
	return tmp;
}//���ƶ����죬��Ҫ��ʵ�������ο�������

template<typename T, size_t N, typename... Args>
Matrix<T, sizeof...(Args)> reshape(const slice& s, Args... args) {
	Matrix<T, sizeof...(Args)> tmp(s,args...);
	return tmp;
}//���ƶ����죬��Ҫ��ʵ�������ο�������

#endif // MATRIX_H