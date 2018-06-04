/*
*
*@author£ºAver Jing
*@description:a part of exercise in CH12
*@date£ºMay 26, 2018
* bad design: do not place all exercise in one file
* 
*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <cstring>

#include "StrBlob.h"
#include "TextQuery.h"
#include "TextQueryTemplate.h"
#include "TextQueryStrBlob.h"

using namespace std;

//How many elements do b1 and b2 have at the end of this code?
void ex12_1() {
	StrBlob b1;
	{
		StrBlob b2 = { "a", "an", "the" };
		b1 = b2;
		b2.push_back("about");
	}
	cout << b1.count() << endl;
}

//ex12.3 Does this class need const versions of push_back and pop_back? 
//If so, add them. If not, why aren't the needed?
//Please consider it seriously.
//https://www.douban.com/group/topic/61573279/
//Or https://stackoverflow.com/questions/20725190/operating-on-dynamic-memory-is-it-meaningful-to-overload-a-const-memeber-functi

//Write a function that returns a dynamically allocated vector of ints. Pass that
//vector to another function that reads the standard input to give values to the elements.
//Pass the vector to another function to print the values that were read.Remember to delete
//the vector at the appropriate time.
//ex12.6
vector<int>* dynamic_vector_generator() {
	vector<int> *p = new vector<int>();
	return p;
}
void dynamic_vector_input(vector<int>* p) {
	int i;
	while (cin >> i) p->push_back(i);
}
void dynamic_vector_print(vector<int>* p) {
	for (const auto& e : *p)
		cout << e << ' ';
	cout << endl;
}

//Redo the previous exercise, this time using shared_ptr.
//ex12.7
shared_ptr<vector<int>> dynamic_vector_generator_sptr() {
	return make_shared<vector<int>>();
}
void dynamic_vector_input_sptr(shared_ptr<vector<int>> p) {
	int i;
	while (cin >> i) p->push_back(i);
}
void dynamic_vector_print_sptr(shared_ptr<vector<int>> p) {
	for (const auto& e : *p)
		cout << e << ' ';
	cout << endl;
}

//ex12.10
void process(shared_ptr<int> p) {
	cout << p.use_count() << endl;
}

void ex12_16() {
	unique_ptr<int> p1(new int(42));
	//unique_ptr<int> p2(p1);
}

void ex12_20() {
	ifstream ifle("test.txt");
	string line;
	StrBlob str;
	while (getline(ifle, line) ){
		str.push_back(line);
	}
	StrBlobPtr sptr(str);
	/*for (int i = 0; i < str.size(); ++i) {
		cout << sptr.deref();
		sptr.incr();
	}*/
	for (StrBlobPtr beg(str.begin()), end(str.end()); beg != end; beg.incr())
		cout << beg.deref() << endl;
}

//Write a program to concatenate two string literals,putting the result in a dynamically
//allocated array of char.Write a program to concatenate two library strings that have 
//the same value as the literals used in the first program.
void ex12_23() {
	const char* p1 = "hello ";
	const char* p2 = "world.";
	unsigned int len = strlen(p1) + strlen(p2) + 1;
	char* c = new char[len]();
	strcat_s(c, len, p1);
	strcat_s(c, len, p2);
	cout << c << endl;

	//ex12.24
	string s1{ "hello " };
	string s2{ "world." };
	strcpy_s(c, len, (s1 + s2).c_str());
	cout << c << endl;
	//char* s = new char[10]("ssss");
	delete[] c;
}

void ex12_26(const int n) {
	allocator<string> alloc;
	auto p = alloc.allocate(n);
	auto q = p;
	string s;
	while (cin >> s && p != p + n)
		alloc.construct(p++, s);

	while (q != p) {
		cout << *--p << ' ';
		alloc.destroy(p);
	}
		
	alloc.deallocate(p, n);
}

void ex12_27() {
	fstream in("word_search.txt");
	TextQuery tq(in);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		tq.query(s);
	}
}

//Define your own version of the TextQuery and QuryResult classes and execute the runQueries
//function.
void ex12_30() {
	ifstream in("word_search.txt");
	TextQueryTem tqm(in);
	while (true) {
		cout << "enter key to look for, or q to quit:";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tqm.query(s)) << endl;
	}
}

void ex12_32() {
	ifstream in("word_search.txt");
	TextQueryStrBlob tqm(in);
	while (true) {
		cout << "enter key to look for, or q to quit:";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tqm.query(s)) << endl;
	}
}

int main() {
	//ex12_1();
	/*
	auto p = dynamic_vector_generator();
	dynamic_vector_input(p);
	dynamic_vector_print(p);
	delete p;*/

	/*
	auto p = dynamic_vector_generator_sptr();
	dynamic_vector_input_sptr(p);
	dynamic_vector_print_sptr(p);*/
	/*
	shared_ptr<int> p(new int(40));
	process(shared_ptr<int>(p));
	//ex12.11
	process(shared_ptr<int>(p.get()));
	//error First, don't use get to initialize or assign another smart pointer.
	//Second, the main function p will free the memory that has been freed inside preocess(). 

	cout << p.use_count() << endl;*/
	//ex12_20();

	//ex12_23();
	//ex12_26(6);
	//ex12_27();
	ex12_30();

	return 0;
}