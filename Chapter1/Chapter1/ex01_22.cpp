/*
*
*@author£ºAver Jing
*@description£ºWrite a program that reads several transactions for the same
*ISBN. Write the sum of all the transactions that were read.
*@date£ºJuly 10, 2018
*
*/

#include<iostream>
#include "Sales_item.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	Sales_item total;
	if (cin >> total) {
		Sales_item tran;
		while (cin >> tran)
		{
			if (total.isbn() == tran.isbn())
				total += tran;
		}
		cout << total << endl;
	}
	else {
		cout << "no data." << endl;
	}

	return 0;
}