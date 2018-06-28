/*
*
*@author£ºAver Jing
*@description£º
* Test your print_total function from the exercises by passing both Quote and Bulk_quote 
*objects that function.
*@date£ºJune 25, 2018
*
*/

#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

int main() {
	Quote quote("0-201-78345-X", 23.8);
	print_total(cout, quote, 3);

	Bulk_quote bulk_quote("0-201-78345-X", 23.8, 3, 0.5);
	print_total(cout, bulk_quote, 4);

	return 0;
}