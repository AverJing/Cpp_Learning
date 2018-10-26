/*
*
*@author£ºAver Jing
*@description£ºThe program in this section defined its istringstream
*object inside the outer while loop. What changes would you need to make if
*record were defined outside that loop? Rewrite the program, moving the
*definition of record outside the while, and see whether you thought of all
*the changes that are needed.
*@date£ºJuly 18, 2018
*
*/

#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//aggregate class
struct PersonInfo
{
	string name;
	vector<string> phones;
};

void ex8_11(const string &fileName) {
	ifstream ifle(fileName);
	string line, word;
	vector<PersonInfo> people;
	std::istringstream record;
	while (getline(ifle, line)) {
		PersonInfo info;
		record.clear();
		record.str(line);  //key point
		record >> info.name;
		while (record >> word) info.phones.push_back(word);
		people.push_back(info);
	}

	for (auto& p : people) {
		cout << p.name << " ";
		for (auto& s : p.phones) cout << s << " ";
		cout << endl;
	}
}

int main() {
	ex8_11("Person.txt");

	return 0;
}