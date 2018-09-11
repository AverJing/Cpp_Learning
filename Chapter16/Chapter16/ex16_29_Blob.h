/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
#pragma once

#include <vector>
#include <memory>
#include <string>


#include "ex16_28_shared_ptr.h"

//It's better
template<typename> class Blob;
template <typename> class BlobPtr;
//======================================================
//
// Blob - custom vector
//
//=======================================================
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
	// clang-format off
	friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
	friend bool operator> <T>(const Blob<T>&, const Blob<T>&);
	// clang-format on
	friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	// constructors
	Blob();
	Blob(std::initializer_list<T>);

	template<typename It>
	Blob(It begin, It end);

	Blob(const Blob<T> &lhs) :data(new std::vector<T>(*lhs.data)) {}
	Blob(const Blob<T> &&rhs) noexcept : data(std::move(rhs.data)) {}
	Blob& operator= (const Blob<T>&);
	Blob& operator= (const Blob<T>&&) noexcept;

	BlobPtr<T> begin();
	BlobPtr<T> end();

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//add and remove elements
	void push_back(const T&t) { data->push_back(t); }
	void push_back(const T&&t) { data->push_back(std::move(t)); }
	void pop_back();
	//element access
	T& back();
	T& front();
	const T& back() const;
	const T& front() const;
	T& operator[](size_type i);
	const T& operator[](size_type i) const;
private:
	shared_pointer<std::vector<T>> data;
	//throws mas if data[i] isn't valid
	void check(size_type i, const std::string &msg) const;
};

//======================================================
//
// friend function
//
//=======================================================
template <typename T> bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
	return *lhs.data == *rhs.data;
}

template <typename T> bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs) {
	//return !(*lhs.data == *rhs.data);
	//or
	return !(lhs == rhs);
}

template <typename T> bool operator<(const Blob<T>& lhs, const Blob<T>& rhs) {
	//return *lhs.data < *rhs.data;
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
		rhs.data->begin(), rhs.data->end());
}

template <typename T> bool operator>(const Blob<T>& lhs, const Blob<T>& rhs) {
	return rhs < lhs;
}

template <typename T> bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs) {
	return !(rhs < lhs);
}

template <typename T> bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs) {
	return !(lhs < rhs);
}

//======================================================
//
// member function
//
//=======================================================

template<typename T>
inline Blob<T>::Blob() :data(new std::vector<T>())
{}

template<typename T>
inline Blob<T>::Blob(std::initializer_list<T> il) : data(new std::vector<T>(il))
{
}

template<typename T>
template<typename It>
inline Blob<T>::Blob(It begin, It end)
	:data(new std::vector<T>(begin, end))
{
}

template<typename T>
inline void Blob<T>::pop_back()
{
	check(0, "back on empty Blob<T>");
	data->pop_back();
}

template<typename T>
inline T& Blob<T>::operator[](size_type i)
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline const T& Blob<T>::operator[](size_type i) const
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return data->at(i);
}

template<typename T>
inline T& Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
inline const T & Blob<T>::front() const
{
	check(0, "back on empty Blob");
	return data->front();
}

template<typename T>
inline T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline const T & Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string & msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T> 
Blob<T>& Blob<T>::operator=(const Blob<T>& b)
{
	data = new std::vector<T>(*b.data);
	return *this;
}

template<typename T>
inline Blob<T>& Blob<T>::operator = (const Blob<T>&& rhs) noexcept
{
	if (this != &rhs) {
		data = std::move(rhs.data);
		rhs.data = nullptr;
	}
	return *this;
}

template <typename T> BlobPtr<T> Blob<T>::begin()
{
	return BlobPtr<T>(*this);
}

template <typename T> BlobPtr<T> Blob<T>::end()
{
	return BlobPtr<T>(*this, data->size());
}

//=================================================================================
//		BlobPtr - custom iterator of Blob
//=================================================================================

template <typename T> class BlobPtr {
	friend bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
	{
		return lhs.curr == rhs.curr;
	}
	friend bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) { return !(lhs == rhs); }
	friend bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
	{
		return lhs.curr < rhs.curr;
	}
	friend bool operator>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
	{
		return lhs.curr > rhs.curr;
	}
	friend bool operator<=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
	{
		return lhs.curr <= rhs.curr;
	}
	friend bool operator>=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
	{
		return lhs.curr >= rhs.curr;
	}

public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T>& s, size_t sz = 0) : wptr(s.data), curr(sz) {}

	T& operator*() const;
	T* operator->() const;
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	BlobPtr& operator+=(size_t);
	BlobPtr& operator-=(size_t);
	BlobPtr operator+(size_t) const;
	BlobPtr operator-(size_t) const;

	T& operator[](size_t n);
	const T& operator[](size_t n) const;

private:
	shared_pointer<std::vector<T>> check(size_t, const T&) const;

	shared_pointer<std::vector<T>> wptr;
	size_t curr;
};

//------------------------------------------------------------------------------
//  member function.
//------------------------------------------------------------------------------

template <typename T> T& BlobPtr<T>::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template <typename T> T* BlobPtr<T>::operator->() const
{
	return &this->operator*();
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of Blob<T>Ptr");
	++curr;
	return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(-1, "decrement past begin of Blob<T>Ptr");
	return *this;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr<T> ret = *this;
	++*this;
	return ret;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr<T> ret = *this;
	--*this;
	return ret;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of Blob<T>Ptr");
	return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator-=(size_t n)
{
	curr -= n;
	check(curr, "increment past end of Blob<T>Ptr");
	return *this;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator+(size_t n) const
{
	BlobPtr<T> ret = *this;
	ret += n;
	return ret;
}

template <typename T> inline BlobPtr<T> BlobPtr<T>::operator-(size_t n) const
{
	BlobPtr<T> ret = *this;
	ret -= n;
	return ret;
}

template <typename T> inline shared_pointer<std::vector<T>> BlobPtr<T>::check(size_t i, const T& msg) const
{
	//auto ret = wptr.lock();
	if (!wptr) throw std::runtime_error("unbound Blob<T>Ptr");
	if (i >= wptr->size()) throw std::out_of_range(msg);
	return wptr;
}

template <typename T> inline T& BlobPtr<T>::operator[](size_t n)
{
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}

template <typename T> inline const T& BlobPtr<T>::operator[](size_t n) const
{
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}