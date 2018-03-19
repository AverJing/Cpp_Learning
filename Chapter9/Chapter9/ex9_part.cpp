/*
*
*@author: AverJing
*@description: a part of exercise in CH9
*@date:Tuesday, February 27, 2018
*
*/
#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <vector>
#include <forward_list>
#include <fstream>

using namespace std;

template<class a>
void Print(const a &v) {
	for (auto &i : v)
		cout << i << ' ';
	cout << endl;
}

//Define a list that holds elements that are deques that hold ints.
void ex9_2() {
	list<deque<int>> ldi;
}

//Write a function that takes a pair of iterators to vector<int> and an int value.
//Look for the value int the range and return a bool indicating whether it was found.
bool ex9_3(vector<int>::const_iterator begin, vector<int>::const_iterator end, int temp) {
	for (auto iter = begin; iter != end; ++iter) {
		if (*iter == temp)
			return true;
	}
	return false;
}

//Rewrite the previous program to return an iterator to the requested element.
vector<int>::const_iterator ex9_4(vector<int>::const_iterator begin, vector<int>::const_iterator end, int temp) {
	for (auto iter = begin; iter != end; ++iter) {
		if (*iter == temp)
			return iter;
	}
	return end;
}

//Show an example of each of the six ways to create and initialize a vector.
//Explain what values each vector contains.
void ex9_11() {
	vector<int> v1;//null
	vector<int> v2 = { 1,2,3 };//1 2 3
	vector<int> v3(2);//0 0 
	vector<int> v4(4, 5);//5 5 5 5 5  
	vector<int> v5(v2);//same as vec2
	vector<int> v6(v2.cbegin(), v2.cend()); //same as vec2
}

//How would you initialize a vector<double> to a list<int>?
//From a vector<int> ?
void ex9_12() {
	vector<int> ivec(4, 5);
	list<int> ilist(4, 5);

	vector<double> dvec1(ilist.cbegin(), ilist.cend());
	for (auto &d : dvec1)
		cout << d << ' ';
	cout << endl;

	vector<int> dvec2(ivec.cbegin(), ivec.cend());
	for (auto &d : dvec2)
		cout << d << ' ';
	cout << endl;
}

//Write a program to assign the elements from a list<char *> pointers to a vector<string>
void ex9_14() {
	list<const char *> clist = { "hello", "hi" };//should be const 
	vector<string> svec(clist.cbegin(), clist.cend()); //ok
	for (auto &s : svec)
		cout << s << ' ';
	cout << endl;
	clist.push_back("Bye");

	svec.assign(clist.cbegin(), clist.cend());
	for (auto &s : svec)
		cout << s << ' ';
	cout << endl;
}

//Write a program to determine whether two vector<int>s are equal.
void ex9_15() {
	vector<int> v1;
	vector<int> v2;
	if (v1 == v2)
		cout << "Equal" << endl;
	else
		cout << "Unequal." << endl;
}

//Repeat the previous program, but compare elements in list<int>
void ex9_16() {
	list<int> ilist{ 1,2,3,4,5 };
	vector<int> v1{ 1,2,3,4 };
	vector<int> v2{ 1,2,3,4,5 };
	if (vector<int>(ilist.cbegin(),ilist.cend()) == v1)//essence
		cout << "Equal" << endl;
	else
		cout << "Unequal." << endl;
	if (vector<int>(ilist.cbegin(), ilist.cend()) == v2)//essence
		cout << "Equal" << endl;
	else
		cout << "Unequal." << endl;
}

//Write a program to read a sequence of string from standard input into a deque.
//Use iterators to write a loop to print the elements in the deque.
void ex9_18() {
	deque<string> dstr;
	string word;
	while (cin >> word)
		dstr.push_back(word);
	for (auto begin = dstr.cbegin(), end = dstr.cend(); begin != end; ++begin)
		cout << *begin << ' ';
	cout << endl;
}

//Rewrite the previous program to use a list instead of deque.
void ex9_19() {
	list<string> dstr;
	string word;
	while (cin >> word)
		dstr.push_back(word);
	for (auto begin = dstr.cbegin(), end = dstr.cend(); begin != end; ++begin)
		cout << *begin << ' ';
	cout << endl;
}

//Write a program to copy elements from a list into two deques.
//The even-elements should go into one deque and the odd ones into the other.
void ex9_20() {
	deque<int> di1;
	deque<int> di2;

	list<int> lit{ 1,2,3,4,5,6,7,8,9 };
	for (auto &i : lit) {
		if (i % 2 == 0)
			di1.push_back(i);
		else
			di2.push_back(i);
	}

	cout << "Even-elements are ";
	Print<deque<int>>(di1);

	cout << "Odd-elements are ";
	Print<deque<int>>(di2);
}

//Explain how the loop would work in this program.
void ex9_21() {
	vector<string> svec;
	string word;
	auto iter = svec.begin();
	while (cin >> word) {
		iter = svec.insert(iter, word);
	}
	Print<vector<string>>(svec);
}

//fix eg:9.22
void ex9_22(vector<int>& iv, int some_val) { 
	auto cursor = iv.size() / 2;
	auto iter = iv.begin(), mid = iv.begin() + cursor;
	while (iter != mid) {
		if (*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
			++iter;
			++cursor;
			mid = iv.begin() + cursor;
		}
		++iter;
	}
	Print(iv);
}

//Write a program that fetches the first element in a vector using at, the subscript operation,
//front and begin. Test yout program on an empty vector.
void ex9_24() {
	//vector<int> ivec;
	vector<int> ivec{ 1 };
	auto begin = ivec.begin();
	cout << ivec.at(0)
		<<  ivec[0]
		<< *begin
		<< ivec.front();
}

//Using the following definition of ia, copy ia into a vector and into a list.
//Using the single-iterator form of earase to remove the odd elements from your list and the even elements
//from your vector.
void ex9_26() {
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> ivec(ia, end(ia));
	list<int> ilist(ia, end(ia));
	auto begin_vec = ivec.begin();
	auto begin_list = ilist.begin();
	//essence
	//take some time to think it seriously
	while (begin_list != ilist.end()) {
		if (*begin_list % 2) {
			begin_list = ilist.erase(begin_list);
		}
		else
			++begin_list;
	}
	while (begin_vec != ivec.end()) {
		if (*begin_vec % 2 == 0)
			begin_vec = ivec.erase(begin_vec);
		else
			++begin_vec;
	}
	cout << "The elements of list are :";
	Print(ilist);
	cout << "The elements of vector are :";
	Print(ivec);
}

//Write a program to find and remove the odd-valued elements in a forward_list<int>.
void ex9_27() {
	forward_list<int> ifwl{ 1,2,3,4,5,6,7,8,9 };

	for (auto begin = ifwl.begin(), end = ifwl.end(); begin != end; ++begin) {
		if (*begin % 2)
			cout << *begin << ' ';
	}
	cout << endl;
	//essence
	//take some time to think it seriously
	auto prev = ifwl.before_begin();
	auto begin = ifwl.begin();
	while (begin != ifwl.end()) {
		if (*begin % 2) {
			begin = ifwl.erase_after(prev);
		}
		else {
			prev = begin;
			++begin;
		}
	}
	cout << "The elements of forward_list are :";
	Print(ifwl);
}

//Write a function that takes a forward_lsit<string> and two additional string arguments.
//The function should find the first string and insert the second immediately following
//the first. If the first string is not found, then insert the second string at the end of the list.
void ex9_28(forward_list<string> &sflt, const string &str1, const string &str2) {
	bool temp = false;
	auto end_pre = sflt.begin();
	for (auto begin = sflt.begin(); begin != sflt.end(); ++begin) {
		if (*begin == str1) {
			sflt.insert_after(begin, str2);
			temp = true;
		}
		end_pre = begin;
	}
	if(!temp)
		sflt.insert_after(end_pre, str2);

	//another method
	//auto prev = list.before_begin();
	//auto size = std::distance(list.begin(), list.end());
	//for (auto curr = list.begin(); curr != list.end(); prev = curr++)
	//	if (*curr == to_find) list.insert_after(curr, to_add);
	//if (size == std::distance(list.begin(), list.end())) list.insert_after(prev, to_add);
}

//remove even-valued elements and duplicate odd ones
void ex9_31() {
	list<int> ilst{ 1,2,3,4,5,6,7,8,9 };
	forward_list<int> fwd_lst{ 1,2,3,4,5,6,7,8,9 };

	auto iter = ilst.begin();
	while (iter != ilst.end()) {
		if (*iter % 2) {
			iter = ilst.insert(iter, *iter);
			/*++iter;
			++iter;*/
			advance(iter, 2);
		}
		else
			iter = ilst.erase(iter);
	}
	Print(ilst);

	auto iter2 = fwd_lst.begin();
	auto iter2_pre = fwd_lst.before_begin();
	while (iter2 != fwd_lst.end()) {
		if (*iter2 % 2) {
			iter2 = fwd_lst.insert_after(iter2, *iter2);
			iter2_pre = iter2;
			++iter2;
		}
		else
			iter2 = fwd_lst.erase_after(iter2_pre);
	}
	Print(fwd_lst);
}

//Infinite loop. Fixed.
void ex9_34() {
	vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = vi.begin();

	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
		}
		++iter;
	}
	Print(vi);
}

//Write a program to explore how vectors grow in the library you use. 
void ex9_38() {
	vector<int> vi;
	int i;
	while (cin >> i) {
		vi.push_back(i);
		cout << vi.capacity() << endl;
	}
		
}

//Write a program that initializes a string from a vector<char>
void ex9_41() {
	vector<char> vc{ 'h','e','l','l','o',' ', 'w', 'o', 'r', 'l', 'd' };
	string str(vc.cbegin(), vc.cend());
	cout << str << endl;
}

//Write a program that takes three strings, s, oldVal, and newVal.
//Using iterators, and the insert and erase functions replace all instances of oldVals
//that appears in s by newVal.
//essence
//essence
//difficulty
void ex9_43(string &s, const string &oldVal, const string &newVal) {
	for (auto begin = s.begin(); distance(begin, s.end()) >= distance(oldVal.cbegin(), oldVal.cend());) {
		if (string{ begin, begin + oldVal.size() } == oldVal) {
			begin = s.erase(begin, begin + oldVal.size());
			begin = s.insert(begin, newVal.cbegin(), newVal.cend());
			advance(begin, newVal.size());
		}else
			++begin;
	}

	/*string::size_type pos = s.find(oldVal);
	while (pos != string::npos) {
		s.erase(pos, oldVal.size());
		s.insert(pos, newVal);
		pos = s.find(oldVal, ++pos);
	}*/
}

//Rewrite the previous function using an index and replace.
void ex9_44(string &s, const string &oldVal, const string &newVal) {
	for (string::size_type i = 0; i != s.size(); ++i)
		if (s.substr(i, oldVal.size()) == oldVal) {
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size() - 1;
		}
}

void ex9_45(string &name, const string &prefix, const string &suffix) {
	name.insert(name.cbegin(), prefix.cbegin(), prefix.cend());
	name.append(suffix.cbegin(), suffix.cend());
}

void ex9_46(string &name, const string &prefix, const string &suffix) {
	name.insert(0, prefix);
	name.insert(name.size(),suffix);
}

//use find_first_of
void ex9_47_1() {
	string numbers{ "0123456789" };
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string str{ "ab2c3d7R4E6" };

	cout << "numeric characters: ";
	for (string::size_type pos = 0;
		(pos = str.find_first_of(numbers, pos)) != string::npos; ++pos)
		cout << str[pos] << " ";
	cout << "\nalphabetic characters: ";
	for (string::size_type pos = 0;
		(pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos)
		cout << str[pos] << " ";
	cout << endl;
}

//use find_first_not_of
void ex9_47_2() {
	string numbers{ "0123456789" };
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string str{ "ab2c3d7R4E6" };

	cout << "numeric characters: ";
	for (string::size_type pos = 0;
		(pos = str.find_first_not_of(numbers, pos)) != string::npos; ++pos)
		cout << str[pos] << " ";
	cout << "\nalphabetic characters: ";
	for (string::size_type pos = 0;
		(pos = str.find_first_not_of(alphabet, pos)) != string::npos; ++pos)
		cout << str[pos] << " ";
	cout << endl;
}

//Write a program that reads a file containing words and reports the longest word 
//that contains neither ascenders and descenders.
void ex9_49() {
	ifstream ifile{ "letter.txt" };
	string result;

	for (string word; ifile >> word;) {
		if ((word.find_first_not_of("aceimnorsuvwxz") == string::npos) && word.size() > result.size())
			result = word;
	}
	cout << result << endl;
	ifile.close();
}

//Write a program to process a vector<string>s whose elements represent integral values.
//Produce the sum of all the elements in that vector.
void ex9_50_1() {
	vector<string> svec{ "1","2","3","4","5","6" };
	int result = 0;
	for (auto begin = svec.cbegin(); begin != svec.cend(); ++begin) {
		cout << *begin << ' ';
		result += stoi(*begin);
	}
	cout << ':' << result << endl;
}

void ex9_50_2() {
	vector<string> svec{ "1.5","2.3","3.4","4.5","5.3","6.2" };
	double result = 0;
	for (auto begin = svec.cbegin(); begin != svec.cend(); ++begin) {
		cout << *begin << ' ';
		result += stod(*begin);
	}
	cout << ':' << result << endl;
}

//Write a class that has three unsigned members representing year, month, day.
//Write a constructor that takes a string representing a date.
//Your constructor should handle a variety of date formats, such as 
//January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
class ex9_51_date {
public:
	ex9_51_date(const string &s);
	unsigned year;
	unsigned month;
	unsigned day;
};

ex9_51_date::ex9_51_date(const string &s) {
	unsigned format = 0;
	//! 1/1/1900
	if (s.find_first_of("/") != std::string::npos) format = 0x10;

	//! Jan 1, 1900
	if (s.find_first_of(",") >= 4 && s.find_first_of(",") != std::string::npos)
		format = 0x01;

	switch (format) {

		//! format = 1/1/1900
	case 0x10:
		day = std::stoi(s.substr(0, s.find_first_of("/")));
		month = std::stoi(s.substr(s.find_first_of("/") + 1,
			s.find_last_of("/") - s.find_first_of("/") - 1));
		year = std::stoi(s.substr(s.find_last_of("/") + 1, 4));
		break;

		//! format = January 1, 1900  or Jan 1, 1900
	case 0x01:
		day = std::stoi(
			s.substr(s.find_first_of("1234567890"),
				s.find_first_of(",") - s.find_first_of("1234567890")));

		if (s.find("Jan") < s.size()) month = 1;
		if (s.find("Feb") < s.size()) month = 2;
		if (s.find("Mar") < s.size()) month = 3;
		if (s.find("Apr") < s.size()) month = 4;
		if (s.find("May") < s.size()) month = 5;
		if (s.find("Jun") < s.size()) month = 6;
		if (s.find("Jul") < s.size()) month = 7;
		if (s.find("Aug") < s.size()) month = 8;
		if (s.find("Sep") < s.size()) month = 9;
		if (s.find("Oct") < s.size()) month = 10;
		if (s.find("Nov") < s.size()) month = 11;
		if (s.find("Dec") < s.size()) month = 12;

		year = std::stoi(s.substr(s.find_last_of(" ") + 1, 4));
		break;
	}
}


void test_diff_capacity_resize() {
	vector<int> vi{ 1,2,3,};
	cout << vi.capacity() << endl;
	vi.resize(8, 5);
	cout << vi.capacity() << endl;
	Print(vi);
	vi.resize(2, 5);
	cout << vi.capacity() << endl;
	Print(vi);
	//resize() can not reduce the memory capacity of a container. 
}

int main(){
	//ex9_12();
	//ex9_14();
	//ex9_15();
	//ex9_16();
	//ex9_18();
	//ex9_19();
	//ex9_20();
	//ex9_21();
	/*vector<int> ivec{ 1,2,3,4,5,6,7,8 };
	ex9_22(ivec, 2);*/
	//ex9_24();
	//ex9_26();
	//ex9_27();

	//forward_list<string> sflt{ "hi", "hello", "nihao","seeyou","byebye" };
	//ex9_28(sflt, "helloo","nice");
	//Print(sflt);

	//ex9_31();
	//ex9_34();
	//ex9_38();
	//ex9_41();

	/*string str{ "To drive straight thru is a foolish, tho courageous act." };
	ex9_43(str, "thru", "through");
	ex9_43(str, "tho", "though");
	cout << str << endl;*/

	/*string str{ "To drive straight thru is a foolish, tho courageous act." };
	ex9_44(str, "thru", "through");
	ex9_44(str, "tho", "though");
	cout << str << endl;*/

	/*string s{ "Magee" };
	ex9_45(s, "Mr.", "Jr.");
	cout << s << endl;*/

	/*string s{ "Magee" };
	ex9_46(s, "Mr.", "Jr.");
	cout << s << endl;*/
	
	//ex9_47_1();
	//ex9_47_2();
	
	//ex9_49();
	//ex9_50_1();
	//ex9_50_2();

	ex9_51_date d("99/21/3871");
	cout << d.day << " " << d.month << " " << d.year << " ";

	//test_diff_capacity_resize();

	return 0;
}