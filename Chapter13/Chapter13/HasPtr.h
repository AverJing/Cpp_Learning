#pragma once
/*
*
*@author£ºAver Jing
*@description£º
* Standard HasPtr.
*@date£ºJune 6, 2018
*
*/

#ifndef EX_13_27_H
#define EX_13_27_H

#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr&, const HasPtr&);
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)), i(rhs.i) { }
	HasPtr& operator=(const HasPtr&);
	~HasPtr();

private:
	string * ps;
	int i;
	//size_t *use;//member to keep track of how many objects share
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	auto p = new string(*rhs.ps);
	delete ps;
	i = rhs.i;
	ps = rhs.ps;
	return *this;
}

HasPtr::~HasPtr() {
		delete ps;
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
#endif