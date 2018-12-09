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

using Token = std::pair<char, double>;
using std::string;

//LeetCode  227

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
		case ';'://输出结果
		case 'q'://退出
		case '+': case '-': case '*': case '/': 
		case '(': case ')': case '{': case '}': case '!':
			return std::make_pair(ch, INT_MAX);
		case'.':
		case'0':case'1':case'2':case'3':case'4':
		case'5':case'6':case'7':case'8':case'9':
			{
			std::cin.putback(ch);
			double res;
			std::cin >> res;//借助cin读数字
			return std::make_pair('8', res); //随意选择的'8'当作数字标记
			}
		default:
			//error("Bad Token");
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

	switch (t.first) {
	case '8': {
		auto tmp = ts.get();
		if (tmp.first == '!') return factorial(t.second);
		else {
			ts.push_back(tmp);
			return t.second;
		}  //考虑在此处计算阶乘
	}		
	case'(': {//solve '(' expresion ')'
		double res = expression();
		//if (ts.get().first != ')') error("expression error");
		assert(ts.get().first == ')', "expression error");
		return res;
	}
	case'{': {//solve '{' expresion '}'
		double res = expression();
		//if (ts.get().first != ')') error("expression error");
		assert(ts.get().first == '}', "expression error");
		return res;
	}
	//增加一元运算
	case '+':
		return primary();
	case '-':
		return -primary();
	default:
		//error("primary expected!");
		assert(false, "primary expected!");
	}
}

double term() {
	double left = primary();
	auto t = ts.get();
	
	while (true) {
		switch (t.first)
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
		switch (t.first)
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

int main(){
	double val = 0;
	/*
	while (true) {
		Token t = ts.get();
		if (t.first == 'q') break;
		if (t.first == ';') {
			std::cout << val << "\n";
			continue;//输出结果时，记得重新开始计算新的结果
		}			
		else {
			ts.push_back(t);
		}
		val = expression();
	}*/
	while (true) {
		Token t = ts.get();	
		std::cout << "> ";
		while(t.first == ';') {
			t = ts.get();
		}
		if (t.first == 'q') break;
		ts.push_back(t);
		std::cout << "= " << expression() << "\n"; 
	}
}	