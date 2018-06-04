#pragma once
#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class TextQuery {
public:
	TextQuery(fstream& ifile):infile(ifile){
		string str;
		while (getline(infile, str)) {
			line.push_back(str);
			istringstream is(str);
			string word;
			while (is >> word)
				result[word].emplace(line.size());
		}
	}
	void query(const string& s) {
		if (result.find(s) != result.end()) {
			if (result[s].size() > 1)
				cout << s << " occur " << result[s].size() << " times." << endl;
			else
				cout << s << " occurs " << result[s].size() << " time." << endl;
			for(auto & e : result[s]) {
				cout << "(line " << e << "):" << line[e - 1] << endl;
			}
		}
		else {
			cout << s << " not found." << endl;
		}
	}
private:
	fstream& infile;
	vector<string> line;
	map<string, set<int>> result;
};
#endif