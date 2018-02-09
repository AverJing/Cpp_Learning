/*
*
*@author: AverJing
*@description: a part of excercise in CH6
*@date:Tuesday, February 6, 2018
*
*/
#include <iostream>
#include "Chapter6.h"
#include <vector>
#include <string>

using namespace std;

// Write and test your own version of fact.
void ex6_3(int val /*= 5*/) {
	int result = 1;
	int ival = val;
	while (val > 0) {
		result *= val--;
	}
	cout << ival << "! is " << result << endl;
}

//  Write  a  function  that  interacts  with  the  user,  asking  for  a
//number  and  generating  the  factorial  of  that  number.
void ex6_4() {
	int ival;
	while (cin >> ival) {
		ex6_3(ival);
	}
}

//Write a function to return the absolute value of its argument.
int ex6_5(int val) {
	return (val >= 0 ? val : -val);
}

void count_1(string & str, int val) {}
void count_2(const string & str, int val) {}

//  Write  a  function  that  takes  an  initializer_list<int>
//and produces the sum of the elements in the list.
int ex6_27(initializer_list<int> i1) {
	int sum = 0;
	for (auto &i : i1)
		sum += i;
	return sum;
}

// the function fails to provide a returnafter the if.
//this compiler can not detect this error.
bool test_return(const string &str1, const string &str2) {
	if (str2.size() > str2.size())
		return true;
}

// Write a recursive function to print the contents of a vector.
void ex6_33(const vector<int>::iterator beg,const vector<int>::iterator end) {
	if (beg != end) {
		cout << *beg << ' ';
		ex6_33(next(beg), end);
	}	
}

//  Give the second parameter of make_plural a default argument of 's'.
//Test  your  program  by  printing  singular  and plural versions of the words
//success and failure.
string ex6_42(size_t cnt, const string &str, const string & code = "s") {
	return (cnt > 1) ? str + code : str;
}

//
void ex6_47(const vector<int>::iterator beg, const vector<int>::iterator end) {
	#ifndef NDEBUG
	cout << " vector size is " << end - beg << endl;
	#endif
	if (beg != end) {
		cout << *beg << ' ';
		ex6_47(next(beg), end);
	}
}

inline int iadd(const int x, const int y) {
	return x + y;
}

inline int isub(const int x, const int y) {
	return x - y;
}

inline int imul(const int x, const int y) {
	return x * y;
}

inline int idev(const int x, const int y) {
	return x / y;
}

int f(int, int);
typedef decltype(f) * fp;

int f(int, int);
typedef decltype(f) fp2;

void ex6_54_55_56() {
	//v1.0
	//vector<fp> v = { &iadd, &isub, &imul, &idev };

	//for (auto begin = v.cbegin(), end = v.cend(); begin != end; ++begin) {
	//	cout << (*begin)(2, 2) << ' ';
	//}
	//cout << endl;

	//v2.0
	//vector<fp> v = { iadd, isub, imul, idev };//this place is different from v1.0

	//for (auto begin = v.cbegin(), end = v.cend(); begin != end; ++begin) {
	//	cout << (*begin)(2, 2) << ' ';
	//}
	//cout << endl;

	//v3.0
	vector<fp2 *> v = { &iadd, &isub, &imul, &idev };

	for (auto begin = v.cbegin(), end = v.cend(); begin != end; ++begin) {
		cout << (*begin)(2, 2) << ' ';
	}
	cout << endl;
}

int main(){
	//ex6_3(6);
	//ex6_4();
	//cout << "The absolute value of this parameter is " << ex6_5(-10) << endl;
	//count_1("abcdef", 1);  //error
	//count_2("abcdef", 1);  //right
	//cout << ex6_27({ 1,2,3,4,5 }) << endl; 
	/*vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	ex6_33(ivec.begin(), ivec.end());*/
	//cout << ex6_42(2, "failure") << ' ' << ex6_42(2, "sucess", "es")<< endl;
	//vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	//ex6_47(ivec.begin(), ivec.end());
	ex6_54_55_56();

	return 0;
}