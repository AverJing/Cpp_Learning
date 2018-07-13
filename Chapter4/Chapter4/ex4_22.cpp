/*
*
*@author£ºAver Jing
*@description£ºExtend the program that assigned high pass, pass, and fail
*grades to also assign low pass for grades between 60 and 75 inclusive. Write
*two versions: One version that uses only conditional operators; the other
*should use one or more if statements. Which version do you think is easier
*to understand and why?
*@date£ºJuly 13, 2018
*
*/

#include<iostream>
#include <string>

using namespace std;

int main() {
	int i;
	while (cin >> i) {
		string finalgrade;
		//First
		finalgrade = (i > 90) ? "high pass" : (i > 75) ? "pass" : (i > 60) ? "low pass" : "fali";
		//Second
		/*
		if (i > 90) {
			finalgrade = "high pass";
		}
		else if (i > 75) {
			finalgrade = "pass";
		}
		else if (i > 60)
			finalgrade = "low pass";
		else
			finalgrade = "fail";*/

		cout << finalgrade << endl;
	}

	return 0;
}