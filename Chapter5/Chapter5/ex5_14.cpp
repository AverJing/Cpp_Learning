/*
*
*@author£ºAver Jing
*@description£ºWrite a program to read strings from standard input
*looking for duplicated words. The program should find places in the input
*where one word is followed immediately by itself. Keep track of the largest
*number of times a single repetition occurs and which word is repeated. Print
*the maximum number of duplicates, or else print a message saying that no
*word was repeated. For example, if the input is
*how now now now brown cow cow
*the output should indicate that the word now occurred three times.
*@date£ºJuly 13, 2018
*
*/

#include<iostream>
#include <string>

using namespace std;

int main() {
	string s, pre, temp;
	int max = 1;
	int curr = 1;

	while (cin >> s) {
		if (pre == s) {
			++curr;
			if (curr > max)
				max = curr, temp = s;
		}
		pre = s;
	}

	if (max > 1)
		cout << temp << " occur " << max << " times." << endl;
	else
		cout << "No word was repeated." << endl;

	return 0;
}