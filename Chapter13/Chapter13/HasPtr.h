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
	HasPtr(HasPtr&&) noexcept;
	//HasPtr& operator=(const HasPtr&);
	//HasPtr& operator=(HasPtr&&) noexcept;
	HasPtr& operator=(HasPtr);
	~HasPtr();

private:
	string * ps;
	int i;
	//size_t *use;//member to keep track of how many objects share
};
#endif