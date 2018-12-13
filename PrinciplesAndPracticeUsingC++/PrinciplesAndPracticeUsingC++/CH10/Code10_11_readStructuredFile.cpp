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
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::string;
using std::istream;
using std::ostream;

const int not_a_reading = -7777;
const int not_a_month = -1;
const int default_day = 32;
const int default_month = 12;

void error(const string& msg) {
	throw std::runtime_error("msg");
}

struct Day {
	vector<double> hour{ vector<double>(24, not_a_reading) };
};

struct Month {
	int month{ not_a_month };
	vector<Day> day{ default_day };
};

struct Year {
	int year;
	vector<Month> month{ default_month };
};

/*完整格式 
{year 200 
			{month feb (1 1 68) (2 3 66.66) (1 0 67.2)}
			{month dec (15 15 -9.2) (15 14 -9.2) (15 15 -9.2)}
}
*/

//使用Reading类来读取输入,更为简单
struct Reading {
	int day;
	int hour;
	double temperature;
};

istream& operator>>(istream& is, Reading& r) {
//将is中的温度读入到r中
//格式：(2 3 66.66)
//检查格式，但不考虑数据有效性
	char ch;
	if (is >> ch && ch != '(') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')') error("bad reading");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

//P268

int main(){
	
}	