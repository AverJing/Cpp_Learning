/*
*
*@author£ºAver Jing
*@description£º
*@date£ºJune 19, 2018
*
*/

#include<iostream>
#include "ex16_14_Screen.h"

int main() {
	Screen<5, 5> screen('x');
	screen.set(2, 2, 'o');
	std::cout << screen << std::endl;

	std::cout << "please input some characters as you like:";
	std::cin >> screen;
	std::cout << screen << std::endl;
	
	return 0;
}
