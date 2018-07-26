/*
*
*@author£ºAver Jing
*@description£ºWrite a function that returns a dynamically allocated vector
*of ints. Pass that vector to another function that reads the standard input
*to give values to the elements. Pass the vector to another function to print
*the values that were read. Remember to delete the vector at the
*appropriate time
*@date£ºJuly 25, 2018
*
*/

#include<iostream>
#include "base_tool.h"

vector<int>* dynamic_vector_generator() {
	auto *p = new vector<int>();
	return p;
}
void dynamic_vector_input(vector<int>* p) {
	int i;
	while (cin >> i) p->push_back(i);
}
void dynamic_vector_print(vector<int>* p) {
	for (const auto& e : *p)
		cout << e << ' ';
	cout << endl;
}

//Redo the previous exercise, this time using shared_ptr.
//ex12.7
shared_ptr<vector<int>> dynamic_vector_generator_sptr() {
	return make_shared<vector<int>>();
}
void dynamic_vector_input_sptr(shared_ptr<vector<int>> p) {
	int i;
	while (cin >> i) p->push_back(i);
}
void dynamic_vector_print_sptr(shared_ptr<vector<int>> p) {
	for (const auto& e : *p)
		cout << e << ' ';
	cout << endl;
}


int main() {

	return 0;
}