/*
*
*@author£ºAver Jing
*@description£ºImplement your own version of the word-transformation program.
*@date£ºJuly 24, 2018
*
*/

#include<iostream>
#include <fstream>
#include <sstream>
#include "base_tool.h"

using namespace std;

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
int main() {

	return 0;
}