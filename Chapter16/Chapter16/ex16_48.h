/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
#pragma once

#include <iostream>
#include <sstream>
#include <string>

using std::string;

//1
template<typename T> 
string debug_rep(const T&);

//2
template<typename T>
string debug_rep(T*);

//3
string debug_rep(const string&);

//4
string debug_rep(const char*);

//5
string debug_rep(char *);

template<typename T>
inline string debug_rep(const T &t)
{
	std::cout << "const T& 1" << t << std::endl;
	return t.str();
}


template<typename T>
inline string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "T*: 2" << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

inline string debug_rep(const string& s) {
	std::cout << "string& 3" << std::endl;
	return '"' + s + '"';
}

inline string debug_rep(const char *p)
{
	std::cout << "const char* 4" << std::endl;
	return debug_rep(string(p));
}

inline string debug_rep(char *p) {
	std::cout << "char* 5" << std::endl;
	return debug_rep(string(p));
}
