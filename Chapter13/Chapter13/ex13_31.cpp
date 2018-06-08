/*
*
*@author£ºAver Jing
*@description£º
* Give your class a < operator and define a vector of HasPtrs. Give that vector some 
*elements and then sort the vector. Note when swap is called.
*@date£ºJune 7, 2018
*
*/

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr&, const HasPtr&);
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)), i(rhs.i) { }
	HasPtr& operator=(HasPtr);
	~HasPtr();

private:
	string * ps;
	int i;
	//size_t *use;//member to keep track of how many objects share
};

//It's very fantastic.   focus on parameter
HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
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

int main() {
	const string s1("aj"), s2("ac"), s3("ad");
	vector<HasPtr> hpv{ HasPtr(s1), HasPtr{s2}, HasPtr{s3} };
	sort(hpv.begin(), hpv.end());

	return 0;
}