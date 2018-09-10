/*
*
*@author£ºAver Jing
*@description£ºWrite and test your own versions of the compare functions
*@date£º
*
*/

#include<iostream>

using namespace std;

template<typename T> bool compare(const T& v1, const T& v2) {
	return (v1 < v2 ? true : false);
}//replace this with less<T>

template <unsigned int N, unsigned int M>//deduced by compile
int compare(const char(&p)[N], const char(&t)[M]) {//reference to an array
	return std::strcmp(p, t);
}

int main() {

	return 0;
}