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
#include <string>
#include <memory>

using std::string;

class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(const std::initializer_list<std::string>&);
	StrVec& operator=(const StrVec&);
	~StrVec() { free(); }
	void push_back(const string& s);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	void reserve(const size_t n);
	void resize(const size_t n);
	void resize(const size_t n, const string& s);
private:
	std::allocator<string> alloc;

	void chk_n_alloc() { if (size() == capacity()) reallocate(); }

	//same to reallocate
	void alloc_n_move(const size_t & n);
	
	//工具函数  拷贝，赋值，析构函数使用
	std::pair<std::string*, std::string*> alloc_n_copy(const string*, const string*);
	void free();			   // destroy the elements and free the space
	void reallocate();		   // get more space and copy the existing elements
	std::string* elements;	   // pointer to the first element in the array
	std::string* first_free;   // pointer to the first free element in the array
	std::string* cap;	 	   // pointer to one past the end of the array
};

void StrVec::push_back(const string& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::free() {
	for (auto p = first_free; p != elements;)
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const string* beg, const string* end) {
	auto data = alloc.allocate(end - beg);

	return { data, std::uninitialized_copy(beg, end, data) };
}

void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;

	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = newdata + newcapacity;
}

StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

void StrVec::alloc_n_move(const size_t & n)
{
	auto newdata = alloc.allocate(n);		//allocate new memory
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();			// free the old space once we've moved the elements
					// update our data structure to point to the new elements
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void StrVec::reserve(const size_t n)
{
	if (size() >= n || capacity() >= n)
		return;
	alloc_n_move(n);
}

inline void StrVec::resize(const size_t n)
{
	resize(n, std::string());
}

inline void StrVec::resize(const size_t n, const string & s)
{
	if (size() < n) {
		if (capacity() < n)
			reserve(2 * n);
		for (auto i = size(); i < n; ++i)
			alloc.construct(first_free++, s);
	}
	else if (size() > n) {
		for (auto i = size(); i > n; --i)
			alloc.destroy(--first_free);
	}
}

StrVec::StrVec(const std::initializer_list<string> &ilst)
{
	auto newdata = alloc_n_copy(ilst.begin(), ilst.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& s) {
	if (this != &s) {
		auto newdata = alloc_n_copy(s.begin(), s.end());
		free();
		elements = newdata.first;
		first_free = cap = newdata.second;
	}
	return *this;
}