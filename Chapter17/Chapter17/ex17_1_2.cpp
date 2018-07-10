/*
*
*@author£ºAver Jing
*@description£º
* Define a tuple that holds three int values and intialize the members to 10, 20, and 30
*@date£ºJuly 5, 2018
*
*/

#include <iostream>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int main() {
	tuple<int, int, int> it{ 10,20,30 };

	tuple<string, vector<string>, pair<string, int>> st;

	return 0;
}