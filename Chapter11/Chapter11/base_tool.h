#pragma once
#pragma once
#ifndef BASIC_TOOL
#define BASIC_TOOL

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<class T>
void Print(const T &t) {
	for (auto &e : t)
		std::cout << e << ' ';
	cout << endl;
}
#endif // !BASIC_TOOL
