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
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

using std::string;
using std::vector;

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';
const char let = 't';
const string declkey = "let";

struct Variable {
	string name;
	double value;
};

struct Token {
	char kind;
	double value;
	string name;
	Token() {}
	Token(char ch) :kind(ch) {}
	Token(char ch, double value) :kind(ch),value(value) {}
	Token(char ch, string n) :kind(ch),name(n) {}
};

/*
void error(const string& s) {
	throw std::runtime_error(s);
}*/

class Token_stream {
public:
	//get
	Token get() {
		if (full) {
			full = false;
			return buffer;
		}

		char ch;
		std::cin >> ch;

		switch (ch) {
		case print://输出结果
		case quit://退出
		case '=':
		case '+': case '-': case '*': case '/': case '%':
		case '(': case ')': case '{': case '}': case '!':
			return Token(ch, INT_MAX);
		case'.':
		case'0':case'1':case'2':case'3':case'4':
		case'5':case'6':case'7':case'8':case'9':
		{
			std::cin.putback(ch);
			double res;
			std::cin >> res;//借助cin读数字
			return Token('8', res); //随意选择的'8'当作数字标记
		}
		default:
			//error("Bad Token");
			if (isalpha(ch)) {
				string s;
				s += ch;
				while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				std::cin.putback(ch);
				if (s == declkey) return Token(let);
				return Token(name, s);
			}
			assert(false, "pushback in full buffer");
		}

	}
	//push_back
	void push_back(Token t) {
		//if (full) error("pushback in full buffer");
		assert(!full, "pushback in full buffer");
		buffer = t;
		full = true;
	}
private:
	Token buffer;
	bool full{ false };
};

Token_stream ts; //提供get和push_back
double expression(); //前置声明
vector<Variable> var_table;

double get_value(const string& s) {
	for (const auto& e : var_table) {
		if (e.name == s) {
			return e.value;
		}
	}
	assert(false, "get: undefined variable." + s);
}

void set_value(const string& s, double d) {
	for (auto& e : var_table) {
		if (e.name == s) {
			e.value = d;
			return;
		}
	}
	assert(false, "set: undefined variable." + s);
}

bool is_declared(const string& s) {
	//由于目前var_table不大，使用的vector，如果比较大还是推荐有序的map或者哈希容器
	//注意find是直接找值的，find_if才是可以使用谓词的
	auto res = std::find_if(var_table.cbegin(), var_table.cend(), [&](const Variable& lhs) {return s == lhs.name; });
	return res != var_table.end();
	/*for (const auto& e : var_table) {
		if (e.name == s) return true;
	}
	return false;*/
}

double define_name(const string& var, double val) {
	assert(!is_declared(var), "decalre twice.");

	var_table.push_back(Variable{ var,val });
	return val;
}

double declaration() {
	Token t = ts.get();
	assert(!(t.kind != name), "name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	assert(!(t2.kind != '='), "= missing in declaration" + var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}


double statement() {
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.push_back(t);
		return expression();
	}
}

/*
template<int N>
struct factorial {
	enum{res= N * factorial<N-1>::res};
};

template<>
struct factorial<1> {
	enum { res = 1};
};*/
//constexpr 不一定在编译期求值
int constexpr factorial(int n) {
	return (n < 2) ? 1 : n * factorial(n - 1);
}

double primary() {
	Token t = ts.get();

	switch (t.kind) {
	case number: {
		auto tmp = ts.get();
		if (tmp.kind == '!') return factorial(t.value);
		else {
			ts.push_back(tmp);
			return t.value;
		}  //考虑在此处计算阶乘
	}
	case'(': {//solve '(' expresion ')'
		double res = expression();
		//if (ts.get().kind != ')') error("expression error");
		assert(ts.get().kind == ')', "expression error");
		return res;
	}
	case'{': {//solve '{' expresion '}'
		double res = expression();
		//if (ts.get().kind != ')') error("expression error");
		assert(ts.get().kind == '}', "expression error");
		return res;
	}
			 //增加一元运算
	case '+':
		return primary();
	case '-':
		return -primary();
	case name:
		return get_value(t.name);
	default:
		//error("primary expected!");
		assert(false, "primary expected!");
	}
}

double term() {
	double left = primary();
	auto t = ts.get();

	while (true) {
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			auto tmp = primary();
			assert(std::abs(tmp) > 0.0000001, "divided by zero");
			left /= tmp;
			t = ts.get();
			break;
		}
		case '%': {
			auto tmp = primary();
			assert(std::abs(tmp) > 0.0000001, "divided by zero");
			left = fmod(left, tmp); //浮点数求余 x%y=x-y*int(x/y)
			t = ts.get();
			break;
		}
		default:
			ts.push_back(t);
			return left;
		}
	}
}

double expression() {
	double left = term();
	auto t = ts.get();

	while (true) {
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
		{
			left -= term();
			t = ts.get();
			break;
		}
		default:
			ts.push_back(t);
			return left;
		}
	}
}

void calculate() {
	while (true) {
		Token t = ts.get();
		std::cout << prompt;
		while (t.kind == print) {
			t = ts.get();
		}
		if (t.kind == quit) break;
		ts.push_back(t);
		std::cout << result << statement() << "\n";
	}
}


int main() {
	double val = 0;
	/*
	while (true) {
		Token t = ts.get();
		if (t.kind == 'q') break;
		if (t.kind == ';') {
			std::cout << val << "\n";
			continue;//输出结果时，记得重新开始计算新的结果
		}
		else {
			ts.push_back(t);
		}
		val = expression();
	}*/
	define_name("pi", 3.1415926);
	define_name("e", 2.7182818);

	calculate();//书中还有一些错误处理
}