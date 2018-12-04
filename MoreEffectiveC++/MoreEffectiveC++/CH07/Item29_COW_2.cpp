/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

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

//version2   使用RCObject和灵巧指针实现对引用计数的抽象

template <class T>
class RCPtr;

class String
{
public:
	String(const char* s = "");

	//consider why cancle copy constructor, operator= and destructor
	//String(const String& rhs);
	//String& operator=(const String& rhs);
	//~String();
	const char& operator[](const size_t index) const;
	char& operator[](const size_t index);
	

private:
	struct StringValue : public RCObject{
		//unsigned int rCount;
		char* data;
		//bool shareable;
		StringValue(const char* initValue = "");
		StringValue(const StringValue& rhs);
		void init(const char* initValue);
		~StringValue();
	};
	RCPtr<StringValue> value;
};

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
	T* operator->()const;
	T& operator*() const;
private:
	T* pointee;

	void init();
};

int main() {

}

String::String(const char* s) :value(new StringValue(s))
{
}

const char & String::operator[](const size_t index) const
{
	//此处简单，没有考虑是否越界
	return value->data[index];
}

char & String::operator[](const size_t index)
{
	//lazy copy   
	//与其它对象共享一个值直到写操作时才拥有自己的拷贝

	//必须要考虑到可能更改string
	//将该字符串从共享中分离出来
	if (value->isShared()) {
		value->removeReference();
		value = new StringValue(value->data);
	}
	value->markUnshareable();

	return value->data[index];
}

String::StringValue::StringValue(const char * initValue)
{
	init(initValue);
}

String::StringValue::~StringValue()
{
	delete[] data;
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
RCPtr<T>::RCPtr(T * realPtr):pointee(realPtr)
{
	init();
}

template<class T>
RCPtr<T>::RCPtr(const RCPtr & rhs):pointee(rhs.pointee)
{
	init();
}

template<class T>
RCPtr<T>::~RCPtr()
{
	if (pointee) pointee->removeReference();
}

template<class T>
RCPtr<T>& RCPtr<T>::operator=(const RCPtr & rhs)
{
	if (pointee != rhs.pointee) {
		if (pointee) {
			pointee->removeReference();
		}
		pointee = rhs.pointee;
		init();
	}

	return *this;
}

template<class T>
T * RCPtr<T>::operator->() const
{
	return pointee;
}

template<class T>
T & RCPtr<T>::operator*() const
{
	return *pointee;
}

template<class T>
void RCPtr<T>::init()
{
	if (!pointee) return;

	if (pointee->isShareable() == false) {
		pointee = new T(*pointee);
	}

	pointee->addRefence();
}

String::StringValue::StringValue(const StringValue & rhs)
{
	init(rhs.data);
}

void String::StringValue::init(const char * initValue)
{
	data = new char[strlen(initValue) + 1];
	strcpy(data, initValue);
}
