/*
*
*@author£ºAver Jing
*@description£ºWrite versions of numbered and f corresponding to the previous three 
*exercises and check whether you correctly predicted the output.
*@date£ºJune 5, 2018
*
*/

#include<iostream>

using namespace std;

static int count = 0;

struct numbered
{
	numbered(): mysn(::count++){}
	numbered(const numbered& rhs) { mysn = ::count++; }
	int mysn;
};
/*
void f(numbered s) {
	cout << s.mysn << endl;
}
*/
void f(const numbered& s) {
	cout << s.mysn << endl;
}

int main() {
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}