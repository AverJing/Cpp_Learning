#pragma once
/*
*
*@author£ºAver Jing
*@description£º
* implement a simplification of the library vector class.
*@date£ºJune 8,2018
*
*/

#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <allocators>
#include <memory>
#include <string>

using namespace std;

class StrVec
{
public:
	StrVec() :// the allocator member is default initialized
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);			// copy constructor
	StrVec &operator=(const StrVec&);	//copy assignment
	~StrVec();
	void push_back(const string&);		// copy the element
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }

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

