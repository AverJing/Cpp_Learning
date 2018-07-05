#pragma once
#ifndef EX16_12_BLOB_H
#define EX16_12_BLOB_H

#include <vector>
#include <memory>
#include <string>

//It's better
template<typename> class BlobPtr;
template<typename> class Blob;

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
	Blob(It begin,It end)

	Blob(const Blob<T> &lhs) :data(std::make_shared<vector<T>>(*lhs.data)) {}
	Blob(const Blob<T> &&rhs) noexcept : data(std::move(lhs.data)) {}
	Blob& operator = (const Blob<T>&);
	Blob& operator = (const Blob<T>&&) noexcept;
	//member of elements in the Blob
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
	std::shared_ptr<std::vector<T>> data;
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
inline Blob<T>::Blob() :data(std::make_shared<std::vector<t>>())
{}

template<typename T>
inline Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<t>>(il))
{
}

template<typename T>
template<typename It>
inline Blob<T>::Blob(It begin, It end)
	:data(std::make_shared<std::vector<T>>(begin, end))
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
	return data->back();
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

template<typename T>
inline Blob<T>& Blob<T>::operator=(const Blob<T>& lhs)
{
	data = make_shared<vector<T>>(*lhs.data);
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

//======================================================
//
// BlobPtr - custom iterator of Blob
//
//=======================================================
template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);

template<typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	// clang-format off
	friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator> <T>(const BlobPtr<T>&, const BlobPtr<T>&);
	// clang-format on
	friend bool operator<=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator>=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public: 
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) :wptr(a.data), curr(sz) {}

	T& deref() const;
	T& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	T& operator[](size_t n);
	const T& operator[](size_t n) const;
	// increment and decrement
	BlobPtr& operator++();		//prefix operators
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	BlobPtr& operator+=(size_t);
	BlobPtr& operator-=(size_t);
	BlobPtr operator+(size_t) const;
	BlobPtr operator-(size_t) const;
private:
	// check returns a shared_ptr to the vector if the check succeed
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;			// current position within the array
};

//======================================================
//
// friend function
//
//=======================================================
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(lhs == rhs);
}

template <typename T> bool operator<(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
	return x.curr < y.curr;
}

template <typename T> bool operator>(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
	return x.curr > y.curr;
}

template <typename T> bool operator<=(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
	return x.curr <= y.curr;
}

template <typename T> bool operator>=(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
	return x.curr >= y.curr;
}

//======================================================
//
// member function
//
//=======================================================

template <typename T> inline T& BlobPtr<T>::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
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

template<typename T>
inline std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t, const std::string &) const
{
	auto ret = wptr.lock();
	if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");
	if (i >= ret->size()) throw std::out_of_range(msg);
	return ret;
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


#endif // ! EX16_12_BLOB_H

