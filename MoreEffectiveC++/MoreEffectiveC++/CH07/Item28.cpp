/*
*
*
*@author: Aver Jing
*@description： 为了方便查阅，我把实现和头文件声明放在一起
*@date：
*
*
*/

#include <iostream>
#include <functional>

//参见  C++ Primer CH16  ex28

//书中智能指针的实现
template<typename T>
class SmartPointer {
public:
	void swap(SmartPointer& lhs, SmartPointer& rhs) {
		using std::swap;
		swap(lhs.ptr, rhs.ptr);
		swap(count, rhs, count);
		swap(deleter, rhs.deleter);
	}
	//default constructor
	SmartPointer() = default;
	
	~SmartPointer() { std::cout << "free memory" << std::endl; delete count; }
	size_t GetCount() const{ return *count; }

	T& operator*()const { //注意不可以更改ptr，可以更改ptr指向的变量的内容
		return *ptr;
	}
	T* operator->()const {
		return &(this->operator*());
	}
private:
	//C++ 11 允许类内初始化，注意静态变量还需要在外部显式声明
	//注意有些时候()的类内初始化会带来歧义  函数还是初始化。。。
	T* ptr = nullptr;
	size_t* count = new size_t(1);  //多个智能指针共享该计数变量
	std::function<void(T*)> deleter{ [](const T* p) {delete p; } };
	void decrement_n_destroy();

	//书中给出的   灵巧指针 不允许拷贝和赋值
	//copy constructor
	SmartPointer(const SmartPointer& rhs) :
		ptr(rhs.ptr), count(rhs.count), deleter(rhs.deleter) {
		++*count;
	}
	//注意
	SmartPointer& operator=(const SmartPointer& rhs) {
		++*rhs.count;

		decrement_n_destroy();

		ptr = rhs.ptr;
		count = rhs.count;
		deleter = rhs.deleter;
	}
};

int main(){
	SmartPointer<int> p;
	std::cout << p.GetCount() << std::endl;
}

template<typename T>
void SmartPointer<T>::decrement_n_destroy()
{
	if (ptr) {
		if (--*count == 0) {
			deleter(ptr);
			delete count;
		}
		ptr = nullptr;
		count = nullptr;
	}
}
