/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>

using namespace std;

class function {
public:
	int operator()(int a, int b, int c) {
		return a > 0 ? b : c;
	}
};

int main() {
	function a;
	cout << a(2, 2, 0);

	return 0;
}