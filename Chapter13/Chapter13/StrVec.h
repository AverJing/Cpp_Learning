#pragma once
#pragma warning(disable:4996)
/*
*
*@author£ºAver Jing
*@description£º
* implement a simplification of the library vector class.
*@date£ºJune 8,2018
*
*/

//ex13.39
//Write your own version of StrVec, including versions of
//  reserve, capacity (9.4, p. 356), and resize (9.3.5, p. 352).

#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <allocators>
#include <iterator>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include <memory>
#include <string>

using namespace std;
using namespace stdext;

class StrVec
{
public:
	StrVec() :// the allocator member is default initialized
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(initializer_list<string>&);
	StrVec(const StrVec&);			// copy constructor
	StrVec &operator=(const StrVec&);	//copy assignment
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(StrVec&&) noexcept;
	~StrVec();
	void push_back(const string&);		// copy the element
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }
	void reserve(const size_t &n);
	void alloc_n_move(const size_t &n);
	void resize(const size_t &n);
	void resize(const size_t &n, const string &s);

private:
	allocator<string> alloc;		// allocates  the elements
	// used by the functions that add elements to the StrVec
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	// utilities used by the copy constructors, assignment operator, and destructor
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();			// destroy the elements and free the space
	void reallocate();		// get more space and copy the existing elements
	string *elements;		// pointer to the first element in the array
	string *first_free;		// pointer to the first free element in the array
	string *cap;			// pointer to one past the end of the array
};

#endif

