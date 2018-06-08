/*
*
*@author£ºAver Jing
*@description£º
* A good way to understand copy-control members and constructors is to define a simple class
*with these members in which each member prints its name:
*	struct X{
*		X(){cout << "X()" << endl;}
*		X(const X&){cout << "X(const X&)" << endl;}
*	};
* Add the copy-assignment operator and destructor to X and write a program using X objects 
*in various ways: Pass them as nonreference and reference parameters; dynamically allocate
*them ; put them in containers; and so forth. Study the output until you are certain you
*understand when and why each copy-control member is used. As you read the output, remember
*that the complier can omit calls to the copy constructor.
*@date£ºJune 5, 2018
*
*/

#include <iostream>
#include <vector>
using namespace std;

struct X {
	X() { cout << "X()" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }
	~X() { cout << "~X()" << endl; }
	X& operator=(const X& x) {
		*this = x;
		cout << "operator=" << endl;
	}
};

void f(const X& rx, X x)
{
	vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);
	vec.push_back(x);
}

int main() {
	X* px = new X;
	f(*px, *px);
	delete px;

	return 0;
}