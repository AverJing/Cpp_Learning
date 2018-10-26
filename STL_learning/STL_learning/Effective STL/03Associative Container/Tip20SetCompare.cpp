/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>
#include <string>
#include <set>

using std::set;
using std::string;

bool compare(string lhs, string rhs) {
	return lhs < rhs;
}

struct Compare {
	bool operator()(string lhs, string rhs) {
		return lhs < rhs;
	}
};

int main(){
	set<string, compare> s;
	set<string, Compare> s2;
}	