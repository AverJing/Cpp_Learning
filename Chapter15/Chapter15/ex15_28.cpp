/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>
#include <vector>
#include <memory>
#include <numeric>
#include <algorithm>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

int main() {
	vector<shared_ptr<Quote>> qvec;
	qvec.push_back(make_shared<Quote>("1", 10));
	qvec.push_back(make_shared<Quote>("2", 20));
	qvec.push_back(make_shared<Bulk_quote>("3", 30, 3, 0.5));
	
	/*
	double sum = 0;
	for (auto &e : qvec)
		sum += e->net_price(5);
	*/

	double sum = accumulate(qvec.cbegin(), qvec.cend(), 0.0, [](double ret, const shared_ptr<Quote> obj) {
		return ret += obj->net_price(5);
	});

	cout << sum << endl;
	return 0;
}