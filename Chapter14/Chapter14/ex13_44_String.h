#pragma once
#pragma warning(disable:4996) //ignore checked iterators
#ifndef EX13_STRING_H
#define EX13_STRING_H

/*
*
*@author£ºAver Jing
*@description£º
* Write a class named String that is a simplified version of the library string class. Your 
*class should have at least a default constructor and a constructor that takes a pointer to a
*C-style string. Use an allocator to allocate memory that your String class uses.
*@date£ºJune 11, 2018
*
*/
#include <allocators>
#include <cstring>
#include <memory>

using namespace std;

class String {
public:
	friend ostream& operator<<(ostream&, const String&);
	String() :element(nullptr), first_free(nullptr){}
	String(const char *);
	String(const String&);
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;
	String& operator=(const String&);
	char& operator[](const size_t n);
	const char& operator[](const size_t n) const;
	~String();

private:
	pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void range_intializer(const char*, const char*);


private:
	allocator<char> alloc;
	char *element;		//pointer to the first element
	char *first_free;	//pointer to after of last element
	//char *cap;		//seem to be useless
};

#endif