/*
*
*@author: AverJing
*@description: a part of excercise in CH8
*@date:Saturday, February 24, 2018
*
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Sales_data.h"

using namespace std;

//Write a function to open a file for input and read its contents into a vector
//of strings, storing each line as a separate element in the vector.
void ex8_4(const string &fileName, vector<string> &svec) {
	ifstream ifile(fileName, ios::in);
	
	if (ifile) {
		string str;
		while (getline(ifile, str) ){
			svec.push_back(str);
		}
	}	
}

//Rewrite the previous program to store each word in separate element
void ex8_5(const string &fileName, vector<string> &svec) {
	ifstream ifile(fileName, ios::in);
	if (ifile) {	
		string str;
		while (ifile >> str) {
			svec.push_back(str);
		}
	}
}

//Rewrite the bookstore program to read its transactions from a file.
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

//Revise the previous program to append its output to its given file.
//Run this program on the same output file at least twice to ensure the data are preserved. 
void ex8_8(const string &ifile, const string &ofile) {
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

//Write a program to store each line from a file in a vector<string>.
//Use isstringstream to read each element from the vector a word at a time.
//********** unfamiliar
void ex8_10(const string &fileName, vector<string> &svec) {
	ifstream ifle(fileName);
	if (ifle) {
		string str;
		while (getline(ifle, str))
			svec.push_back(str);
	}
	ifle.close();
	for (auto &str : svec) {
		string word;
		istringstream iss(str);
		while (iss >> word) cout << word << ' ';
		cout << endl;
	}
}

struct PersonInfo {
	string name;
	vector<string> phones;
};

void ex8_11(const string &fileName) {
	ifstream ifle(fileName);
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(ifle, line)) {
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word) info.phones.push_back(word);
		people.push_back(info);
	}

	for (auto& p : people) {
		cout << p.name << " ";
		for (auto& s : p.phones) cout << s << " ";
		cout << endl;
	}
}

bool valid(const string& str)
{
	return isdigit(str[0]);
}

string format(const string& str)
{
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}
//Rewrite the phone number program from this section  to read from  a named file 
//rather than from cin.
void ex8_13(const string &fileName) {
	ifstream ifle(fileName);
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(ifle, line)) {
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word) info.phones.push_back(word);
		people.push_back(info);
	}

	for (auto& p : people) {
		cout << p.name << " ";
		for (auto& s : p.phones) cout << s << " ";
		cout << endl;
	}

	for (const auto& entry : people) {
		ostringstream formatted, badNums;
		for (const auto& nums : entry.phones)
			if (!valid(nums))
				badNums << " " << nums;
			else
				formatted << " " << format(nums);
		if (badNums.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << " invalid number(s) "
			<< badNums.str() << endl;
	}
}

int main(){
	//ex8_1(cin);

	vector<string> svec;
	////ex8_4("input.txt", svec);
	//ex8_5("input.txt", svec);

	//for (auto begin = svec.cbegin(), end = svec.cend(); begin != end; ++begin)
	//	cout << *begin << endl;

	//ex8_6("data.txt");
	//ex8_7("data.txt", "result.txt");
	//ex8_8("data.txt", "result.txt");

	/*istringstream istr("hello");
	ex8_1(istr);*/

	//ex8_10("input.txt", svec);

	//ex8_11("Person.txt");
	ex8_13("Person.txt");
	return 0;
}