#pragma once
#ifndef TextQueryTEMPLATE_H
#define TextQueryTEMPLATE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class QueryResult; //declaration needed for return type in the query function
class TextQueryTem
{
public:
	using line_no = vector<string>::size_type;
	TextQueryTem(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file; //input file
	//map of each word to the set of the lines in which that word appears
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQueryTem::TextQueryTem(ifstream &is):file(new vector<string>)
{
	string text;
	while (getline(is, text)) {//for each line in the file
		file->push_back(text);//remember this line of text
		int n = file->size() - 1;//the current line number
		istringstream line(text);//separate the line into words
		string word;
		while (line >> word) {//for each word in that line
			//if word isn't already in wm, subscripting adds a new entry
			auto &lines = wm[word];// lines is a shared_ptr
			if (!lines)//that pointer is null the first time we see word
				lines.reset(new set<line_no>);//allocate a new set 
			lines->insert(n);//insert this line number
		}
	}
}

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<TextQueryTem::line_no>> p, shared_ptr<vector<string>> f)
		:sought(s), lines(p), file(f) {};

private:
	string sought;//word this query represents
	shared_ptr<set<TextQueryTem::line_no>> lines;//lines it's on
	shared_ptr<vector<string>> file;//input file

};

string make_plural(unsigned int count, const string& st1, const string& st2)
{
	return (count > 1 ? st1 : st1 + st2);
}

ostream& print(ostream& os, const QueryResult& qr) {
	//if the word found, print the count and all occurrences
	os << qr.sought << " occurs " << qr.lines->size() << ' ' <<
		make_plural(qr.lines->size(), "time", "s") << endl;
	//print each line in which the word appeared
	for (auto num : *qr.lines)//for every element in the set
		//don't confound the user with text lines strating at()
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}

QueryResult TextQueryTem::query(const string& sought) const
{
	//we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//use find and not a subscript to avoid adding words to wm
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); //not found
	else 
		return QueryResult(sought, loc->second, file);
}

#endif