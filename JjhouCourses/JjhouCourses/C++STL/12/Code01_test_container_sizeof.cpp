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
#include <map>
#include <list>
#include <queue>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <forward_list>
#include <set>
#include <stack>


using namespace std;

namespace jj25
{
	void test_components_sizeof()
	{
		cout << "\ntest_components_size().......... \n";

		//containers
		cout << "sizeof(array<int,100>)= " << sizeof(array<int, 100>) << endl;		//400
		cout << "sizeof(vector<int>)= " << sizeof(vector<int>) << endl;				//12
		cout << "sizeof(list<int>)= " << sizeof(list<int>) << endl;					//8
		cout << "sizeof(forward_list<int>)= " << sizeof(forward_list<int>) << endl;	//4
		cout << "sizeof(deque<int>)= " << sizeof(deque<int>) << endl;				//40
		cout << "sizeof(stack<int>)= " << sizeof(stack<int>) << endl;				//40
		cout << "sizeof(queue<int>)= " << sizeof(queue<int>) << endl;				//40
		cout << "sizeof(set<int>)= " << sizeof(set<int>) << endl;					//24
		cout << "sizeof(map<int,int>)= " << sizeof(map<int, int>) << endl;			//24
		cout << "sizeof(multiset<int>)= " << sizeof(multiset<int>) << endl;			//24
		cout << "sizeof(multimap<int,int>)= " << sizeof(multimap<int, int>) << endl;	//24
		cout << "sizeof(unordered_set<int>)= " << sizeof(unordered_set<int>) << endl;					//28
		cout << "sizeof(unordered_map<int,int>)= " << sizeof(unordered_map<int, int>) << endl;			//28	
		cout << "sizeof(unordered_multiset<int>)= " << sizeof(unordered_multiset<int>) << endl;			//28
		cout << "sizeof(unordered_multimap<int,int>)= " << sizeof(unordered_multimap<int, int>) << endl;	//28

		//iterators
		cout << "sizeof(array<int,100>::iterator)= " << sizeof(array<int, 100>::iterator) << endl;		//4
		cout << "sizeof(vector<int>::iterator)= " << sizeof(vector<int>::iterator) << endl;				//4
		cout << "sizeof(list<int>::iterator)= " << sizeof(list<int>::iterator) << endl;					//4
		cout << "sizeof(forward_list<int>::iterator)= " << sizeof(forward_list<int>::iterator) << endl; //4
		cout << "sizeof(deque<int>::iterator)= " << sizeof(deque<int>::iterator) << endl;				//16
		//! cout << "sizeof(stack<int>::iterator)= " << sizeof(stack<int>::iterator) << endl;	//[Error] 'iterator' is not a member of 'std::stack<int>'		
		//! cout << "sizeof(queue<int>::iterator)= " << sizeof(queue<int>::iterator) << endl;	//[Error] 'iterator' is not a member of 'std::queue<int>			
		cout << "sizeof(set<int>::iterator)= " << sizeof(set<int>::iterator) << endl;					//4
		cout << "sizeof(map<int,int>::iterator)= " << sizeof(map<int, int>::iterator) << endl;			//4
		cout << "sizeof(multiset<int>::iterator)= " << sizeof(multiset<int>::iterator) << endl;			//4
		cout << "sizeof(multimap<int,int>::iterator)= " << sizeof(multimap<int, int>::iterator) << endl;	//4
		cout << "sizeof(unordered_set<int>::iterator)= " << sizeof(unordered_set<int>::iterator) << endl;	//4	
		cout << "sizeof(unordered_map<int,int>::iterator)= " << sizeof(unordered_map<int, int>::iterator) << endl;	//4	
		cout << "sizeof(unordered_multiset<int>::iterator)= " << sizeof(unordered_multiset<int>::iterator) << endl;	//4
		cout << "sizeof(unordered_multimap<int,int>::iterator)= " << sizeof(unordered_multimap<int, int>::iterator) << endl;	//4										
	
		//VC++ 中差别很大
		//https://stackoverflow.com/questions/35015429/why-does-sizeofstdvectorint-return-16-bytes-when-it-appears-there-are-20
	}
}

int main(){
	jj25::test_components_sizeof();
}	