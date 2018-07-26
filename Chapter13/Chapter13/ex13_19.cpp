/*
*
*@author£ºAver Jing
*@description£º Does your Employee class need to define its own versions of the copy-control
*  members?
*  If so, why? If not, why not?
*  Implement whatever copy-control members you think Employee needs.
*
*  Answer: No, cause there really is no sensible meaning. employee can't copy
*  in real world.
*@date£º
*
*/

#include<iostream>

using namespace std;

class Employee {
public:
	Employee();
	Employee(const string& name);
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;

	const int id() const { return id_; }

private:
	string name_;
	int id_;
	static int s_increment;
};

int main() {

	return 0;
}