/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>

template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);


int main(){
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42); //3
	g(p);  //4
	g(ci); //3
	g(p2); //4
	f(42); //1
	f(p); //2  error, fix:1
	f(ci); //1
	f(p2); //2
}

template<typename T>
void f(T)
{
	std::cout << "f(T) 1" << std::endl;
}

template<typename T>
void f(const T *a)
{
	std::cout << "f(const T*) 2" << std::endl;
}

template<typename T>
void g(T)
{
	std::cout << "g(T) 3" << std::endl;
}

template<typename T>
void g(T *)
{
	std::cout << "g(*T) 4" << std::endl;
}
