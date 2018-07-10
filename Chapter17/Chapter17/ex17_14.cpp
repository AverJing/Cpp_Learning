/*
*
*@author£ºAver Jing
*@description£º
* Write several regular expressions designed to trigger various errors.
* Run your program to see what output your compiler generates for each error.
*@date£º
*
*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	try {
		regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e)
	{
		cout << e.what() << " code: " << e.code() << endl;
	}

	return 0;
}