/*
*
*@author£ºAver Jing
*@description£ºRewrite exercise 10.12 from ¡ì 10.3.1 (p. 387) to use a
*lambda in the call to sort instead of the compareIsbn function.
*@date£ºJuly 20, 2018
*
*/

#include<iostream>
#include "Sales_data.h"
#include "base_tool.h"

using namespace std;

void ex10_17() {
	Sales_data d1("CppPrimer"), d2("EssentialCpp"), d3("Cpp"), d4("GameEngine");
	vector<Sales_data> sdvec{ d1, d2, d3, d4 };

	sort(sdvec.begin(), sdvec.end(), [](Sales_data const& lhs, Sales_data const& rhs) {return lhs.ISBN() < rhs.ISBN(); });

	Print(sdvec);
}

int main() {

	return 0;
}