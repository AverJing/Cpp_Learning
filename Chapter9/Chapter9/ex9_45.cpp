/*
*
*@author£ºAver Jing
*@description£ºWrite a funtion that takes a string representing a name
*and two other strings representing a prefix, such as ¡°Mr.¡± or ¡°Ms.¡± and a
*suffix, such as ¡°Jr.¡± or ¡°III¡±. Using iterators and the insert and append
*functions, generate and return a new string with the suffix and prefix
*added to the given name.
*@date£ºJuly 19, 2018
*
*/

#include <iostream>
#include <string>

using namespace std;

string ex9_45(string &name, const string &prefix, const string &suffix) {
	name.insert(0, prefix);
	//or
	//name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(suffix);

	//ex9_46
	//Rewrite the previous exercise using a position and length to
	//manage the strings.This time use only the insert function.
	name.insert(0, prefix);
	name.insert(name.size(), suffix);

	return name;
}

int main() {
	string name = "aver_jing";
	cout << ex9_45(name, "Mr.", "III");
	return 0;
}