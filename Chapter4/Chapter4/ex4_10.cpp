/*
*
*@author��Aver Jing
*@description��Write the condition for a while loop that would read ints
*from the standard input and stop when the value read is equal to 42.
*@date��July 13, 2018
*
*/

#include<iostream>

using namespace std;

int main() {
	int i;
	while (cin >> i && i != 42)
		cout << i << endl;

	return 0;
}