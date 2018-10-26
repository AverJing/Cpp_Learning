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
#include <vector>
#include <string>

using std::vector;
using std::string;

/*
//bad idea
struct func {
	double operator()(const string& s, std::size_t* p) const  {
		return std::stod(s, p);
	}
	int operator()(const string& s, std::size_t* p, int base) const {
		return std::stoi(s, p);
	}
};

//args ...
template<typename T>
void ex09_50(const vector<string>& para, const func& f = func(), bool type = false) {
	T result = T();
	for (auto &e : para) {
		if (!type) result += f(e, 0);
		else result += f(e, 0, 10);
	}
	std::cout << " sum of double is " << result << std::endl;
}*/

double fun1(const string& s, std::size_t* p) {
	return std::stod(s, p);
}
int fun2(const string& s, std::size_t* p) {
	return std::stoi(s, p);
}

template<typename T, typename... Args>
void ex09_50(const vector<string>& para, T (*p)(Args... args)) {
	T result = T();
	for (auto &e : para) {
		result += p(e, 0);
	}
	std::cout << " sum of double is " << result << std::endl;
}

int main(){
	vector<string> dvec{ "1.2", "3.4", "5.6" };
	vector<string> ivec{ "1", "3", "5" };
	/*
	func f;
	ex09_50<double>(dvec);
	ex09_50<int>(ivec, func(), true);*/
	ex09_50<double>(dvec, fun1);
	ex09_50<int>(ivec, fun2);
}	