/*
*
*@author£ºAver Jing
*@description£º
*ex13.5:
*Given the following sketch of a class, write a copy constructor that
*copies all the members. Your constructor should dynamically allocate a new string and
*copy the object to which ps points, rather than copying pa itself.
*ex13.8:
*Write the assignment operator for the HasPtr class. As with the copy constructor, your 
*assignment operator should copy the object to which ps points.
*ex13.11:
*add a destructor to your HasPtr class from the previous exercise.
*@date£ºApril 4, 2018
*/

#include<iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
	//1
	/*error
	HasPtr(const HasPtr &hptr) {
		auto str = new string(*hptr.ps);
		delete ps;
		ps = str;
		i = hptr.i;
	}*/
	//2
	HasPtr(const HasPtr &hptr) : ps(new string(*hptr.ps)), i(hptr.i){}
	HasPtr& operator=(const HasPtr &rhs) {
		auto str = new string(*rhs.ps);
		delete ps;
		ps = str;
		i = rhs.i;
		return *this;
	}
	~HasPtr() { delete ps; };

private:
	string * ps;
	int i;
};

int main() {

	return 0;
}