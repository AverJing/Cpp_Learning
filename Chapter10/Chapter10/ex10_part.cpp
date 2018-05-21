/*
*
*@author：Aver Jing
*@description： a part of exercise in CH10
*@date：May 16, 2018
*
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <list>

#include "Sales_data.h"
#include "Sales_item.h"

using namespace std;

template<class T>
void Print(T &t) {
	for (auto &x : t)
		cout << x << ' ';
	cout << endl;
}

//use count function(in algorithm header) to print the count of 
//how many elements have a given value in vector<int>
void ex10_1() {
	vector<int> ivec{ 1,1,1,1,1,1,5,5,5,7,7,7,7,8 };

	cout << "The number of 1 in ivec is " << count(ivec.cbegin(), ivec.cend(), 1) << endl;;
}

//Repeat the previous program, but read values into a list of strings.
void ex10_2() {
	list<string> slst{"Aver", "Jing", "Jing", "Jing"};

	cout << "The number of Jing in slst is " << count(slst.cbegin(), slst.cend(), "Jing") << endl;;
}

//Use accumulate function to sum these emelents in a vector<int>. 
void ex10_3() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };

	int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);

	cout << "The sum of elements in vector<int> is " << sum << endl;
}

void ex10_4() {
	vector<double> ivec{ 1.1,2.2,3.3};

	double sum = accumulate(ivec.cbegin(), ivec.cend(), 0);

	cout << "The sum of elements in vector<double> is " << sum << endl;

	//The output is 6 rather than 6.6 as expected
	//The reason is std::accumulate is a template function. The third
	//parameter is _Ty
	//When "0", an integer, had ben specified here, the compiler deduced _Ty as integer
}

//-----------------------
//In the call to equal on rosters, what would happen if both rosters held C-style strings,
//rather than library strings?
void  ex10_5() {
	/*vector<const char *> roster1{ "hello\0" };
	list<const char *> roster2{ "hello\0" };

	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;*/
	//The output is 1.

	char c1[10] = "hello";
	char c2[10] = "hello";
	vector<char *> roster1{ c1 };
	list<char *> roster2{ c2 };

	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;
	//The output is 0.
	//We need to keep in mind that when it comes to comparison of C-style strings, we need
	//to use 'strcmp' but not simply relational operators, for using relational operators is
	//just comparison between the address of two C-style strings but not their values.
}

//Using fill_n, write a program to set a sequence of int to 0.
void ex10_6() {
	//back_inserter question
	/*vector<int> vec;
	auto it = back_inserter(vec);
	*it = 42; //assigning through is adds elements to vec
	cout << vec.size() << endl;*/

	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	for (auto &i : ivec)
		cout << i << ' ';
	cout << endl;

	fill_n(ivec.begin(), ivec.size(), 0);

	for (auto &i : ivec)
		cout << i << ' ';
	cout << endl;
}

//Correct errors in following programs
void ex10_7() {
	//First
	vector<int> vec;
	list<int> lst;
	int i;
	while (cin >> i)
		lst.push_back(i);
	vec.resize(lst.size());//Fixed: add this statement
	//Cause Algorithms that write to a destination iterator assume the destination is large
	//enough to hold the number of elements being written.
	copy(lst.cbegin(), lst.cend(), vec.begin());
	Print<vector<int>>(vec);

	//Second
	vector<int> v;
	//v.reserve(10);
	//1:
	/*v.resize(10);
	fill_n(v.begin(), 10, 0);*/
	//2:
	fill_n(back_inserter(v), 10, 0);
	//No error, but not any sense. v.size() still equal zero.
	Print(v);
}

void elimDups(vector<string> &svec) {
	sort(svec.begin(), svec.end());
	auto end_unique = unique(svec.begin(), svec.end());
	svec.erase(end_unique, svec.end());
}
//Implement your own version of elimDups.Test your program by printing the vector after 
//you read the input, after the call to unique, and after the call to erase.
void ex10_9() {
	vector<string> svec{ "a", "c", "b", "a", "c" };
	elimDups(svec);
	Print(svec);
}

//Write a program that uses stable_sort and isShorter to sort a vector passed to your version
//of elimDups. Print the vector to verify that your program is correct.
bool isShoter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}
void ex10_11() {
	vector<string> svec{ "111", "111" , "111" , "a", "b", "a", "b" };
	elimDups(svec);
	stable_sort(svec.begin(), svec.end(), isShoter);
	Print(svec);
}

//Write a function named compareIsbn that compares the isbn() members of two Sales_data objects.
//Use the function to sort a vector that holds Sales_data objects.
bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2) {
	return sd1.ISBN() < sd2.ISBN();
}
void ex10_12() {
	Sales_data d1("CppPrimer"), d2("EssentialCpp"), d3("Cpp"), d4("GameEngine");
	vector<Sales_data> sdvec{ d1, d2, d3, d4 };

	//error:“void std::sort(const _RanIt, const _RanIt, _Pr)”: 未能为“_Pr”推导 模板 参数	Chapter10

	//sort(sdvec.begin(), sdvec.end(), compareIsbn);

	Print(sdvec);
}

bool split(const string& s) {
	return s.size() >= 5;
}
//Print the elements that have five or more characters.
void ex10_13() {
	vector<string> svec{ "hello", "if", "you", "find", "me", "I", "will", "follow" };

	auto pivot = partition(svec.begin(), svec.end(), split);

	for (auto it = svec.begin(); it != pivot; ++it)
		cout << *it << ' ';
	cout << endl;
}

//Write a lambda that takes two ints and returns their sum
void ex10_14() {
	auto add = [](int lhs, int rhs) {return lhs + rhs; };
	cout << add(10, 5) << endl;
}

//Write a lambda that captures an int from its enclosing function and take an int parameter
//The lambda should return the sum of the captured int and the int parameter.
void ex10_15(int i) {
	auto add = [i](int v) {return i + v; };
	cout << add(10) << endl;
}

//Write your own version of the beggies function using lambdas.
void biggies(vector<string> &vs, size_t sz) {
	elimDups(vs);
	//sort by size, but maintain alphabetical order for same size
	stable_sort(vs.begin(), vs.end(), [](string const& a, string const& b) {return a.size() < b.size(); });
	//get an iterator to the first one whose size() is >= a
	auto pivot = find_if(vs.begin(), vs.end(), [sz](string& a) {return a.size() >= sz; });
	//print the result
	for_each(pivot, vs.end(), [](string& a) {cout << a << ' '; });
}

//Rewrite excercise 10.12 to use lambda in the call to sort instead of the compareIsbn function.
void ex10_17() {
	Sales_data d1("CppPrimer"), d2("EssentialCpp"), d3("Cpp"), d4("GameEngine");
	vector<Sales_data> sdvec{ d1, d2, d3, d4 };

	sort(sdvec.begin(), sdvec.end(), [](Sales_data const& lhs, Sales_data const& rhs) {return lhs.ISBN() < rhs.ISBN(); });

	Print(sdvec);
}

//Rewrite beggies to use partition instead of find_if.
void ex10_18(vector<string> &vs, size_t sz) {
	elimDups(vs);
	//sort by size, but maintain alphabetical order for same size
	//stable_sort(vs.begin(), vs.end(), [](string const& a, string const& b) {return a.size() < b.size(); });
	//get an iterator to the first one whose size() is >= a
	auto pivot = partition(vs.begin(), vs.end(), [sz](string& a) {return a.size() >= sz; });
	//print the result
	for_each(vs.begin(), pivot, [](string& a) {cout << a << ' '; });
}

//Use stable_partition to rewrite the previous program.
void ex10_19(vector<string> &vs, size_t sz) {
	elimDups(vs);
	//sort by size, but maintain alphabetical order for same size
	//stable_sort(vs.begin(), vs.end(), [](string const& a, string const& b) {return a.size() < b.size(); });
	//get an iterator to the first one whose size() is >= a
	auto pivot = stable_partition(vs.begin(), vs.end(), [sz](string& a) {return a.size() >= sz; });
	//print the result
	for_each(vs.begin(), pivot, [](string& a) {cout << a << ' '; });
}

//Use count_if to rewrite the portion of our program that counted how many words are greater
//than length 6.
void ex10_20() {
	vector<string> v{ "Never", "let", "your", "fear","decide", "your", "fate", "AverJing" };
	cout << count_if(v.begin(), v.end(), [](string const& s) {return s.size() >= 6; })
		 << endl;
}

//Write a lambda that captures a local int variable and decrements that variable until it
//reaches 0.Once the variable is 0 additional calls should no longer decrement the variable.
//The lambda should return a bool that indicates whther the captured variable is 0.
void ex10_21(int i) {
	auto flag = [&i]()-> bool {
	if (i > 0) 
		{ --i; return false; } 
	else if (i < 0) i = -i; 
	else return true; };

	while (!flag()) cout << i << ' ' << endl;
}

//Rewrite the program to count words of size 6 or less using functions in place of the lambdas.
bool splitBysz(const string& s, string::size_type sz) {
	return s.size() < sz;
}
void ex10_22() {
	vector<string> v{ "Never", "let", "your", "fear","decide", "your", "fate", "AverJing" };
	cout << count_if(v.begin(), v.end(), bind(splitBysz, placeholders::_1, 6))
		<< endl;
}

//Use bind and check_size to find the first element in a vector of ints that has a value greater
//than the length of a specified string value.
void ex10_24() {
	vector<int> v{ 1,2,3,4,5 };
	string s = "test";
	cout << *find_if(v.cbegin(), v.cend(), bind(splitBysz, s, placeholders::_1));
}

//Rewrite that function to use check_size and bind.
void ex10_25(vector<string> &words, size_t sz) {
	elimDups(words);
	auto iter = std::stable_partition(words.begin(), words.end(),
		bind(splitBysz, placeholders::_1, sz));
	for_each(words.begin(), iter,
		[](const string& s) { std::cout << s << " "; });
}

//Use unique_copy to copy these unique elemtns from vector<int> 
//into an initially empty list<int>.
void ex10_27() {
	vector<int> ivec{ 1,1,5,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9 };
	list<int> ilst;
	//ilst.resize(ivec.size());

	sort(ivec.begin(), ivec.end());
	//unique_copy(ivec.cbegin(), ivec.cend(), ilst.begin());
	unique_copy(ivec.cbegin(), ivec.cend(), inserter(ilst,ilst.begin()));
	Print(ilst);
}

//Copy a vector that holds the values from 1 to 9 inclusive,
//into three other containers.Use an inserter, a back_inserter, and a front_inserter, 
//respectively to add elements to these containers.
void ex10_28() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	list<int> ilst1;
	list<int> ilst3;
	list<int> ilst2;

	copy(ivec.cbegin(), ivec.cend(), inserter(ilst1, ilst1.begin()));
	Print(ilst1);
	copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst2));
	Print(ilst2);
	copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst3));
	Print(ilst3);
}

//Write a program using stream iterators to read a text file into a vector of strings.
void ex10_29() {
	vector<string> svec;
	ifstream in("test.txt");
	istream_iterator<string> str_it(in), eof;
	copy(str_it, eof, back_inserter(svec));

	copy(svec.cbegin(), svec.cend(), ostream_iterator<string>(cout, " "));
}

//Use stream iterators, sort, and copy to read a sequence of integers from the
//standard input, sort them, and then write them back to the standard output.
void ex10_30() {
	istream_iterator<int> int_it(cin), eof;
	vector<int> ivec;
	//copy(int_it, eof, back_inserter(ivec));
	while (int_it != eof) ivec.push_back(*int_it++);
	sort(ivec.begin(), ivec.end());
	copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
}

//Update the program from the previous excercise so that it prints only the unique elements.
void ex10_31() {
	istream_iterator<int> int_it(cin), eof;
	vector<int> ivec;
	//copy(int_it, eof, back_inserter(ivec));
	while (int_it != eof) ivec.push_back(*int_it++);
	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
}

//Rewrite the bookstore program from P21(Chinese version), using a vector to hold the
//transactions and various algorithms to do the processing.
//Use sort with your compareIsbn function from P345 to arrange the transactions in order,
// then use find and accumulate to do the sum.
void ex10_32() {
	istream_iterator<Sales_item> in_iter(cin), in_eof;
	vector<Sales_item> vec;

	while (in_iter != in_eof) vec.push_back(*in_iter++);
	sort(vec.begin(), vec.end(),
		[](Sales_item const& lhs, Sales_item const& rhs) {
		return lhs.isbn() < rhs.isbn();
	});
	for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
		end = find_if(beg, vec.cend(), [beg](const Sales_item& item) {
			return item.isbn() != beg->isbn();
		});
		cout << accumulate(beg, end, Sales_item(beg->isbn()))
			<< endl;
	}
}

//Write a program that takes the names of an input file and two output files.
//The input file should hold integers.Using an istream_iterator read the input file.
//Using ostream_iterators, write the odd numbers into the first output file.
//Each value should be followed by a space. Write the even numbers into the second file.
//Each of these values should be placed on a separate line.
void ex10_33() {
	ifstream in("number.txt");
	istream_iterator<int> in_it(in), eof;

	ofstream odd_out("odd.txt");
	ofstream even_out("even.txt");
	ostream_iterator<int> odd(odd_out, " "), even(even_out, "\n");

	for_each(in_it, eof, [&odd, &even](const int i) { *(i & 0x1 ? odd : even)++ = i; });

}

//Use reverse_iterator to print a vector
void ex10_34() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	for (auto r_iter = ivec.crbegin(); r_iter != ivec.crend(); ++r_iter)
		cout << *r_iter << ' ';
	cout << endl;
}

//Now print the elements in reverse order using ordinary iterators.
void ex10_35() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	for (auto it = ivec.end(); it != ivec.begin();) {
		cout << *--it << ' ';
	}
	cout << endl;
}

//Use find to find the last element in a list of ints with value 0.
void ex10_36() {
	list<int> ilst{ 0,1,20,3,4,0,5,6,7,0,2,3,4 };
	auto found = find(ilst.rbegin(), ilst.rend(), 0);
	cout << *found << "position is " << *found.base();
}

//Given a vector that has ten elements, copy the elements from position 3 through 7
//in reverse order to a list.
void ex10_37() {
	vector<int> ilst{ 1,2,3,4,5,6,7,8,9,10 };
	list<int> dest;
	//reverse_copy(ilst.begin() + 3, ilst.begin() + 8, back_inserter(dest));
	copy(ilst.rbegin() + 2, ilst.rbegin() + 7, back_inserter(dest));
	Print(dest);
}

//Waiting for update.
void ex10_38() {

}

int main() {
	//ex10_1();
	//ex10_2();
	//ex10_3();
	//ex10_4();
	//ex10_5();
	//ex10_6();
	//ex10_7();
	//ex10_9();
	//ex10_11();
	//ex10_12();
	//ex10_13();
	//ex10_14();
	//ex10_15(10);

	//ex10.16
	vector<string> v{ "1234", "1234", "1234", "hi~","alan", "alan", "cp" };
	//biggies(v, 3);

	//ex10_17();
	//ex10_18(v, 3);
	//ex10_19(v, 3);
	//ex10_20();
	//ex10_21(10);
	//ex10_22();
	//ex10_24();
	//ex10_25(v, 3);

	//ex10_27();
	//ex10_28();
	//ex10_29();
	//ex10_30();
	//ex10_31();
	//ex10_32();
	//ex10_33();
	//ex10_34();
	//ex10_35();
	//ex10_36();
	ex10_37();

	return 0;
}