/*
*
*@author£ºAver Jing
*@description: a part of exercise in CH11
*@date£ºMay 21, 2018
*
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <utility>

#include "Sales_data.h"

using namespace std;

template<class T>
void Print(T &t) {
	for (const auto&e : t)
		cout << e << ' ';
	cout << endl;
}

//Write your own version of the word-counting program.
void ex11_3() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		++word_count[word];
	}
	for (const auto &e : word_count)
		cout << e.first << " occurs " << e.second << (e.second > 1 ? " times." : " time.") << endl;
}

//Extend your program to ignore case and punctuation.
void ex11_4() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		word.erase(remove_if(word.begin(), word.end(), ispunct));
		for (auto &ch : word) ch = tolower(ch);
		++word_count[word];
	}
	for (const auto &e : word_count)
		cout << e.first << " occurs " << e.second << (e.second > 1 ? " times." : " time.") << endl;
}

//Define a map for which the key is the family's last name and the value is a vector
//of the children's names.Write code to add new families and to add new children 
//to existing family.
void ex11_7() {
	map<string, vector<string>> family;
	string last_name;
	string chld_name;
	/*1.
	while (cin >> last_name) {
		cout << "Enter children's name:";
		string name;
		while (cin >> name) {
			family[last_name].push_back(name);
		}
	}*/
	//2.
	while ([&]()->bool {
		cout << "Please enter last name\n";
		return cin >> last_name && last_name != "q";
	}()) {
		cout << "Enter children's name:\n";
		while (cin >> chld_name && chld_name != "q") {
			family[last_name].push_back(chld_name);
		}
	}

	for (const auto &e : family) {
		cout << e.first << ' ';
		Print(e.second);
	}
}

//Write a program that stores the excluded words in a vector instead of in a set.
//What are the advantages to using a set?
void ex11_8() {
	map<string, size_t> word_count;
	vector<string> exclude{ "The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a" };
	string word;

	while (cin >> word) {
		if (find(exclude.begin(), exclude.end(), word) == exclude.end())
			++word_count[word];
	}
	for (const auto &e : word_count)
		cout << e.first << " occurs " << e.second << (e.second > 1 ? " times." : " time.") << endl;
}

//Define a map that associates words with a list of line numbers on which the word might occur.
//Note: Key types for ordered containers is required to be able to compare.(such as < oprator)
bool compareIsbn(Sales_data &lhs, Sales_data &rhs) {
	return lhs.ISBN() < rhs.ISBN();
}

void ex11_9_11() {
	//ex11_9
	map<string, list<int>> word_line;

	//ex11_11
	using compareType = bool(*) (Sales_data &lhs, Sales_data &rhs);
	multiset<Sales_data, compareType> bookstore(compareIsbn);
}

//Write a program to read a sequence of strings and ints, storing each into a pair.
//store the pairs in a vector.
void ex11_12() {
	vector<pair<string, int>> pvec;
	string s;
	int i;
	while (cin >> s >> i) {
		//1.
		//pvec.push_back({ s, i });
		//2.
		//pvec.push_back(pair<string, int>(s, i));
		//3.
		//pvec.push_back(make_pair(s, i));
		//4. easiest way
		pvec.emplace_back(s, i);
	}

	for (const auto& e : pvec) {
		cout << e.first << ' ' << e.second << endl;
	}
}

//Extend the map of children to their family name that you wrote for the exercises 
//in exercise 11.7 by having the vector store a pair that holds a child's name and birthday.
void ex11_14() {
	map<string, vector<pair<string, string>>> family;
	string last_name;
	string chld_name;
	string chld_birth;
	/*1.
	while (cin >> last_name) {
	cout << "Enter children's name:";
	string name;
	while (cin >> name) {
	family[last_name].push_back(name);
	}
	}*/
	//2.
	while ([&]()->bool {
		cout << "Please enter last name\n";
		return cin >> last_name && last_name != "q";
	}()) {
		cout << "Enter children's name:\n";
		while (cin >> chld_name >> chld_birth && chld_name != "q" && chld_birth != "q") {
			family[last_name].emplace_back(chld_name, chld_birth);
		}
	}

	for (const auto &e : family) {
		cout << e.first << ' ';
		for (const auto& s : e.second)
			cout << s.first << ' ' << s.second << endl;
	}
}

//Rewrite the word-counting program from exercise 11.3 to use insert instead of subscripting.
//Which program do you think is easier to write and read?
void ex11_20() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		//++word_count[word];
		auto ret = word_count.insert({ word , 1});
		if (!ret.second)
			++ret.first->second;
	}
	for (const auto &e : word_count)
		cout << e.first << " occurs " << e.second << (e.second > 1 ? " times." : " time.") << endl;
}

//Assuming word_count is a map from string to size_t and word is a string, explain the following
//loop:
//while(cin >> word)
// ++word_count.insert({word, 0}).first->second;
void ex11_21() {
	//which means this:
	//++ ((word_count.insert({ word, 0 })).first->second);
}

//Given a map<string, vector<int>>, write the types used as an argument and as the return value
//for the version of insert that inserts one element.
void ex11_22() {
	//pair<string, vector<int>> //arguement
	//pair<map<string, vector<int>>::iterator, bool> //return
}

//Rewrite the map that stored vectors of children's names with a key that is the family last
//name for the exercise 11.7 to use a multimap.
void ex11_23() {
	multimap<string, string> family;
	string last_name;
	string chld_name;
	while (cin >> last_name >> chld_name && last_name != "q" &&chld_name != "q") {
			family.emplace(last_name, chld_name);
	}
	for(const auto &e : family) {
		cout << e.first << ' ' << e.second;
	}
}

//Write a program that defines a multimap of authors and their works. Use find to find an element
//in the multimap and erase that element. Be sure your program works correctly if the element you
//look for is not in the map.
void ex11_31(string index,string pwork) {
	multimap<string, string> author_work;
	string author, work;
	while (cin >> author >> work) {
		author_work.emplace(author, work);
	}
	for (auto ret = author_work.find(index); ret != author_work.cend() && ret->first == index;) {
		if (ret->second == pwork)
			author_work.erase(ret);
		else
			++ret;
	}
	for (const auto &e : author_work) {
		cout << e.first << ' ' << e.second << endl;
	}
}

//Using the multimap from the previous exercise. write a program to print the list of 
//authors and their works alphabetically.
void ex11_32() {
	multimap<string, string> author_work{ {"a","aa"}, {"b", "bb"}, {"c", "cc"}, {"a", "abc"} };
	map<string, set<string>> order_author;
	for (const auto& e : author_work) {
		order_author[e.first].insert(e.second);
	}
	for (const auto &e : order_author) {
		cout << e.first << ':';
		for(const auto& work : e.second)
			cout << work << ' ';
		cout << endl;
	}
}

//Implement your own version of the word-transformation
map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;//holds the transformations
	string key, value;//key:a word to transform; value:phrase to use instead
	//read the first word into key and the rest of the line into value
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1)//check that there is a transformation
			trans_map[key] = value.substr(1);//skip leading
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;

	//ex11.35
	/*In buildMap, what effect, if any, would there be from rewriting 
	trans_map[key] = value.substr(1); as trans_map.insert({key, value.substr(1)})?*/
	/*use subscript operator: if a word does appear multiple times, 
	our loops will put the last corresponding phrase into trans_map
	  use insert: if a word does appear multiple times, 
	 our loops will put the first corresponding phrase into trans_map*/
}

const string& transform(string& word, const map<string, string>& trans_map) {
	//word.erase(remove_if(word.begin(), word.end(), ispunct));//ignore punctuations
	auto ret = trans_map.find(word);
	if (ret != trans_map.cend())
		return ret->second;
	else
		return word;

	//ex11.34
	//What would happen if we used the subscript operator instead of find in the transform function.
	//Because std::map's operator is not declared as const,
	//but m is declared as a reference to std::map with const.
	//If insert new pair,it will cause error.
}

void ex11_33(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);//store the transformations
	string text;				//hold each line from the input
	while (getline(input, text)) {//read a line of inputs
		istringstream line(text);//read each word
		string word;
		bool firstword = true;//controls whether a space is
		while (line >> word) {
			if (firstword)
				firstword = false;
			else
				cout << ' ';//print a space between words
			cout << transform(word, trans_map);//print the output
		}
		cout << endl;//done with this line of input
	}
}

//The rest of exercises will update in next time.
//Now I will ignore the part of unordered container.

int main() {
	//ex11_3();
	//ex11_4();
	//ex11_7();
	//ex11_8();
	//ex11_12();
	//ex11_14();
	//ex11_20();
	//ex11_21();
	//ex11_23();
	//ex11_31("dd", "aa");
	//ex11_32();

	ifstream map_file("map.txt"), input("input.txt");
	ex11_33(map_file, input);

	return 0;
}