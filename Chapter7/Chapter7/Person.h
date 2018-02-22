#pragma once

#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;
//ex7_4  Please write a class named Person that represents the name and address of a person.
//ex7_5  Provide operations in your person class to return the name and address. 
class Person {
private:
	string name;
	string addr;
public:	
	friend istream &read(istream &is, Person &tmp);
	const string& getName() const { return name; }
	const string& getAddr() const { return addr; }
	//ex7_15 add appropriate constructor to your Person class                                                                                                                                             
	Person() = default;
	Person(string name, string addr) :name(name), addr(addr) {}
	Person(istream &is) {
		is >> name >> addr;
	}
};

//ex7_9 Provide operation to read and print your person class.
//nomember function
istream &read(istream &is, Person &tmp) {
	is >> tmp.name >> tmp.addr;
	return is;
}

ostream &print(ostream &os, const Person &tmp) {
	os << tmp.getName() << ' ' << tmp.getAddr();
	return os;
}

#endif // !PERSON_H
