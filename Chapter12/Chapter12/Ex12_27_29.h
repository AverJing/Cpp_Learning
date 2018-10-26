/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>

using std::shared_ptr;
using std::vector;
using std::string;
using std::map;
using std::set;

class QueryResult;

class TextQuery
{
public:
	TextQuery(std::fstream& input);
	~TextQuery();
	QueryResult query(const string& key);
private:
	shared_ptr<vector<string>> line;
	map<string, shared_ptr<set<size_t>>> result;
};

class QueryResult {
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);
	QueryResult(string s, shared_ptr<vector<string>> f, shared_ptr<set<size_t>> p)
		:key(s), line(f), lineNum(p) {
		//std::cout << "call qr cons..." << std::endl;
	}
private:
	string key;
	shared_ptr<vector<string>> line;
	shared_ptr<set<size_t>> lineNum;
};

TextQuery::TextQuery(std::fstream& input):line(std::make_shared<vector<string>>())
{
	string str;
	while (std::getline(input, str)) {
		line->push_back(str);
		std::istringstream in(str);
		auto n = line->size() - 1;
		string word;
		while (in >> word) {
			//需要更改指针本身，需要引用
			auto &p = result[word];  //是引用
			if (!p) {
				p.reset(new set<size_t>);  //注意  参数是内置指针
			}
			p->insert(n);
		}
	}
}

TextQuery::~TextQuery()
{
}


QueryResult TextQuery::query(const string& key) {
	auto loc = result.find(key);
	if (loc == result.end())
	{
		return QueryResult(key, line, nullptr);
	} 
	else
		return QueryResult(key, line, loc->second);
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
	//if the word found, print the count and all occurrences
	if (qr.lineNum) {
		os << qr.key << " occur(s) " << qr.lineNum->size() << ' ' <<
			 "time(s)" << std::endl;
		//print each line in which the word appeared
		for (auto num : *qr.lineNum)//for every element in the set
			//don't confound the user with text lines strating at()
			os << "\t(line " << num + 1 << ") " << *(qr.line->begin() + num) << std::endl;
	}
	return os;
}