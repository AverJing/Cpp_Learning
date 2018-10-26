#pragma once
#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
public:
	friend StrBlobPtr;
	friend ConstStrBlobPtr;

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	int count() const { return data.use_count(); }
	//add and delete element
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	//visit element
	string& front();
	string& back();
	const string& front()const;
	const string& back()const;
private:
	shared_ptr<vector<string>> data;
	//throws message if data[i] is not valid
	void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>> ()/*new vector<string>*/) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const{
	if (i >= data->size())
		throw out_of_range(msg);
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}
const string& StrBlob::front()const {
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::back()const {
	check(0, "back on empty StrBlob");
	return data->back();
}

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob& s, size_t i = 0) : wptr(s.data), curr(i) {}
	StrBlobPtr(const StrBlob& s, size_t i = 0) : wptr(s.data), curr(i) {}
	//Attention: consider the difference among value,reference and pointer(const) which can be overload function parameter 
	string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }

private:
	//check returns a share_ptr to the vector if the check succeeds
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	//store a weak_ptr, which means the underlying vector might be destroyed
	weak_ptr<vector<string>> wptr;
	size_t curr;//current position within the array
};

inline std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}

inline StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}


StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {} // should add const
	bool operator!=(ConstStrBlobPtr& p) { return p.curr != curr; }
	const string& deref() const
	{ // return value should add const
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	ConstStrBlobPtr& incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}

private:
	std::shared_ptr<vector<string>> check(size_t i, const string& msg) const
	{
		auto ret = wptr.lock();
		if (!ret) throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size()) throw std::out_of_range(msg);
		return ret;
	}
	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};

ConstStrBlobPtr StrBlob::begin() const // should add const
{
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const // should add const
{
	return ConstStrBlobPtr(*this, data->size());
}
#endif