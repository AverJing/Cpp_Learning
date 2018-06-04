#pragma once
#ifndef TextQuerySTRBLOB_H
#define TextQuerySTRBLOB_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include "StrBlob.h"

using namespace std;

class QueryResultStrBlob; //declaration needed for return type in the query function
class TextQueryStrBlob
{
public:
	using line_no = StrBlob::size_type;
	TextQueryStrBlob(ifstream&);
	QueryResultStrBlob query(const string&) const;
private:
	shared_ptr<StrBlob> file; //input file
									 //map of each word to the set of the lines in which that word appears
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQueryStrBlob::TextQueryStrBlob(ifstream &is) :file(new StrBlob)
{
	string text;
	while (getline(is, text)) {//for each line in the file
		file->push_back(text);//remember this line of text
		int n = file->size() - 1;//the current line number
		istringstream line(text);//separate the line into words
		string word;
		while (line >> word) {//for each word in that line
			word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
							  //if word isn't already in wm, subscripting adds a new entry
			auto &lines = wm[word];// lines is a shared_ptr
			if (!lines)//that pointer is null the first time we see word
				lines.reset(new set<line_no>);//allocate a new set 
			lines->insert(n);//insert this line number
		}
	}
}

class QueryResultStrBlob
{
	friend ostream& print(ostream&, const QueryResultStrBlob&);
public:
	using Iter = set<TextQueryStrBlob::line_no>::iterator;
	using Sptr = shared_ptr<StrBlob>;
	QueryResultStrBlob(string s, shared_ptr<set<TextQueryStrBlob::line_no>> p, shared_ptr<StrBlob> f)
		:sought(s), lines(p), file(f) {};
	Iter begin() { return lines->begin(); }
	Iter end() { return lines->end(); }
	Sptr get_file() { return file; }
private:
	string sought;//word this query represents
	shared_ptr<set<TextQueryStrBlob::line_no>> lines;//lines it's on
	shared_ptr<StrBlob> file;//input file

};

string make_plural_str(unsigned int count, const string& st1, const string& st2)
{
	return (count > 1 ? st1 : st1 + st2);
}

ostream& print(ostream& os, const QueryResultStrBlob& qr) {
	//if the word found, print the count and all occurrences
	os << qr.sought << " occurs " << qr.lines->size() << ' ' <<
		make_plural_str(qr.lines->size(), "time", "s") << endl;
	//print each line in which the word appeared
	for (auto num : *qr.lines)//for every element in the set
							  //don't confound the user with text lines strating at()
	{
		StrBlobPtr p(*qr.file, num);
		os << "\t(line " << num + 1 << ") " << p.deref() << endl;
	}

		
	return os;
}

QueryResultStrBlob TextQueryStrBlob::query(const string& sought) const
{
	//we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//use find and not a subscript to avoid adding words to wm
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResultStrBlob(sought, nodata, file); //not found
	else
		return QueryResultStrBlob(sought, loc->second, file);
}

#endif