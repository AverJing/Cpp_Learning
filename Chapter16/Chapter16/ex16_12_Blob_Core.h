/*
*
*
*@author: Aver Jing
*@description： a part of ex16_12_Blob
*@date：
*
*
*/
#pragma once

#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

using std::vector;
using std::shared_ptr;
using std::string;
using std::initializer_list;

template<typename> class Blob_Core;
template<typename> class BlobPtr_Core;

template<typename T> class Blob_Core {
public:
	friend class BlobPtr_Core<T>;
	typedef T value_type;
	typedef typename vector<T>::size_type size_type; // do not ignore 'typename'
	//because, by default, the language assumes that a name accessed 
	//through the scope opearator is not a type
	//constructor
	Blob_Core();
	Blob_Core(initializer_list<T>);
	//memeber of element in Blob
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//add and remove elements
	void push_back(const T&t) { data->push_back(t); }
	void push_back(const T&&t) { data->push_back(std::move(t)); }
	void pop_back();
	//element access
	T& back();
	T& operator[](size_type i);
private: 
	shared_ptr<vector<T>> data;
	void check(size_type i, const string& msg) const ;
};

template<typename T>
inline Blob_Core<T>::Blob_Core(): data(std::make_pair(vector<T>()))
{
}

template<typename T>
inline Blob_Core<T>::Blob_Core(initializer_list<T> l)
	:data(std::make_shared(vector<T>(l)))
{
}

template<typename T>
inline void Blob_Core<T>::pop_back()
{
	check(0, "back on empty Blob<T>");
	data->pop_back();
}

template<typename T>
inline T & Blob_Core<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline T & Blob_Core<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*p)[i];
}

template<typename T>
inline void Blob_Core<T>::check(size_type i, const string & msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T> class BlobPtr_Core {
public:
	BlobPtr_Core() :curr(0) {}
	BlobPtr_Core(Blob_Core<T> &a, size_t sz = 0) :wptr(a.data), curr(sz) {}

	T& deref() const;
	T& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	T& operator[](size_t n);
	const T& operator[](size_t n) const;
	// increment and decrement
	BlobPtr_Core<T>& operator++();		//prefix operators
	BlobPtr_Core<T>& operator--();
private:
	// check returns a shared_ptr to the vector if the check succeed
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;			// current position within the array
};

template<typename T>
inline T & BlobPtr_Core<T>::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template<typename T>
inline T & BlobPtr_Core<T>::operator[](size_t n)
{
	auto p = check(n, "dereference past end");
	return (*p)[n];
}

template<typename T>
inline const T & BlobPtr_Core<T>::operator[](size_t n) const
{
	auto p = check(n, "dereference past end");
	return (*p)[n];
}

template<typename T>
inline BlobPtr_Core<T>& BlobPtr_Core<T>::operator++()
{
	check(curr, "increment past end of Blob<T>Ptr");
	++curr;
	return *this;
}

template<typename T>
inline BlobPtr_Core<T>& BlobPtr_Core<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of Blob<T>Ptr");
	return *this;
}


template<typename T>
inline std::shared_ptr<std::vector<T>> BlobPtr_Core<T>::check(std::size_t, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret) throw std::runtime_error("unbound the Blob<T>Ptr");
	if (curr >= ret->size()) throw std::out_of_range(msg);
	return ret;
}
