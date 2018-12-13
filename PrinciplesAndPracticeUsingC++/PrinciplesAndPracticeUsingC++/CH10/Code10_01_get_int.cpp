/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>
#include <cctype>
#include <string>

using std::cout;
using std::cin;
using std::string;

//结合教材，好好品味，从最初的代码如何变为这样。
void skip_to_int() {
	if (cin.fail()) {
		cin.clear();
		for (char ch; cin >> ch;) {
			if (std::isdigit(ch) || ch == '-') {
				cin.unget();
				return;
			}
		}
	}
	//eof or bad, throw
}

int get_int() {
	int n = 0;
	while (true) {
		if (cin >> n) return n;
		cout << "Sorry, that was not a number; please try again\n";
		skip_to_int();//fail
	}
}

int get_int(int low, int up, const string& greeting, const string& sorry) {
	cout << greeting << ":[ " << low << ':' << up << "]\n";

	while (true) {
		int n = get_int();
		if (n >= low && n <= up) return n;
		cout << sorry << ":[ " << low << ':' << up << "]\n";
	}
}

int main(){
	cin.exceptions(cin.exceptions() | std::ios_base::badbit);//cin处于bad时，抛出一个异常
	std::cout << get_int(0, 100, "Plase enter num", "Not in range, try again");
}	