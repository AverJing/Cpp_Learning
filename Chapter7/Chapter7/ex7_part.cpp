/*
*
*@author: AverJing
*@description: a part of excercise in CH7
*@date:Thursday, February 22, 2018
*
*/
#include <iostream>
#include "Sales_data.h"
#include "Screen.h"

using namespace std;

//revise the transaction-processing program to use member-combine()
void ex7_3() {
	Sales_data total;
	if (cin >> total) {
		Sales_data trans;
		while (cin >> trans) {
			if (total.ISBN() == trans.ISBN())
				total.combine(trans);
			else {
				cout << total;
				total = trans;
			}
		}
		cout << total;
	}
	else {
		cerr << "No data!" << endl;
	}
}

//use the istream constructor to rewrite ex7_3 program.
void ex7_13() {
	//think twice about it
	Sales_data total(cin);
	if (!total.ISBN().empty()) {
		istream &is = cin;
		while (is) {
			Sales_data trans(is);
			if (total.ISBN() == trans.ISBN())
				total.combine(trans);
			else {
				cout << total;
				total = trans;
			}
		}
		cout << total;
	}
	else {
		cerr << "No data!" << endl;
	}
}

//use delegating constructors.
void ex7_41() {
	cout << "1. default way: " << endl;
	cout << "----------------" << endl;
	Sales_data s1;

	cout << "\n2. use std::string as parameter: " << endl;
	cout << "----------------" << endl;
	Sales_data s2("CPP-Primer-5th");

	cout << "\n3. complete parameters: " << endl;
	cout << "----------------" << endl;
	Sales_data s3("CPP-Primer-5th", 3, 25.8);

	cout << "\n4. use istream as parameter: " << endl;
	cout << "----------------" << endl;
	Sales_data s4(std::cin);
}

//a literal class
void ex7_55() {
	struct Data {
		int ival;
		std::string s;
	};
	cout << std::boolalpha;
	cout << std::is_literal_type<Data>::value << std::endl;
}

int main(){
	//ex7_3();
	//ex7_13();
	//Screen myScreen(5, 5, 'X');
	//myScreen.move(4, 0).set('#').display(cout);
	//cout << "\n";
	//myScreen.display(cout);
	//cout << "\n";

	//ex7_41();
	ex7_55();
	return 0;
}