/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

bool readFromFileAndWritetoFile(const std::string& infile, const std::string& outfile) {
	std::ifstream is{ infile };
	std::istream_iterator<std::string>  ii{ is };
	std::istream_iterator<std::string>  eof;

	std::vector<std::string> res{ ii,eof };
	std::sort(res.begin(), res.end());

	std::ofstream os{ outfile };
	std::ostream_iterator<std::string> oi{ os , "\n"};

	std::unique_copy(res.begin(), res.end(), oi);

	return !is.eof() || !os;
}

bool readFromFileAndWritetoFileSimple(const std::string& infile, const std::string& outfile) {
	std::ifstream is{ infile };
	std::ofstream os{ outfile };
	//set有序且无重复值
	std::set<std::string> res{ std::istream_iterator<std::string>{ is },std::istream_iterator<std::string>{} };

	std::copy(res.begin(), res.end(), std::ostream_iterator<std::string>{os, "\n"});

	return !is.eof() || !os;
}

int main(){
	//std::cout<< readFromFileAndWritetoFile("input.txt", "output.txt");
	std::cout << readFromFileAndWritetoFileSimple("input.txt", "output.txt");
}	