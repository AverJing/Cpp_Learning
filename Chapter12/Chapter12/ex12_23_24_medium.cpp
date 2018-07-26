/*
*
*@author£ºAver Jing
*@description£ºWrite a program to concatenate two string literals,putting the result in a dynamically
*allocated array of char.Write a program to concatenate two library strings that have 
*the same value as the literals used in the first program.
*@date£ºJuly 25, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void ex12_23() {
	const char* p1 = "hello ";
	const char* p2 = "world.";
	unsigned int len = strlen(p1) + strlen(p2) + 1;
	char* c = new char[len]();
	strcat_s(c, len, p1);
	strcat_s(c, len, p2);
	cout << c << endl;

	//ex12.24
	string s1{ "hello " };
	string s2{ "world." };
	strcpy_s(c, len, (s1 + s2).c_str());
	cout << c << endl;
	//char* s = new char[10]("ssss");
	delete[] c;
}

int main() {

	return 0;
}