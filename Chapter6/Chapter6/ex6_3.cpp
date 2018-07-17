/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include <iostream>
#include <string>

int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}

void factorial_with_interacts() {
	for (int val = 0; std::cout << "Enter a number within [0, 13): ", std::cin >> val; ) {
		if (val < 0 || val > 12) continue;
		std::cout << val << "! =" << fact(val) << std::endl;
	}
}

int main()
{
	factorial_with_interacts();
}