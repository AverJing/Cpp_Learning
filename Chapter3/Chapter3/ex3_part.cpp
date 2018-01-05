/*
*
*@author: AverJing
*@description: a part of ch3 excercises
*
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// read the standard input a line at a time.
void ex3_2_1() {
	string sval;
	while(getline(cin, sval))
		cout << sval << endl;
}

// read the standard input a word at a time
void ex3_2_2() {
	string sval;
	while (cin>>sval)
		cout << sval << ' ';
	cout << endl;
}

// read two strings and report whether the strings are equal
// If not, report which of the two is larger.
void ex3_4_1() {
	string sval1, sval2;
	//while(cin >> sval1 >> sval2)
	cin >> sval1 >> sval2;
		if (sval1 == sval2)
			cout << " sval1 is equal to sval2." << endl;
		else
			cout << (sval1 > sval2 ? sval1 : sval2) << endl;
}

// read two strings and report whether the strings have the same length
// If not, report which is longer
void ex3_4_2() {
	string sval1, sval2;
	//while(cin >> sval1 >> sval2)
	cin >> sval1 >> sval2;
	if (sval1.size() == sval2.size())
		cout << " the length of sval1 is equal to sval2's." << endl;
	else
		cout << (sval1.size() > sval2.size() ? sval1 : sval2) << endl;
}

// read strings from the standard input, concatenating what is read into one
// large string.
// Print the concatenated string.
void ex3_5_1() {
	string stotal;
	string temp;
	while (cin >> temp)
		stotal += temp;
	cout << stotal << endl;
}

// separate adjacent input strings by a space.
void ex3_5_2() {
	string stotal;
	string temp;
	while (cin >> temp)
		stotal += temp + ' ';
	cout << stotal << endl;
}

// Use a range for to change all the characters in a string to X.
void ex3_6() {
	string sval;
	cin >> sval;
	for (auto &c : sval)
		c = 'X';
	cout << sval << endl;
}

// Use while to change all the characters in a string to X.
void ex3_8_1() {
	string sval;
	cin >> sval;
	decltype(sval.size()) i = 0;

	while (i < sval.size())
		sval[i++] = 'X';
	cout << sval << endl;
}

// Use for to change all the characters in a string to X.
void ex3_8_2() {
	string sval;
	cin >> sval;

	for(decltype(sval.size()) i = 0; i < sval.size(); ++i)
		sval[i] = 'X';
	cout << sval << endl;
}

// reads a string of characters including punctuation and writes what was read
// but with the punctuation removed.
void ex3_10() {
	string sval, result;
	getline(cin, sval);
	for(const auto c : sval ) {
		if (!ispunct(c))
			result += c;
	}
	sval = result;
	cout << sval << endl;
}

/// read a sequence of ints from cin and
/// store those values in a vector.
void ex3_14() {
	int i;
	vector<int> ivec;
	while (cin >> i)
		ivec.push_back(i);
	for (const auto &i : ivec)
		cout << i << ' ';
	cout << endl;
}

/// read a sequence of strings from cin and
/// store those values in a vector.
void ex3_15() {
	string sval;
	vector<string> svec;
	while (cin >> sval)
		svec.push_back(sval);
	for (const auto &s : svec)
		cout << s << ' ';
	cout << endl;

}

/// print the size and contents of the vectors from exercise 3.13.
/// Check whether your answers to that exercise were correct.
/// If not, restudy ¡ì 3.3.1 (p. 97) until you understand why you were wrong.
template<class type>
void ex3_16_print(const type &t_vec, const string &name) {
	cout << "{ \" " << name << "\":{\"size\":\"" << t_vec.size() << "\",\"value\":[";
	for (const auto &i : t_vec) cout << i << ",";
	if (!t_vec.empty()) cout << "\b";
	cout << "]}" << endl;
}

void ex3_16() {
	vector<int> v1;         // size:0,  no values.
	vector<int> v2(10);     // size:10, value:0
	vector<int> v3(10, 42); // size:10, value:42
	vector<int> v4{ 10 };     // size:1,  value:10
	vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
	vector<string> v6{ 10 };  // size:10, value:""
	vector<string> v7{ 10, "hi" };  // size:10, value:"hi"
	ex3_16_print(v1, "v1");
	ex3_16_print(v2, "v2");
	ex3_16_print(v3, "v3");
	ex3_16_print(v4, "v4");
	ex3_16_print(v5, "v5");
	ex3_16_print(v6, "v6");
	ex3_16_print(v7, "v7");
}

/// Read a sequence of words from cin and store the values a vector.
/// After you've read all the words, process the vector and change each word to
/// uppercase.
/// Print the transformed elements, eight words to a line.
void ex3_17() {
	string sval;
	vector<string> svec;
	while (cin >> sval) {
		for (auto &c : sval)
			c = toupper(c);
		svec.push_back(sval);
	}
	for (decltype(svec.size()) i = 0; i < svec.size(); ++i) {
		if (i != 0 && i % 8 == 0)
			cout << endl;
		cout << svec[i] << ' ';
	}
}

/// List three ways to define a vector and give it ten elements,
/// each with the value 42.
/// Indicate whether there is a preferred way to do so and why.
void ex3_19() {
	vector<int> vec1(10, 42);//better
	vector<int> vec2 = vec1;
	vector<int> vec3(vec1);
	vector<int> vec4{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	vector<int> vec5 = { 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	vector<int> vec6;
	for (int i = 0; i < 10; ++i)
		vec6.push_back(42);

}
// Read a set of integers into a vector.Print the sum of each pair  of  adjacent  elements.
//Change  your  program  so  that  it  prints  the  sum  of the first and last elements, 
//followed by the sum of the second and second - to - last, and so on.
void ex3_20_1() {
	int i;
	vector<int> ivec;
	while (cin >> i) {
		ivec.push_back(i);
		cout << i << ' ';
	}
	for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; ++i)
		cout << ivec[i] + ivec[i + 1] << ' ';
	cout << endl;
}

void ex3_20_2() {
	int i;
	vector<int> ivec;
	while (cin >> i) {
		ivec.push_back(i);
		cout << i << ' ';
	}
	for (decltype(ivec.size()) i = 0, j = ivec.size() - 1; 
		i <= j; ++i, --j)
		cout << ivec[i] + ivec[j] << ' ';
	cout << endl;
}

template<class type>
void ex3_21_print(const vector<type> &t_vec, const string &name) {
	cout << "{ \" " << name << "\":{\"size\":\"" << t_vec.size() << "\",\"value\":[";
	for (auto i = t_vec.cbegin(); i != t_vec.cend(); ++i) cout << *i << ",";
	if (!t_vec.empty()) cout << "\b";
	cout << "]}" << endl;
}

//Redo the first exercise from ¡ì 3.3.3 (p. 105) using iterators.
void ex3_21() {
	vector<int> v1;         // size:0,  no values.
	vector<int> v2(10);     // size:10, value:0
	vector<int> v3(10, 42); // size:10, value:42
	vector<int> v4{ 10 };     // size:1,  value:10
	vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
	vector<string> v6{ 10 };  // size:10, value:""
	vector<string> v7{ 10, "hi" };  // size:10, value:"hi"
	ex3_21_print(v1, "v1");
	ex3_21_print(v2, "v2");
	ex3_21_print(v3, "v3");
	ex3_21_print(v4, "v4");
	ex3_21_print(v5, "v5");
	ex3_21_print(v6, "v6");
	ex3_21_print(v7, "v7");
}

void ex3_22() {
	vector<string> svec;
	string sval;
	while (cin >> sval)
		svec.push_back(sval);
	for (auto iter = svec.begin(); iter != svec.end(); ++iter) {
		for (auto &c : *iter)
			c = toupper(c);
		cout << *iter << ' ';
	}
	cout << endl;
}

/// Write a program to create a vector with ten int elements.
/// Using an iterator, assign each element a value that is twice its current
/// value.
void ex3_23() {
	vector<int> ivec(10, 2);
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
		*iter *= 2;
		cout << *iter << ' ';
	}
	cout << endl;
		
}

// Redo the last exercise from ¡ì3.3.3 using iterators.
void ex3_24_1() {
	vector<int> ivec;
	for (int i; cin >> i;) {
		ivec.push_back(i);
		cout << i << ' ';
	}
	for (auto iter = ivec.cbegin(); iter != ivec.cend() - 1; ++iter)
		cout << *iter + *(iter + 1) << ' ';
	cout << endl;
}

void ex3_24_2() {
	vector<int> ivec;
	for (int i; cin >> i;) {
		ivec.push_back(i);
		cout << i << ' ';
	}
	for (auto it1 = ivec.cbegin(), it2 = ivec.cend() - 1; 
		it1 <= it2; ++it1, --it2)
		cout << *it1 + *it2<< ' ';
	cout << endl;
}

//  Rewrite  the  grade  clustering  program  from  ¡ì3.3.3 
//using iterators instead of subscripts.
void ex3_25() {
	vector<unsigned> scores(11, 0);
	unsigned grade;
	for (auto it = scores.begin(); cin >> grade;) {
		if (grade < 101)
			++*(it + grade / 10);
		else
			cout << "input error.";
	}
	for (const auto &s : scores)
		cout << s << ' ';
	cout << endl;
}

//define  an  array  of  ten ints.Give  each
//element the same value as its position in the array.
void ex3_31() {
	int a[10];
	for (int i = 0; i < 10; ++i)
		a[i] = i;
	for (const auto i : a)
		cout << i << ' ';
	cout << endl;
}

//  Copy  the  array  you  defined  in  the  previous  exercise  into
//another array.Rewrite your program to use vectors.
void ex3_32_1() {
	int a1[10];
	int a2[10];
	for (size_t i = 0; i < 10; ++i)
		a1[i] = i;
	for (size_t i = 0; i < 10; ++i)
		a2[i] = a1[i];
	for (const auto i : a2)
		cout << i << ' ';
	cout << endl;
}

void ex3_32_2() {
	vector<int> ivec(10);
	vector<int> ivec2;
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		*it = it - ivec.begin();
	ivec2 = ivec;
	for (const auto i : ivec2)
		cout << i << ' ';
	cout << endl;
}

// Using  pointers,  write  a  program  to  set  the  elements  in  an
//array to zero.
void ex3_35() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto a_begin = begin(a); a_begin != end(a); ++a_begin)
		*a_begin = 0;
	for (const auto &i : a)
		cout << i << ' ';
	cout << endl;
}

// Write a program to compare two arrays for equality. 
//Write a similar program to compare two vectors.
template<class type>
bool ex3_36_1_compare(type *pb1, type *pe1, type *pb2, type *pe2) {
	if ((pe1 - pb1) != (pe2 - pb2))
		return false;
	else {
		for (; pb1 != pe1 && pb2 != pe2; ++pb1, ++pb2) {
			if (*pb1 != *pb2)
				return false;
		}
		return true;
	}
}
void ex3_36_1() {
	/*int arr1[3] = { 0, 1, 2 };
	int arr2[3] = { 0, 1, 2 };*/
	char arr1[] = "hello ";
	char arr2[] = "hello ";
	if (ex3_36_1_compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
		cout << " equal " << endl;
	else
		cout << " not equal " << endl;
}

void ex3_36_2() {
	vector<int> vec1 = { 0, 1, 2 };
	vector<int> vec2 = { 0, 1, 2 };

	if (vec1 == vec2)
		cout << "The two vectors are equal." << endl;
	else
		cout << "The two vectors are not equal." << endl;
}

//  Write  a  program  to  compare  two  strings.Now  write  a
//program to compare the values of two C - style character strings.
void ex3_39_1() {
	string str1, str2;
	cin >> str1 >> str2;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	if (str1 == str2)
		cout << "two strings are equal." << endl;
	else if (str1 < str2)
		cout << "str1 is smaller than str2." << endl;
	else
		cout << "str2 is greater than str2." << endl;
}

void ex3_39_2() {
	char a[] = "hello";
	char b[] = "see you";
	cout << "str1: " << a << endl;
	cout << "str2: " << b << endl;
	if (strcmp(a, b) == 0)
		cout << "two strings are equal." << endl;
	else if (strcmp(a, b) < 0)
		cout << "str1 is smaller than str2." << endl;
	else
		cout << "str1 is greater than str2." << endl;

}

//  Write  a  program  to  initialize  a vector from  an  array  of ints.
void ex3_41() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> ivec(begin(a), end(a));
	for (const auto &i : ivec)
		cout << i << ' ';
	cout << endl;
}

//Write a program to copy a vector of ints into an array of ints.
void ex3_42() {
	vector<int> ivec(10, 1);
	int *a = new int[ivec.size()];
	for (auto i = 0; i < ivec.size(); ++i) {
		a[i] = ivec[i];
		cout << a[i] << ' ';
	}
	cout << endl;
	delete[] a; 
}

//  Write  three  different  versions  of  a  program  to  print  the elements  of ia.
//One  version  should  use  a  range for to  manage  the iteration, 
//the  other  two  should  use  an  ordinary for loop  in  one  case  using
//subscripts and in the other using pointers.
//do  not  use  a  type  alias,  auto, or decltype to simplify the code.

void ex3_43_1() {
	int a[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11},
	};
	//essencial, int (*line)[4]  is not allowed.
	//the type of i is int *; the inner for loop is illegal. 
	for (int (&line)[4] : a) {
		for (int i : line) {
			cout << i << ' ';
		}
		cout << endl;
	}
		
}

void ex3_43_2() {
	int a[3][4] = {
		{ 0,1,2,3 },
		{ 4,5,6,7 },
		{ 8,9,10,11 },
	};
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

void ex3_43_3() {
	int a[3][4] = {
		{ 0,1,2,3 },
		{ 4,5,6,7 },
		{ 8,9,10,11 },
	};
	for (int (*pa)[4] = begin(a); pa != end(a); ++pa) {
		for (int *pb = begin(*pa); pb != end(*pa); ++pb)
			cout << *pb << ' ';
		cout << endl;
	}
}

//Rewrite  the  programs  from  the  previous  exercises  using  a
//type alias for the type of the loop control variables.
using int_array = int[4];
//typedef int int_array[4];
void ex3_44() {
	int a[3][4] = {
		{ 0,1,2,3 },
	{ 4,5,6,7 },
	{ 8,9,10,11 },
	};
	for (int_array *pa = begin(a); pa != end(a); ++pa) {
		for (int *pb = begin(*pa); pb != end(*pa); ++pb)
			cout << *pb << ' ';
		cout << endl;
	}
}

//Rewrite the programs again, this time using
void ex3_45() {
	int a[3][4] = {
		{ 0,1,2,3 },
		{ 4,5,6,7 },
		{ 8,9,10,11 },
	};
	for (auto &line : a) {//reference is necessary.
		for (int i : line) {
			cout << i << ' ';
		}
		cout << endl;
	}
	for (auto pa = begin(a); pa != end(a); ++pa) {
		for (auto pb = begin(*pa); pb != end(*pa); ++pb)
			cout << *pb << ' ';
		cout << endl;
	}
}

int main(){
	//ex3_2_1();
	//ex3_2_2();
	//ex3_4_1();
	//ex3_4_2();
	//ex3_5_1();
	//ex3_5_2();
	//ex3_6();
	//ex3_8_1();
	//ex3_8_2();
	//ex3_10();
	//ex3_14();
	//ex3_15();
	//ex3_16();
	//ex3_17();
	//ex3_20_1();
	//ex3_20_2();
	//ex3_21();
	//ex3_22();
	//ex3_23();
	//ex3_24_1();
	//ex3_24_2();
	//ex3_25();
	//ex3_31();
	//ex3_32_1();
	//ex3_32_2();
	//ex3_35();
	//ex3_36_1();
	//ex3_36_2();
	//ex3_39_1();
	//ex3_39_2();
	//ex3_41();
	//ex3_42();
	//ex3_43_1();
	//ex3_43_2();
	//ex3_43_3();
	//ex3_44();
	ex3_45();
	return 0;
}