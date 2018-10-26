#pragma once
#ifndef EX16_28_SHARED_PTR_H
#define EX16_28_SHARED_PTR_H

#include "ex16_21_DebugDelete.h"
#include <functional>

template<typename> class shared_pointer;
template<typename T> void swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs);

template<typename T>
class shared_pointer {
	friend void swap<T>(shared_pointer<T>& lhs, shared_pointer<T>& rhs);
public:
	/*
	shared_pointer() : ptr(nullptr), count(0) {};
	shared_pointer(T * p) : ptr(p), count(++count) {}	//p must be pointed to new
	shared_pointer(shared_pointer<T> &lhs) {
		ptr = lhs.ptr;
		++count;
	}
	shared_pointer<T> & opeator = (const shared_pointer<T>& rhs) {
		if (this != &rhs) {
			ptr = rhs.ptr;
			++count;
		}
		return *this;
	}*/
	shared_pointer() = default;

	//! constructor taking raw pointer.
	//! set the refCount as 1
	shared_pointer(T* up, std::function<void(T*)> d = DebugDelete()) :
		ptr(up), refCount(new std::size_t(1)), deleter(d) { }

	//! copy constructor.
	//! increment useCount for each Copy
	shared_pointer(const shared_pointer& sp) :
		ptr(sp.ptr), refCount(sp.refCount), deleter(sp.deleter)
	{
		++*refCount;
	}

	//! move constructor
	shared_pointer(shared_pointer&& sp) noexcept;

	//! copy assignment
	shared_pointer& operator =(const shared_pointer& rhs);

	//! move assignment
	shared_pointer& operator =(shared_pointer&& rhs) noexcept;


	//! conversion operator
	operator bool() const { return ptr ? true : false; }

	//! dereference
	T& operator* () const { return *ptr; }

	//! arrow
	T* operator->() const { return &this->operator *(); }

	//! return useCount
	std::size_t use_count() const { return *refCount; }

	//! get the underlying pointer
	T* get() const noexcept { return ptr; }

	//! check if the unique user
	bool unique() const noexcept { return *refCount == 1; }

	//! swap
	void swap(shared_pointer& rhs) { ::swap(*this, rhs); }

	//! if unique user, free the object pointed to
	void reset() noexcept { decrement_n_destroy(); }

	//! make prt point where p pointing and create a new coount for it
	void reset(T* p)
	{
		if (ptr != p)
		{
			decrement_n_destroy();
			ptr = p;
			refCount = new std::size_t(1);
		}
	}

	//! reset to point where p is pointing and change deleter to d.
	void reset(T *p, const std::function<void(T*)>& d)
	{
		reset(p);
		deleter = d;
	}


	~shared_pointer() {
		/*
		if (count)
			--count;
		else
			delete ptr;*/
		decrement_n_destroy();
	}

	//注意，详解 见More effective C++ P148  It28
	//为了实现  所有类型的转换函数
	//举例   使用智能指针的基类虚函数的调用
	template<class newType>
	operator shared_pointer<newType>() {
		return  shared_pointer<newType>(ptr);
	}
private:
	T * ptr = nullptr;
	//static unsigned count;
	std::size_t* refCount = new std::size_t(0);

	//! any functor lambda or function pointer that matched this
	//! signature can replace the default one at run time.
	std::function<void(T*)> deleter{ DebugDelete() };
	//! signature ^^^^^^^^         ^~~~~~~~~~~~~~^
	//!                         here: = doesn't work, another way is initializing it in constructor.

	//! utilities
	void decrement_n_destroy();
};

template <typename T>
inline void
swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs)
{
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.refCount, rhs.refCount);
	swap(lhs.deleter, rhs.deleter);
}

//! move constructor
template<typename T>
inline
shared_pointer<T>::shared_pointer(shared_pointer&& sp) noexcept:
ptr(sp.ptr), refCount(sp.refCount), deleter(std::move(sp.deleter))//call movement constructor
{
	sp.ptr = nullptr;
	sp.refCount = nullptr;
}

//! copy assignment
template<typename T>
inline shared_pointer<T>&
shared_pointer<T>::operator =(const shared_pointer& rhs)
{
	//! increment rhs.refCount first to ensure safty when self-assignment
	++*rhs.refCount;

	//! for lhs:
	decrement_n_destroy();

	//! copy datastructure from rhs to this.
	ptr = rhs.ptr;
	refCount = rhs.refCount;
	deleter = rhs.deleter;

	return *this;
}

//! move assignment
template<typename T>
inline shared_pointer<T>&
shared_pointer<T>::operator =(shared_pointer&& rhs) noexcept
{
	//! for lhs
	decrement_n_destroy();

	//! swap two sides
	::swap(*this, rhs);

	std::cout << "shared_pointer::move=\n";

	return *this;
}

template <typename T>
inline std::ostream&
operator <<(std::ostream& os, shared_pointer<T> p)
{
	os << p.get();
	return os;
}

//! utilities for decrement and delete using deleter.
template <typename T>
inline void
shared_pointer<T>::decrement_n_destroy()
{
	if (ptr)
	{
		if (--*refCount == 0)
		{
			delete refCount;
			deleter(ptr);
		}
		refCount = nullptr;
		ptr = nullptr;
	}
}


#endif // !EX16_28_SHARED_PTR_H
