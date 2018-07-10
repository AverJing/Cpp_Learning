/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include <cassert>
#include <fstream>

//#include "ex17_4_findBook.h"
//#include "ex17_5_findBook.h"
#include "ex17_6_findBook.h"

vector<Sales_data> build_store(const string& s)
{
	vector<Sales_data> ret;
	std::ifstream is(s);
	Sales_data item;
	while (is >> item) ret.push_back(item);
	sort(ret.begin(), ret.end(),
		[](const Sales_data& lhs, const Sales_data& rhs) {
		return lhs.isbn() < rhs.isbn();
	}); //! need sort for equal_range to work
	return ret;
}

int main()
{
	// each element in files holds the transactions for a particular store
	vector<vector<Sales_data>> files;
	for (int cnt = 1; cnt <= 4; ++cnt)
		files.push_back(build_store("data/store" + std::to_string(cnt) + ".txt"));

	//EX04::reportResults(std::cin, std::cout, files);
	//EX05::reportResults(std::cin, std::cout, files);
	EX06::reportResults(std::cin, std::cout, files);
}

/* in ex17_6findBook.h
There are somes errors.
https://docs.microsoft.com/zh-cn/cpp/build/reference/force-force-file-output
https://docs.microsoft.com/zh-cn/cpp/build/reference/force-force-file-output

Use /FORCE to ignore the errors.
But do not know.
*/