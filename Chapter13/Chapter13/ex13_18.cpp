/*
*
*@author£ºAver Jing
*@description£º
* Define an Employee class that contains an employee name and a unique employee identifier.
*Give the class a default constructor and a constructor that takes a string representing
*the employee's name. Each constructor should generate a unique ID by incrementing a static
*data member.
*@date£ºJune 5, 2018
*
*/

#include<iostream>
#include <string>

using namespace std;

//static int cnt = 0;

class Employee
{
public:
	Employee(): name(), ID(cnt++) {}
	Employee(const string& name) : name(name), ID(cnt++) {}	
	Employee(const Employee& rhs) {
		name = rhs.name;
		ID = cnt++;
	}
	Employee& operator=(const Employee& rhs) {
		ID = cnt++;
		name = rhs.name;
		return *this;
	}
	const int getID() { return ID; }
private:
	string name;
	int ID;
	//or
	static int cnt;
};

int Employee::cnt = 0;

int main() {

	return 0;
}