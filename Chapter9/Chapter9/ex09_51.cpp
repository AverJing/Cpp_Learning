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
#include <string>

using std::string;

//记得effective C++中有对年月日的约束，忘记具体位置了
struct Date {
	Date(const string&);
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

int main(){
	Date d("Jan 1 2018");
	std::cout << d.day << " " << d.month << " " << d.year << " ";
}

Date::Date(const string &s)
{
	unsigned format = 0;

	//  1/1/1900
	if (s.find_first_of('/') != string::npos) format = 1;
	// Jan, 1 1900
	else if (s.find_first_of(',') >= 4 && s.find_first_of(',') != string::npos)
		format = 2;
	//Jan 1 1900
	else format = 3;

	switch (format) {
	//  1/1/1900
	case 1:
		day = std::stoi(s.substr(0, s.find_first_of('/')));
		month = std::stoi(s.substr(s.find_first_of('/') + 1,
			s.find_last_of('/') - s.find_first_of("/") - 1));
		year = std::stoi(s.substr(s.find_last_of("/") + 1, 4));
		break;
	
	case 2:
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

	case 3:
		day = std::stoi(s.substr(s.find_first_of(' ') + 1,
			s.find_last_of(' ') - s.find_first_of(' ') - 1));

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
