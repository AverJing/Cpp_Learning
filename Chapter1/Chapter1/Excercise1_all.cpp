/*
*
*@author: AverJing
*@description: as follows
*注释：     先CTRL+K，然后CTRL+C
*取消注释： 先CTRL+K，然后CTRL+U
*/
#include <iostream>
#include "Sales_item.h" 

using namespace std;

static float x;
static float y;

//print Hello, World on the standard output.
void ex1_3() {
	cout << "Hello, World." << endl;
}

//uses the multiplication operator *,return the result
float ex1_4() {
	return x * y;
}

//use a separate statement to print each operand.
void ex1_5() {
	cout << x;
	cout << '*';
	cout << y;
	cout << '=';
	cout << ex1_4();
	cout << endl;
}

//fix
void ex1_6() {
	cout << "The sum of " << x << " and " << y << " is " << x + y << endl;
}

//sum the numbers from 50 to 100 (use while)
int ex1_9() {
	int result = 0;
	int i = 50;
	while(i <= 100)
		result += i++;
	return result;
}

// prints the numbers from ten down to zero.(use while)
void ex1_10() {
	int i = 10;
	while (i > 0)
		cout << i-- << ' ';
	cout << endl;
}

// Print each number in the range specified by two integers.(use while)
void ex1_11() {
	int i = (x > y ? y : x);
	while ( i <= y || i <= x)
		cout << i++ << ' ';
	cout << endl;
}

//the loop sums the numbers from -100 to 100. the final value of sum is zero.
void ex1_12() {
	int sum = 0;
	for (int i = -100; i <= 100; ++i)
		sum += i;
	cout << sum << endl;
}

//sum the numbers from 50 to 100 (use for)
int ex1_13_1() {
	int result = 0;
	for (int i = 50; i <= 100;)
		result += i++;
	return result;
}

// prints the numbers from ten down to zero.(use while)
void ex1_13_2() {
	for (int i = 10; i >= 0; --i)
		cout << i << ' ';
	cout << endl;
}

// Print each number in the range specified by two integers.(use for)
//same as ex1_19
void ex1_13_3() {
	for (int i = (x > y ? y : x); i <= y || i <= x; ++i)
		cout << i << ' ';
	cout << endl;
}

void ex1_16() {
	int sum = 0;
	int tmp;
	while (cin >> tmp)
		sum += tmp;
	cout << sum << endl;
}

void ex1_17() {
	//currVal is the member we'are counting;we'll read new values into val.
	int currVal = 0, val = 0;
	if (cin >> currVal){
		int cnt = 1;//store the count for the current value we're processing
		while (cin >> val) {
			if (val == currVal)//if the valuese are the same
				++cnt;//add 1 to cnt
			else {
				cout << currVal << " occurs " << cnt << " times " << endl;
				currVal = val; //remember the new value 
				cnt = 1;   //reset the counter
			}
		}//while loop ends here
		cout << currVal << " occurs " << cnt << " times " << endl;

	}
}
//http://blog.csdn.net/qq_29883591/article/details/69183999
void ex1_20() {
	Sales_item item;
	while (cin >> item)
		cout << item << endl;
}

//Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.
void ex1_21() {
	Sales_item item1, item2;
	cin >> item1 >> item2;
	cout << item1 + item2 << endl;
}

//Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.
void ex1_22() {
	//same to ex1_25
	//this ex's logic is similar to ex1_23(C++ primer section 1.4.4)
	Sales_item total;
	if (cin >> total) {
		Sales_item trans;
		while (cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			}
			else {
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
}

//Write a program that reads several transactions and counts how many transactions occur for each ISBN.
void ex1_23() {
	//disadvantage: the same ISBN sequences must be continuous
	Sales_item currItem, valItem;
	if (cin >> currItem) {
		int cnt = 1;
		while (cin >> valItem) {
			if (currItem.isbn() == valItem.isbn())
				++cnt;
			else {
				cout << currItem << " occurs " << cnt << " times " << endl;
				currItem = valItem;
				cnt = 1;
			}
		}
		cout << currItem << " occurs " << cnt << " times " << endl;
	}
}

int main(){
	//cin >> x >> y;  //execute ex1_20; please pay attention to this statement  
	//ex1_3();
	/*
	cout << x << '*' << y << '=' << ex1_4() << endl;*/
	//ex1_5();
	//ex1_6();
	//cout <<ex1_9(); 
	//ex1_10();
	//ex1_11();
	//ex1_12();
	//cout << ex1_13_1();
	//ex1_13_2();
	//ex1_13_3();
	//ex1_16();
	//ex1_17();
	//ex1_20();
	//ex1_21();
	//ex1_22();
	//ex1_23();
	return 0;
}