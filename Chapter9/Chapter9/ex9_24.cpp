/*
*
*@author£ºAver Jing
*@description£ºWrite a program that fetches the first element in a vector
*using at, the subscript operator, front, and begin. Test your program on
*an empty vector.
*@date£ºJuly 18, 2018
*
*/

#include<iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> ivec{ 1 };
	auto begin = ivec.begin();
	cout << ivec.at(0)
		<< ivec[0]
		<< *begin
		<< ivec.front();

	return 0;
}