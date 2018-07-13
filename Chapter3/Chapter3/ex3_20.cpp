/*
*
*@author：Aver Jing
*@description：Read a set of integers into a vector. Print the sum of each
*pair of adjacent elements. Change your program so that it prints the sum of
*the first and last elements, followed by the sum of the second and second-tolast,
*and so on.
*@date：July 12, 2018
*
*/

#include<iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	int x;
	vector<int> ivec;
	while (cin >> x)
		ivec.push_back(x);
	for (auto &e : ivec)
		cout << e << ' ';
	cout << endl;
	/*
	for (decltype(ivec.size()) i = 0; i != ivec.size(); ++i) {
		if (i + 1 < ivec.size())
			cout << ivec[i] + ivec[++i] << ' '; //Attention: 加号运算符两侧不一定谁先运算
		else
			cout << ivec[i] << endl;
	}*/
	//fix
	for (decltype(ivec.size()) i = 0; i < ivec.size(); i+=2) {
		//the sum of each pair of adjacent elements
		if (i + 1 < ivec.size())
			cout << ivec[i] + ivec[i + 1] << ' ';
		else
			cout << ivec[i];
	}
	cout << endl;

	for (decltype(ivec.size()) i = 0, j = ivec.size() - 1; i <= j; ++i, --j) {
		if (i == j)
			cout << ivec[i] << ' ';
		else
			cout << ivec[i] + ivec[j] << ' ';
	}
	cout << endl;

	return 0;
}