/*
*
*@author：Aver Jing
*@description：Write a function named compareIsbn that compares the
*isbn() members of two Sales_data objects. Use that function to sort a
*vector that holds Sales_data objects.
*@date：July 20, 2018
*
*/

#include<iostream>
#include "Sales_data.h"
#include "base_tool.h"

using namespace std;

bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2) {
	return sd1.ISBN() < sd2.ISBN();
}

void ex10_12() {
	Sales_data d1("CppPrimer"), d2("EssentialCpp"), d3("Cpp"), d4("GameEngine");
	vector<Sales_data> sdvec{ d1, d2, d3, d4 };

	//error:“void std::sort(const _RanIt, const _RanIt, _Pr)”: 未能为“_Pr”推导 模板 参数	Chapter10

	sort(sdvec.begin(), sdvec.end(), compareIsbn);

	Print(sdvec);
}

int main() {
	ex10_12();

	return 0;
}