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
#include <ctime>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using std::string;
using std::endl;
using std::cout;

template<class T>
void testContainer(T data, int length, const string& containerName);

int main(){

	//testContainer(std::vector<int>{}, 3000000, "vector<int>");

	testContainer(std::set<int>{}, 3000000, "set<int>");
	testContainer(std::unordered_set<int>{}, 3000000, "unordered_set<int>");
	testContainer(std::deque<int>{}, 3000000, "deque<int>");

//#define LIST
	//testContainer(std::list<int>{}, 3000000, "vector<int>");
}	

template<class T>
void testContainer(T data, int length, const string& containerName)
{
	typedef T::value_type Type;  //default is int
	auto timestart = clock();
	for (int i = 0; i < length; ++i) {
		data.insert(data.end(), Type(rand()));
	}
	std::cout << "insert mills-seconds: " << (clock() - timestart) << std::endl;
	cout << containerName << ".size() " << data.size() << endl;
	//cout << containerName << ".capacity() " << data.capacity() << endl;

#if  (defined LIST) || (defined FORWARD_LIST)
	timestart = clock();//list
	data.sort();
	std::cout << "sort mills-seconds: " << (clock() - timestart) << std::endl;
#endif // DEFAULT
}
