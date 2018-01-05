/*
*
*@author: AverJing
*@description: as follows
*
*/
#include <iostream>
#include <typeinfo>
#include "Sales_data.h"

using namespace std;

//http://blog.csdn.net/markl22222/article/details/25928597
void ex2_35() {
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;

	cout << "i  is " << typeid(i).name() << "\n";
	cout << "j  is " << typeid(j).name() << "\n";
	cout << "k  is " << typeid(k).name() << "\n";
	cout << "p  is " << typeid(p).name() << "\n";
	cout << "j2 is " << typeid(j2).name() << "\n";
	cout << "k2 is " << typeid(k2).name() << "\n";

	cout << endl;
	cout << boolalpha;

	cout << "i and j  have same type? "
		<< is_same<decltype(i), decltype(j)>::value << "\n";
	cout << "i and k  have same type? "
		<< is_same<decltype(i), decltype(k)>::value << "\n";
	cout << "i and j2 have same type? "
		<< is_same<decltype(i), decltype(j2)>::value << "\n";
	cout << "j and j2 have same type? "
		<< is_same<decltype(j), decltype(j2)>::value << "\n";
	cout << "k and k2 have same type? "
		<< is_same<decltype(k), decltype(k2)>::value << "\n";
}

//ex1_20
void ex2_41_1() {
	Sales_data curr_data;
	while (cin >> curr_data)
		cout << curr_data;
}

//ex1_21
void ex2_42_2() {
	Sales_data val1, val2;
	cin >> val1 >> val2;
	if (val1.ISBN() == val2.ISBN())
		val1 += val2;
	cout << val1;
}

//ex1_22
void ex2_42_3() {
	Sales_data total;
	if (cin >> total) {
		Sales_data trans;
		while (cin >> trans) {
			if (total.ISBN() == trans.ISBN())
				total += trans;
			else {
				cout << total;
				total = trans;
			}
		}
		cout << total;
	}
}

//ex1_23
void ex2_42_4() {
	Sales_data total;
	if (cin >> total) {
		int cnt = 1;
		Sales_data trans;
		while (cin >> trans) {
			if (total.ISBN() == trans.ISBN())
				++cnt;
			else {
				cout << total << " occurs " << cnt << " times " << endl;
				cnt = 1;;
				total = trans;
			}
		}
		cout << total << " occurs " << cnt << " times " << endl;
	}
}

int main(){
	//ex2_35();
	//ex2_41_1();
	//ex2_42_2();
	//ex2_42_3();
	//ex2_42_4();
	return 0;
}