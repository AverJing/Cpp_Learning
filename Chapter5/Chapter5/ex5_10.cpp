/*
*
*@author£ºAver Jing
*@description£º There is one problem with our vowel-counting program as
*we¡¯ve implemented it: It doesn¡¯t count capital letters as vowels. Write a
*program that counts both lower- and uppercase letters as the appropriate
*vowel¡ªthat is, your program should count both 'a' and 'A' as part of
*aCnt, and so forth.
*@date£ºJuly 13, 2018
*
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while (cin >> ch) switch (ch) {
	case 'a':
	case 'A':
		++aCnt;
		break;
	case 'e':
	case 'E':
		++eCnt;
		break;
	case 'i':
	case 'I':
		++iCnt;
		break;
	case 'o':
	case 'O':
		++oCnt;
		break;
	case 'u':
	case 'U':
		++uCnt;
		break;
	}

	cout << "Number of vowel a(A): \t" << aCnt << '\n'
		<< "Number of vowel e(E): \t" << eCnt << '\n'
		<< "Number of vowel i(I): \t" << iCnt << '\n'
		<< "Number of vowel o(O): \t" << oCnt << '\n'
		<< "Number of vowel u(U): \t" << uCnt << endl;

	return 0;
}