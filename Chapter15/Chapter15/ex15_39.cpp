/*
*
*@author£ºAver Jing
*@description£º
* Implement the Query and Query_base classes. Test your application by evaluating and printing
*a query such as the one as followed.
*@date£ºJune 27, 2018
*
*/

#include<iostream>
#include <fstream>
#include "Query_base.h"

using namespace std;

int main() {
	Query q = Query("like") & Query("bird") | Query("wind");
	ifstream infile("query.txt");
	TextQueryTem f(infile);
	print(cout, q.eval(f));

	return 0;
}