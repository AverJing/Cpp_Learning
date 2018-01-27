/*
*
*@author: AverJing
*@description:excercise of CH4
*@date:Tuesday, January 9, 2018
*
*/
#include <iostream>
#include <vector>

using namespace std;

//  Write  a  program  to  use  a  conditional  operator  to  find  the elements  in  a
//vector<int> that  have  odd  value  and  double  the  value  of each such element.
void ex4_21(vector<int> &vec) {
	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		if (*iter % 2)
			*iter *= 2;
	}
	for (auto const &i : vec)
		cout << i << ' ';
	cout << endl;
}

// first version(only use conditional operators)
void ex4_22_1() {
	unsigned grade;
	while (cin >> grade) {

		cout << ((grade > 90) ? "high pass" : (grade < 60)
			? "fail"
			: (grade < 75) ? "low pass"
			: "pass");
		cout << endl;
	}
}

// second version(only use if statements)
void ex4_22_2() {
	unsigned grade;
	while (cin >> grade) {
		if (grade > 90)
			cout << "high pass";
		else if (grade < 60)
			cout << "fail";
		else if (grade < 75)
			cout << "low pass";
		else
			cout << "pass";
		cout << endl;
	}
}

void ex4_33() {
	int x = 4, y = 7;
	cout << (0 ? ++x, --y : --x, ++y) << endl;
}

int main(){
	/*vector<int> ivec = { 1,2,3,4,5,6 };
	ex4_21(ivec);*/
	ex4_33();

	return 0;
}