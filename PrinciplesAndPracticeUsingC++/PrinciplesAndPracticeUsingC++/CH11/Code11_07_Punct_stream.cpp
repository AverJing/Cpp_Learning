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
#include <sstream>
#include <cctype>
#include <vector>

using std::istringstream;
using std::string;
using std::istream;
using std::vector;

class Punct_stream {
public:
	Punct_stream(istream& in, bool s) :source(in), sensitive(s) {}
	void whitespace(const string& s) { white = s; }//设置空白符
	void add_white(char c) { white += c; }//添加空白符
	bool is_whitespace(char c) {
		for(auto e : white) {
			if (c == e)
				return true;
		}
		return false;
	}
	void case_sensitive(bool b) { sensitive = b; }
	bool is_senstive() { return sensitive; }

	Punct_stream& operator>>(string& s);//重头戏。
	operator bool();//隐式类型转换
private:
	bool sensitive;
	string white;
	istringstream buffer;
	istream& source;
};

int main(){
	Punct_stream ps(std::cin, false);
	ps.whitespace(";:,.?!()\"{}<>&$@#^%*|~");

	std::cout << "please enter some words\n";

	vector<string> vs;
	for (string word; ps >> word;) {
		vs.push_back(word);
	}

	for (auto& e : vs)
		std::cout << e << ' ';
	std::cout << '\n';
}

Punct_stream & Punct_stream::operator>>(string & s)
{
	while (!(buffer >> s)) {//buffer里还有内容
		if (buffer.bad() || !source.good()) return *this;
		buffer.clear();

		string line;
		std::getline(source, line);

		for (auto &e : line) {
			if (is_whitespace(e))
				e = ' ';
			else if (!sensitive)
				e = std::tolower(e);
		}
		buffer.str(line);//将buffer变为line的拷贝
	}
	return *this;
}

inline Punct_stream::operator bool()
{
	return !(source.bad() || source.fail()) && source.good();
}
