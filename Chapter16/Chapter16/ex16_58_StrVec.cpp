#include "ex16_58_StrVec.h"

StrVec::StrVec(const initializer_list<string> &ilst)
{
	auto newdata = alloc_n_copy(ilst.begin(), ilst.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s)
{
	// call alloc_n_copy to allocate exactly as many elements as in s
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec & StrVec::operator=(const StrVec &s)
{
	// call alloc_n_copy to allocate exactly as many elements in s
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::StrVec(StrVec &&rhs) noexcept:elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec & StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();		// ensure that there is room for another element
	// construct a copy of s in the element to which first_free points
	alloc.construct(first_free++, s);
}

void StrVec::reserve(const size_t &n)
{
	if (this->size() >= n)
		return;
	else if (this->capacity() >= n)
		return;
	else{
		alloc_n_move(n);
	}
}

void StrVec::alloc_n_move(const size_t & n)
{
	auto newdata = alloc.allocate(n);		//allocate new memory
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();			// free the old space once we've moved the elements
					// update our data structure to point to the new elements
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void StrVec::resize(const size_t & n)
{
	resize(n, string());
}

void StrVec::resize(const size_t & n, const string &s)
{
	if (this->size() < n) {
		if (this->capacity() < n) {
			reserve(n * 2);
		}
		for (size_t i = size(); i < n; ++i)
			alloc.construct(first_free++, s);
	}
	else if (n < this->size()) {
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	}
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return{data, uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
	// may not pass deallocate a 0 pointer; if elements is 0, there's no word to do
	if (elements) {
		// destroy the old elements in reverse order
		//for (auto p = first_free; p != elements; /*empty*/)
			//alloc.destroy(--p);

		//instead
		for_each(elements, first_free, 
			[this](string &rhs) {alloc.destroy(&rhs); });
		/*for_each(elements, first_free,
			[this](string *rhs) {alloc.destroy(rhs); });*/

		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	// we'll allocate space for twice as many elements as the current size
	auto newcapacity = size() ? 2 * size() : 1;
	// allocate new memory
	auto newdata = alloc.allocate(newcapacity);
	// move the data from the old memory to the new
	auto dest = newdata;		// points to the next free position in the new array
	auto elem = elements;		// points to the next element in the old array
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();			// free the old space once we've moved the elements
	// update our data structure to point to the new elements
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
