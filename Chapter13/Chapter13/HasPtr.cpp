#include "HasPtr.h"

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	auto p = new string(*rhs.ps);
	delete ps;
	i = rhs.i;
	ps = rhs.ps;
	return *this;
}

HasPtr & HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

HasPtr::~HasPtr() {
	delete ps; ps = nullptr;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "call swap(HasPtr &lhs, HasPtr &rhs) " << endl;
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
	return *lhs.ps < *rhs.ps;
}

HasPtr::HasPtr(HasPtr &&rhs) noexcept : ps(rhs.ps), i(rhs.i)
{
	rhs.ps = nullptr;
}

HasPtr & HasPtr::operator=(HasPtr &&rhs) noexcept
{
	if (this != &rhs) {
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	return *this;
}
