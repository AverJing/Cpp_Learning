#pragma once
#ifndef EX17_5_FINDBOOK_H
#define EX17_5_FINDBOOK_H

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <utility>
#include "Sales_data.h"

using std::tuple;
using std::vector;
using std::string;
using std::pair;

namespace EX05 {
	typedef pair<
		vector<vector<Sales_data>>::size_type,
		pair<vector<Sales_data>::const_iterator,
		vector<Sales_data>::const_iterator>
	> matches;

	bool compareIsbn(const Sales_data& lhs,const Sales_data& rhs) {
		return lhs.isbn() < rhs.isbn();
	}

	vector<matches> findBook(const vector<vector<Sales_data>> &files, const string& book) {
		vector<matches> ret;
		for (auto it = files.cbegin(); it != files.cend(); ++it) {
			auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
			if (found.first != found.second)
				ret.push_back(make_pair(it - files.cbegin(), make_pair(found.first, found.second)));
		}
		return ret;
	}

	void reportResults(std::istream& in, std::ostream& os, const vector<vector<Sales_data>>& files) {
		string s;
		while (in >> s) {
			auto tran = findBook(files, s);
			if (tran.empty()) {
				std::cout << s << " not found in any stores" << std::endl;
				continue;
			}
			for (const auto &store : tran) {
				os << "store " << store.first << " sales: "
					<< std::accumulate(store.second.first, store.second.second, Sales_data(s)) << std::endl;
			}
		}
	}
}

#endif // !EX17_5_FINDBOOK_H
