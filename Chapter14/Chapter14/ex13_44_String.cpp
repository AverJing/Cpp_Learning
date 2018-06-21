#include "ex13_44_string.h"
#include <iostream>
#include <algorithm>

String::String(const char *s)
{
	auto newdata = alloc.allocate(strlen(s));
	element = newdata;
	for (size_t i = 0; i < strlen(s); ++i)
		alloc.construct(newdata++, *(s + i));
	//first_free = cap = newdata;
	first_free = newdata;
}

String::String(const String &rhs)
{
	auto newdata = alloc_n_copy(rhs.element, rhs.first_free);
	element = newdata.first;
	first_free = newdata.second;
	cout << "String(const String &)" << endl;
}

String::String(String &&rhs) noexcept : element(rhs.element), first_free(rhs.first_free)
{
	rhs.element = rhs.first_free = nullptr;
	cout << "String(String &&) noexcept" << endl;
}

String & String::operator=(String &&rhs) noexcept
{
	if (this != &rhs) {
		free();
		element = rhs.element;
		first_free = rhs.first_free;
		rhs.element = rhs.first_free = nullptr;
	}
	cout << "operator=(String &&) noexcept" << endl;
	return *this;
}

String & String::operator=(const String &rhs)
{
	auto newdata = alloc_n_copy(rhs.element, rhs.first_free);
	free();
	element = newdata.first;
	first_free = newdata.second;
	cout << "operator=(const String &)" << endl;
	return *this;
}

char & String::operator[](const size_t n)
{
	if (element + n < first_free)
		return *(element + n);
	else
		return;
}

const char & String::operator[](const size_t n) const
{
	if (element + n < first_free)
		return *(element + n);
	else
		return;
}

String::~String()
{
	free();
}

pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto newdata = alloc.allocate(e- b);
	return{newdata, uninitialized_copy(b ,e, newdata)};
}

void String::free()
{
	if (element) {
		//for (auto last = first_free; last != element;)
			//alloc.destroy(--last);
		//or It's better
		for_each(element, first_free, [this](char& c) {alloc.destroy(&c); });
		alloc.deallocate(element, first_free - element);
	}
}

void String::range_intializer(const char *b, const char *e)
{
	auto newdata = alloc_n_copy(b, e);
	element = newdata.first;
	first_free = newdata.second;
}

ostream & operator<<(ostream &os, const String &rhs)
{
	for (auto dest = rhs.element; dest != rhs.first_free; )
		os << *dest++;
	os << endl;
	return os;
}
