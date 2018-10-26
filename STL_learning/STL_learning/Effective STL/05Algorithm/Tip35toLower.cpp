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
#include <cctype>
#include <functional>
#include <algorithm>
#include <string>

using std::string;
using std::function;

/*
template<typename Fuck>
function<bool(Fuck)> not1(function<bool(Fuck)> pred)
{
	return [pred](Fuck fuck) {return !pred(fuck); };
}

template<typename Fuck, typename Shit>
function<bool(Fuck, Shit)> not2(function<bool(Fuck, Shit)> pred)
{
	//lambda
	return [pred](Fuck fuck, Shit shit) {return !pred(fuck, shit); };
}*/

bool ciCharLess(char c1, char c2) {
	return tolower(static_cast<unsigned int>(c1)) < tolower(static_cast<unsigned int>(c2));
}
//必须严格弱序
bool ciStringCompare(const string& s1, const string& s2) {
	return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
		ciCharLess);
}

int main(){
	//auto i = tolower('c');
	std::cout << ciStringCompare("Hello", "helLoi");
}	