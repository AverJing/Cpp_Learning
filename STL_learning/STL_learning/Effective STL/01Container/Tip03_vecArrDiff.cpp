
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

class Widget {
public:
	Widget() { std::cout << '1' << std::endl; }
};

int main(){
	vector<Widget> w;
	w.reserve(50);
	
	auto s = new vector<Widget>();
	s->reserve(50);
	
	delete	 s;
}	