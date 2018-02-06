/*
*
*@author: AverJing
*@description: a part of excercise in CH5
*@date:Saturday, January 27, 2018
*
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Using  an if¨Celse statement, write  your  own  version  of  the
//program to generate the letter grade from a numeric grade.
void ex5_5() {
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	int grade{0};
	while (cin >> grade) {
		string lettergrade;
		if (grade < 60)
			lettergrade = scores[0];
		else {
			lettergrade = scores[(grade - 50) / 10];
			if (grade != 100)
				if (grade % 10 > 7)
					lettergrade += '+';
				else if (grade % 10 < 3)
					lettergrade += '-';
		}
		cout << lettergrade << endl;
	}
	
}

//Rewrite your grading program to use the conditional operator
//in place of the if-else statement
void ex5_6() {
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	int grade{ 0 };
	while (cin >> grade) {
		string lettergrade = (grade < 60 ? scores[0] : scores[(grade - 50) / 10]);
		lettergrade += ((grade == 100 || grade < 60) ? "" :
			((grade % 10 > 7 ? "+" : (grade % 10 < 3) ? "-" : "")));

		cout << lettergrade << endl;
	}
}

//Write a program using a series of if statements to count the
//number of vowels in text read from cin.
void ex5_9() {
	char text;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	while (cin >> text) {
		if (text == 'a')
			++aCnt;
		if (text == 'e')
			++eCnt;
		if (text == 'i')
			++iCnt;
		if (text == 'o')
			++oCnt;
		if (text == 'u')
			++uCnt;
	}
	cout << "The number of  vowel a is \t" << aCnt << endl;
	cout << "The number of  vowel e is \t" << eCnt << endl;
	cout << "The number of  vowel i is \t" << iCnt << endl;
	cout << "The number of  vowel o is \t" << oCnt << endl;
	cout << "The number of  vowel u is \t" << uCnt << endl;
}

//improve ex5_9 to count both lower and uppercase letter 
void ex5_10() {
	char text;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	while (cin >> text) {
		text = tolower(text);
		if (text == 'a')
			++aCnt;
		if (text == 'e')
			++eCnt;
		if (text == 'i')
			++iCnt;
		if (text == 'o')
			++oCnt;
		if (text == 'u')
			++uCnt;
	}
	cout << "The number of  vowel a is \t" << aCnt << endl;
	cout << "The number of  vowel e is \t" << eCnt << endl;
	cout << "The number of  vowel i is \t" << iCnt << endl;
	cout << "The number of  vowel o is \t" << oCnt << endl;
	cout << "The number of  vowel u is \t" << uCnt << endl;
}

//Modify our vowel - counting program so that it also counts the
//number of blank spaces, tabs, and newlines read.
void ex5_11() {
	char text; 
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newCnt = 0;
	while (cin >> noskipws >> text) {//Do not skip whitespaces
		switch (text) {
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
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newCnt;
			break;
		}
	}
	cout << "The number of  vowel a is \t" << aCnt << endl;
	cout << "The number of  vowel e is \t" << eCnt << endl;
	cout << "The number of  vowel i is \t" << iCnt << endl;
	cout << "The number of  vowel o is \t" << oCnt << endl;
	cout << "The number of  vowel u is \t" << uCnt << endl;
	cout << "The number of space is \t" << spaceCnt << endl;
	cout << "The number of tab is \t" << tabCnt << endl;
	cout << "The number of newline is \t" << newCnt << endl;
}

void ex5_11_2() {
	char text;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newCnt = 0;
	while (cin >> noskipws >> text) {//Do not skip whitespaces
		switch (toupper(text)) {
		case 'A':
			++aCnt;
			break;
		case 'E':
			++eCnt;
			break;
		case 'I':
			++iCnt;
			break;
		case 'O':
			++oCnt;
			break;
		case 'U':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newCnt;
			break;
		}
	}
	cout << "The number of  vowel a is \t" << aCnt << endl;
	cout << "The number of  vowel e is \t" << eCnt << endl;
	cout << "The number of  vowel i is \t" << iCnt << endl;
	cout << "The number of  vowel o is \t" << oCnt << endl;
	cout << "The number of  vowel u is \t" << uCnt << endl;
	cout << "The number of space is \t" << spaceCnt << endl;
	cout << "The number of tab is \t" << tabCnt << endl;
	cout << "The number of newline is \t" << newCnt << endl;
}

//Modify  our  vowel - counting  program  so  that  it  counts  the
//number  of  occurrences  of  the  following  two - character  sequences :
//ff,fl,and fi.
void ex5_12() {
	char text, prech = '\0';
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newCnt = 0,
		ffCnt = 0, flCnt = 0, fiCnt = 0;
	while (cin >> noskipws >> text) {//Do not skip whitespaces
		switch (text) {
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
			if (prech == 'f') ++fiCnt;
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
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newCnt;
			break;
		case 'f':
			if (prech == 'f') ++ffCnt;
			break;
		case 'l':
			if (prech == 'f') ++flCnt;
			break;
		}
		prech = text;
	}
	cout << "The number of  vowel a is \t" << aCnt << endl;
	cout << "The number of  vowel e is \t" << eCnt << endl;
	cout << "The number of  vowel i is \t" << iCnt << endl;
	cout << "The number of  vowel o is \t" << oCnt << endl;
	cout << "The number of  vowel u is \t" << uCnt << endl;
	cout << "The number of space is \t" << spaceCnt << endl;
	cout << "The number of tab is \t" << tabCnt << endl;
	cout << "The number of newline is \t" << newCnt << endl;
	cout << "The number of ff is \t" << ffCnt << endl;
	cout << "The number of fl is \t" << flCnt << endl;
	cout << "The number of fi is \t" << fiCnt << endl;
}

//Variable Definitions inside the Body of a switch
void test_switch_inside_variable() {
	
	switch (2) {
	case 1:
		//int i = 2;//error:initialization of 'i' is skipped by 'case' label
		int i;//ok
		cout << 2 << endl;
		break;
	case 2:
		i = 4;
		cout << 4 << endl;
		break;
	}
}

//Write  a  program  to  read strings  from  standard  input
//looking  for  duplicated  words.
void ex5_14() {
	string word, preword;
	int cnt = 1, maxCnt = 1;
	string tempWord;
	while (cin >> word) {
		if (word == preword) {
			++cnt;
			if (cnt > maxCnt) {
				maxCnt = cnt;
				tempWord = word;
			}
				
		}
		preword = word;
	}
	if (maxCnt == 1)
		cout << "No duplicated words." << endl;
	else
		cout << tempWord << " occured " << maxCnt << " times." << endl;
}

//write  a  program  to  determine whether  one vector is  a  prefix  of  the  other.
void ex5_17() {
	vector<int> ivec1{ 0, 1, 1, 2 };
	vector<int> ivec2{ 0, 1, 1, 2, 3, 5, 8 };
	int size = 0;

	for (auto ivec1_begin = ivec1.begin(), ivec2_begin = ivec2.begin();
		ivec1_begin < ivec1.end() && ivec2_begin < ivec2.end();
		++ivec1_begin, ++ivec2_begin) {
		if (*ivec1_begin == *ivec2_begin)
			++size;
		else
			break;
	}
	if (size == ((ivec1.size() < ivec2.size()) ? ivec1.size() : ivec2.size()))
		cout << "ture" << endl;

	/*
	vector<int> vec1{0, 1, 1, 2};
	vector<int> vec2{0, 1, 1, 2, 3, 5, 8};

	auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
	for (decltype(vec1.size()) i = 0; i != size; ++i) {
	if (vec1[i] != vec2[i]) {
	cout << "false" << endl;
	return 0;
	}
	}
	cout << "true" << endl;
	*/
}

//  Write  a  program  that  uses  a  do while loop  to  repetitively
//request  two strings  from  the  user  and  report  which
//string is  less  than the other.
void ex5_19() {
	string rsp;
	do {
		cout << "Input two strings: ";
		string str1, str2;
		cin >> str1 >> str2;
		cout << (str1 <= str2 ? str1 : str2) << " is less than the other. "
			<< "\n\n"
			<< "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] == 'y');
}

//  Write  a  program  to  read  a  sequence  of strings  from  the
//standard  input  until  either  the  same  word  occurs  twice  in  succession or all
//the words have been read.
void ex5_20() {
	string str, pre_str;
	int cnt = 0;

	while (cin >> str) {
		if (str == pre_str) {
			++cnt;
			cout << "the repeated word is " << pre_str << endl;
			break;
		}
		else
			pre_str = str;
	}
	if (!cnt)
		cout << "no word occured two times." << endl;

	/*
	string read, tmp;
	while (cin >> read)
	if (read == tmp)
	break;
	else
	tmp = read;

	if (cin.eof())
	cout << "no word was repeated." << endl;
	else
	cout << read << " occurs twice in succession." << endl;
	*/
}

//  Revise  the  program(ex5_20()) 
//so that it looks only for duplicated words that start with an uppercase letter.
void ex5_21() {
	string curr, prev;
	bool no_twice = false;

	while (cin >> curr) {
		if (!isupper(curr[0]))
			continue;
		if (prev == curr) {
			cout << curr << " occurs twice in succession." << endl;
			no_twice = true;
			break;
		}
		else
			prev = curr;
	}

	if (!no_twice) cout << "no word was repeated." << endl;
}

//  Write  a  program  that  reads  two  integers  from  the  standard
//input and prints the result of dividing the first number by the second.
void ex5_23() {
	int a, b;
	cin >> a >> b;
	cout << static_cast<double>(a) / b << endl;
}

//  Revise  your  program  to  throw  an  exception  if  the  second
//number is zero.
void ex5_24() {
	int a, b;
	cin >> a >> b;

	if (b == 0) throw runtime_error("divisor is 0");

	cout << static_cast<double>(a) / b << endl;
}

//  Revise  your  program  from  the  previous  exercise  to  use  a
//try block to catch the exception.
void ex5_25() {
	int a, b;
	cout << "Input two integers: ";
	while (cin >> a >> b) {
		try {
			if (b == 0) throw runtime_error("divisor is 0");
			cout << static_cast<double>(a) / b << endl;
			cout << "Input two integers: ";
		}
		catch (runtime_error err) {
			cout << err.what();
			cout << "\nTry Again? Enter y or n:" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
	}
}
int main(){
	//ex5_5();
	//ex5_6();
	//ex5_9();
	//ex5_10();
	//ex5_11();
	//ex5_12();
	//test_switch_inside_variable();
	//ex5_14();
	//ex5_17();
	//ex5_19();
	//ex5_20();
	//ex5_21();
	//ex5_23();
	//ex5_24();
	ex5_25();
	return 0;
}