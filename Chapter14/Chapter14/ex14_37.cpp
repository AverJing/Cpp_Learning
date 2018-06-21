/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IsEqual {
public:
	IsEqual(int i) :value(i) {}
	bool operator()(int i) {
		return value == i;
	}
private:
	int value;
};

int main() {
	IsEqual eq(1);
	vector<int> ivec{ 1,2,3,4,5,6,1,1,1,1,1 };
	replace_if(ivec.begin(), ivec.end(), IsEqual(1), 5);
	for (auto &e : ivec)
		cout << e << ' ';
	cout << endl;

	return 0;
}