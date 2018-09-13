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
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;

//如果模板有两个模板参数，下边的特例化会出错。  必须为每个模板参数都提供参数
template<typename T>
int count(const vector<T>& t, const T f) {
	int num = 0;
	for (auto iter = t.begin(); iter != t.end(); ++iter)
		if (*iter == f) ++num;
	return num;
}

template<>
int count(const vector<const char *>& t, const char *f) {
	int num = 0;
	for (auto iter = t.begin(); iter != t.end(); ++iter)
		if (strcmp(*iter, f)) ++num;
	return num;
}

//test
template<typename T, typename F>
int count2(const vector<T>& t, const F f) {
	int num = 0;
	for (auto iter = t.begin(); iter != t.end(); ++iter)
		if (*iter == f) ++num;
	return num;
}

template<>
int count2(const vector<const char *>& t, const char *f) {
	int num = 0;
	for (auto iter = t.begin(); iter != t.end(); ++iter)
		if (strcmp(*iter, f)) ++num;
	return num;
}

int main(){
	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	int a = 1;
	cout << a << "occur()" << count(vec1, a) << "time(s)" << endl;

	vector<double> vec2;
	vec2.push_back(1.2);
	vec2.push_back(2.4);
	double b = 1.2;
	cout << b << "occur(s)" << count(vec2, b) << "time(s)" << endl;

	vector<string> vec3;
	vec3.push_back(string("123"));
	vec3.push_back(string("23"));
	string c = "123";
	cout << c << "occur(s)" << count(vec3, c) << "time(s)" << endl;

	vector<const char*> vec4;
	vec4.push_back("1230");
	vec4.push_back("123");
	const char *d = "1230";
	cout << d << "occur(s)" << count<const char *>(vec4, "1230") << "time(s)" << endl;
}	