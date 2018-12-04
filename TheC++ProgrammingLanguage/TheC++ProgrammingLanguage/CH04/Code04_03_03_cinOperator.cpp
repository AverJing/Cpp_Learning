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
using std::ostream;
using std::istream;

struct Entity {
	string name;
	int number;

	Entity(const string& s = "", int n = 0) :name(s), number(n) {}


	friend ostream& operator<<(ostream& os, Entity& s) {
		return os << "Name: " << s.name << " Number: " << s.number << std::endl;
		//简单优雅
	}

	//{"name", number}
	friend istream& operator>>(istream& in, Entity& s) {
		char c;
		//输入格式必须和上边的一样
		if (in >> c && c == '{' && in >> c && c == '"') {
			string name;
			while (in.get(c) && c != '"') //in.get(c) 不会跳过空格  in>>c会
				name += c;

			int num;
			if (in >> c && c == ',') {
				if (in >> num >> c && c == '}') {
					s = { name,num };
					return in;
				}
			}
		}
		in.setf(std::ios_base::failbit); //将流状态置为fail
	}
};

int main(){
	Entity e;

	std::cin >> e;
	std::cout << e;
}	