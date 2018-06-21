#include "ex14_16_StrBlob.h"

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return lhs.data == rhs.data;
	//return *lhs.data==*rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs==rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	//return lhs.wptr.lock()==rhs.wptr.lock();
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	//return lhs.wptr.lock() == rhs.wptr.lock();
	return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs==rhs);
}

inline StrBlob & StrBlob::operator=(const StrBlob &rhs)
{
	if (this != &rhs) {
		data = make_shared<vector<string>>(*rhs.data);
	}
	return *this;
}

StrBlob& StrBlob::operator=(StrBlob&& rhs) NOEXCEPT {
	if (this != &rhs) {
		data = make_shared<vector<string>>(*rhs.data);
		rhs.data = nullptr;
	}
	return *this;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, this->size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, this->size());
}

string & StrBlob::operator[](const size_t n)
{
	check(n, "index error/out of range");
	return (*data)[n];
}

const string & StrBlob::operator[](const size_t n) const
{
	check(n, "index error/out of range");
	//return (*data)[n];
	return data->at(n);
}

StrBlobPtr & StrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr & StrBlobPtr::operator-=(size_t n)
{
	curr -= n;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n) const
{
	auto ret = *this;
	ret += n;
	return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n) const
{
	auto ret = *this;
	ret -= n;
	return ret;
}

string & StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

string * StrBlobPtr::operator->() const
{
	return & this->operator*();
}

string & StrBlobPtr::operator[](const size_t n)
{
	auto p = check(n, "index error/out of range");
	return (*p)[n];
}

const string & StrBlobPtr::operator[](const size_t n) const
{
	auto p = check(n, "index error/out of range");
	return (*p)[n];
}

StrBlobPtr & StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr & StrBlobPtr::operator++(int)
{
	auto ret = *this;
	++*this;
	return ret;
}

StrBlobPtr & StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past end of StrBlobPtr");	
	return *this;
}

StrBlobPtr & StrBlobPtr::operator--(int)
{
	auto ret = *this;
	--*this;
	return ret;
}

string & ConstStrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

string * ConstStrBlobPtr::operator->() const
{
	return & this->operator*();
}
