#pragma once
#ifndef EX16_5_PRINT_H
#define EX16_5_PRINT_H

#include <iostream>

template<typename T, unsigned N>
void print(const T(&a)[N]) {
	for (const auto &e : a)
		std::cout << e << ' ';
	/*for (unsigned i = 0; i != N; ++i)
		cout << a[i] << ' ';*/
	std::cout << std::endl;
}

#endif // !EX16_5_PRINT_H
