#pragma once
/*
*
*@author£ºAver Jing
*@description£º
* Define your own reference-counted version of HasPtr.
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
	HasPtr(const string &s = string()) :ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }
	HasPtr& operator=(const HasPtr&);
	~HasPtr();

private:
	string *ps;
	int i;
	size_t *use;//member to keep track of how many objects share
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	use = rhs.use;
	i = rhs.i;
	ps = rhs.ps;
	return *this;
}

HasPtr::~HasPtr() {
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}
#endif