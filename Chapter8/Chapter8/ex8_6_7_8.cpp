/*
*
*@author£ºAver Jing
*@description£ºRewrite the bookstore program to read its transactions from a file.
*@date£ºJuly 18, 2018
*
*/

#include<iostream>
#include <fstream>
#include "Sales_data.h"

using namespace std;

void ex8_6(const string &fileName) {
	ifstream input(fileName);
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.ISBN() == trans.ISBN())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
	}
}

//Revise the previous program to write its output to a file.
void ex8_7(const string &ifile, const string &ofile) {
	ifstream input(ifile);
	ofstream output(ofile);
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.ISBN() == trans.ISBN())
				total.combine(trans);
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
	}
}

//Revise the previous program to write its output to a file.
void ex8_7(const string &ifile, const string &ofile) {
	ifstream input(ifile);
	ofstream output(ofile, ios::app);
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.ISBN() == trans.ISBN())
				total.combine(trans);
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
	}
}

int main() {

	return 0;
}