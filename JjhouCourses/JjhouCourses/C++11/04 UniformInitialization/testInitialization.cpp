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
#include <initializer_list>

class Test {
public:
	Test(const std::initializer_list<int>& t) :data(t) {}

	void print() {
		for (auto e : data)
			std::cout << e << ' ';
	}
private:
	std::vector<int> data;
};

int main(){
	Test t({ 5, 1, 2, 3, 4 });
	t.print();
}	