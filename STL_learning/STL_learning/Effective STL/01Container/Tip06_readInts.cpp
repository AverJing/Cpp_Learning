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
#include <fstream>
#include <sstream>
#include <iterator>
#include <list>

int g(double(*pf) ());
int g(double pf ());
int g(double  ());
//same meaning,

int main(){
	//attention file path, in STL_learning
	std::ifstream ifile("Effective STL/01Container/ints.dat");
	//std::istringstream str("0 1 2 3 4");
	/*
	std::list<int> ilst((std::istream_iterator<int>(ifile)),
		std::istream_iterator<int>());*/
	//std::istream_iterator<int> dataBegin(str);
	std::istream_iterator<int> dataBegin(ifile);
	std::istream_iterator<int> dataEnd;
	std::list<int> ilst(dataBegin, dataEnd);
	//attention, compiler regard ilst as a function
	for (auto e : ilst) {
		std::cout << e << ' ';
	}

	//std::list<int> l1{ 1,2,3,4 };
	//std::list<int> l2(l1.begin(), l1.end());
}	