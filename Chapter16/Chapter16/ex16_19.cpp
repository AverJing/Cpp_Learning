/*
*
*@author£ºAver Jing
*@description£º
* Write a function that takes a reference to a container and prints the elements in that container
*Use the container's size_type and size members to control the loop prints the elements.
*@date£º
*
*/

#include<iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T> void Print(T&);

int main() {
	vector<int> ivec{ 1,2,3,4,5 };
	string s{ "abcdefg" };
	Print(ivec);
	cout << endl;
	Print(s);
	return 0;
}

template<typename T>
void Print(T &a)
{
	for (typename T::size_type i = 0; i != a.size(); ++i)
		cout << a[i] << ' ';
}
