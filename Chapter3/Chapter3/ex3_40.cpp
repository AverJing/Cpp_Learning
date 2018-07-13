/*
*
*@author£ºAver Jing
*@description£ºWrite a program to define two character arrays initialized
*from string literals. Now define a third character array to hold the
*concatenation of the two arrays. Use strcpy and strcat to copy the two
*arrays into the third.
*@date£ºJuly 12, 2018
*
*/

#include<iostream>
#include <string>

using namespace std;

int main() {
	char s1[] = "hello ", s2[] = "world";
	char s3[20];
	strcpy_s(s3, s1);
	strcat_s(s3, s2);
	cout << s3 << endl;

	return 0;
}