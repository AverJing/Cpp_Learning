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
#include <memory>

using std::shared_ptr;
using std::weak_ptr;

int main(){
	shared_ptr<int> p(new int(22));
	weak_ptr<int> wp = p;

	std::cout << wp.use_count() << ' ' << p.use_count() << std::endl;
}	