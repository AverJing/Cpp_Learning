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

using std::vector;

//Write a function that takes a pair of iterators to vector<int> and an int value.
//Look for the value int the range and return a bool indicating whether it was found.
bool ex9_3(vector<int>::const_iterator begin, vector<int>::const_iterator end, int temp) {
	for (auto iter = begin; iter != end; ++iter) {
		if (*iter == temp)
			return true;
	}
	return false;

	//or
	//find(begin, end, temp);
}


//Rewrite the previous program to return an iterator to the requested element.
vector<int>::const_iterator ex9_05(vector<int>::const_iterator begin, vector<int>::const_iterator end, int temp) {
	for (auto iter = begin; iter != end; ++iter) {
		if (*iter == temp)
			return iter;
	}
	return end;
}

int main(){
	
}	