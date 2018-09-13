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
#include <string>

template<typename T, typename ... Args>
auto make_shared(Args&& ... args) -> std::shared_ptr<T> {
	return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main(){
	std::shared_ptr<std::string> spt = make_shared<std::string>(10, 'c');
	std::cout << *spt << std::endl;
}	