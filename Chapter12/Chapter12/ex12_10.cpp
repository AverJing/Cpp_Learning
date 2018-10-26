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

//ex12.10
void process(std::shared_ptr<int> p) {
	std::cout << p.use_count() << std::endl;
}

int main(){
	std::shared_ptr<int> p(new int(22));
	process(std::shared_ptr<int>(p));
	//注意在传参时引用计数应该是3，但是临时对象析构了，process输出时应该时2
}	