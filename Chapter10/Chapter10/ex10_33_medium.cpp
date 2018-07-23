/*
*
*@author£ºAver Jing
*@description£ºWrite a program that takes the names of an input file and
*two output files. The input file should hold integers. Using an
*istream_iterator read the input file. Using ostream_iterators, write
*the odd numbers into the first output file. Each value should be followed by a
*space. Write the even numbers into the second file. Each of these values
*should be placed on a separate line.
*@date£ºJuly 23, 2018
*
*/

#include<iostream>
#include <fstream>
#include <iterator>
#include "base_tool.h"

using namespace std;

void ex10_33() {
	ifstream in("number.txt");
	istream_iterator<int> in_it(in), eof;

	ofstream odd_out("odd.txt");
	ofstream even_out("even.txt");
	ostream_iterator<int> odd(odd_out, " "), even(even_out, "\n");

	for_each(in_it, eof, [&odd, &even](const int i) { *(i & 0x1 ? odd : even)++ = i; });

}

int main() {

	return 0;
}