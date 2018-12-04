/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

//注意COW，已经被C++11 抛弃了
//引用计数现在还在用， shared_ptr
//此处的实现，只是为了学习封装的思想，如何一步步编成比较好的实现
//为了方便阅读，没有把类实现分离
#include <iostream>

//version3   将引用计数加到任意类型上
//好好体会，shared_ptr的简单实现

class RCObject {
public:
	bool isShareable() const;
	bool isShared() const;
	void addReference();
	void markUnshareable();
	void removeReference();
protected:
	//note: see explaination in Book
	RCObject() :refCount(0), shareable(true) {};
	RCObject(const RCObject&) :refCount(0), shareable(true) {};
	RCObject& operator=(const RCObject& rhs) { return *this; }//abnormal
	virtual ~RCObject() = 0;
private:
	unsigned int refCount;
	bool shareable;
};

template <class T>
class RCPtr {
public:
	RCPtr(T* realPtr = 0);
	RCPtr(const RCPtr& rhs);
	~RCPtr();
	RCPtr& operator=(const RCPtr& rhs);
	const T* operator->()const;
	T* operator->();
	const T& operator*() const;
	T& operator*();
private:
	struct CountHolder : public RCObject {
		T* pointee;
		~CountHolder() { delete pointee; }
	};
	void init();
	CountHolder* counter;
	void makeCopy();
};

class Widget {
public:
	Widget(int size) :len(size) {};
	Widget(const Widget& rhs) :len(rhs.len) {}
	~Widget() = default;
	Widget& operator=(const Widget& rhs) = default;
	void doThis() { std::cout << "doThis" << std::endl; }
	int showThat() const { std::cout << "showThat" << std::endl; };
private:
	int len;
};

class RCWidget {
public:
	RCWidget(int size) :value(new Widget(size)) {}
	void doThis() { value->doThis(); }
	int showThat() const { return value->showThat(); }
private:
	RCPtr<Widget> value;
};

int main() {
	RCWidget rc(10);
	rc.doThis();
	RCWidget rc2(rc);

}

bool RCObject::isShareable() const
{
	return shareable;
}

bool RCObject::isShared() const
{
	return refCount > 1;
}

void RCObject::addReference()
{
	++refCount;
}

RCObject::~RCObject()
{
}

void RCObject::markUnshareable()
{
	shareable = false;
}

void RCObject::removeReference()
{
	//ensure that this is allocated by heap
	//or like shared_ptr provide deleter
	if (--refCount == 0)
		delete this;
}

template<class T>
RCPtr<T>::RCPtr(T * realPtr) :counter(new CountHolder)
{
	counter->pointee = realPtr;
	init();
}

template<class T>
RCPtr<T>::RCPtr(const RCPtr & rhs) :counter(rhs.counter)
{
	init();
}

template<class T>
RCPtr<T>::~RCPtr()
{
	if (counter->pointee) counter->removeReference();
}

template<class T>
RCPtr<T>& RCPtr<T>::operator=(const RCPtr & rhs)
{
	if (counter != rhs.counter) {
		counter->removeReference();
		counter = rhs.counter;
		init();
	}

	return *this;
}

template<class T>
const T * RCPtr<T>::operator->() const
{
	return counter->pointee;
}

template<class T>
T * RCPtr<T>::operator->()
{
	//difference
	makeCopy();
	return counter->pointee;
}

template<class T>
const T & RCPtr<T>::operator*() const
{
	return *(counter->pointee);
}

template<class T>
T & RCPtr<T>::operator*()
{
	//difference
	makeCopy();
	return *(counter->pointee);
}

template<class T>
void RCPtr<T>::init()
{
	if (counter->isShareable() == false) {
		auto oldValue = counter->pointee;
		counter = new CountHolder;
		counter->pointee = new T(*oldValue);
	}

	counter->addReference();
}

template<class T>
void RCPtr<T>::makeCopy()
{
	if (counter->isShared()) {
		T* oldValue = counter->pointee;
		counter->removeReference();
		counter = new CountHolder;
		counter->pointee = new T(*oldValue);
		counter->addReference();
	}
}