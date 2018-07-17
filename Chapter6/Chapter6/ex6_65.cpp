/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cout;

//!
//! @brief Exercise 6.54
//! @note  define the function type fp
//!
inline int f(const int, const int);
typedef decltype(f) fp; // fp is just a function type not a function pointer

						//!
						//! @brief Exercise 6.55
						//! @note  Store pointers to these functions in the vector
						//!
inline int NumAdd(const int n1, const int n2)
{
	return n1 + n2;
}
inline int NumSub(const int n1, const int n2)
{
	return n1 - n2;
}
inline int NumMul(const int n1, const int n2)
{
	return n1 * n2;
}
inline int NumDiv(const int n1, const int n2)
{
	return n1 / n2;
}

vector<fp*> v{ NumAdd, NumSub, NumMul, NumDiv };

int main()
{
	//!
	//! @brief Exercise 6.56
	//! @note  Call each element in the vector and print their result.
	//!
	for (auto it = v.cbegin(); it != v.cend(); ++it)
		cout << (*it)(2, 2) << std::endl;

	return 0;
}