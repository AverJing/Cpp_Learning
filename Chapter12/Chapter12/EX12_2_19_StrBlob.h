/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
#ifndef EX12_2_STRBLOB
#define EX12_2_STRBLOB

#pragma once

#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;
using std::shared_ptr;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
public:
	friend StrBlobPtr;
	friend ConstStrBlobPtr;
	typedef vector<string>::size_type size_type;
	StrBlob();
	explicit StrBlob(std::initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const string& t) { data->push_back(t); }
	void pop_back() {
		check(0, "pop_back in empty StrBlob");
		data->pop_back();
	}

	std::string& front() {
		check(0, "front on empty StrBlob");
		data->front();
	}
	std::string& back() {
		check(0, "back on empty StrBlob");
		data->back();
	}
	std::string& front() const {
		check(0, "front on empty StrBlob");
		data->front();
	}
	std::string& back() const {
		check(0, "back on empty StrBlob");
		data->back();
	}
	~StrBlob();

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg) const {
		if (i >= data->size())
			throw std::out_of_range(msg);
	}
};

class StrBlobPtr {
public:
	typedef vector<string>::size_type size_type;
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob& str) :wptr(str.data), curr(0) {}
	string& deref() const{
		auto ret = check(curr, "dereference past end");
		return (*ret)[curr];
	}
	StrBlobPtr& incr() {
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
private:
	shared_ptr<vector<string>> check(size_type i, const string& msg) const{
		auto p = wptr.lock();
		if (!p)
			throw std::runtime_error("unbound StrBlobPtr");
		if (i >= p->size())
			throw std::out_of_range(msg);
		
		return p;
	}
	std::weak_ptr<vector<string>> wptr;
	size_type curr;
};

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

StrBlob::StrBlob():data(std::make_shared<vector<string>>())
{
}

StrBlob::StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) 
{}

StrBlob::~StrBlob()
{
}


#endif // !EX12_2_STRBLOB