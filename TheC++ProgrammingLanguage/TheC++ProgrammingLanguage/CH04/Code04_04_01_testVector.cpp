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
#include <vector>

using std::vector;

template<class T>
class Vec :public vector<T> {
public:
	using vector<T>::vector;  //使用vector的构造函数

	T& operator[](size_t index) {
		return vector<T>::at(index);
		//at会检查下标
	}

	const T& operator[](size_t index) const{
		return vector<T>::at(index);
	}
};

int main(){
	//标准库vector下标运算  No bounds checking is performed.
	//VC++ 给出了报错
	/*
	vector<int> s;
	std::cout << s[10];*/

	Vec<int> s;
	std::cout << s[10];
}	