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

//最开始的版本

class String
{
public:
	String(const char* s = "");
	String(const String& rhs);
	String& operator=(const String& rhs);
	const char& operator[](const size_t index) const;
	char& operator[](const size_t index);
	~String();

private:
	struct StringValue{
		unsigned int rCount;
		char* data;
		bool shareable;
		StringValue(const char* initValue="");
		~StringValue();
	};
	StringValue* value;
};

int main(){
	
}

String::String(const char* s):value(new StringValue(s))
{
}

String::String(const String & rhs)
{
	if (rhs.value->shareable) {
		value = rhs.value;
		++value->rCount;
	}
	else {
		value = new StringValue(rhs.value->data);
	}
}

String & String::operator=(const String & rhs)
{
	//考虑自我赋值   每次实现赋值操作，提前想想
	if (value == rhs.value)
		return *this;
	if (--value->rCount == 0)
		delete value;
	value = rhs.value;
	++value->rCount;

	return *this;
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
	if (value->rCount > 1) {
		--value->rCount;
		value = new StringValue(value->data);
	}
	value->shareable = false;	//add this
	//see It30  proxy class for more details

	return value->data[index];
}

String::~String()
{
	if (--value->rCount == 0)delete value;
}

String::StringValue::StringValue(const char * initValue):rCount(1),shareable(true)
{
	data = new char[strlen(initValue) + 1];
	strcpy(data, initValue);
}

String::StringValue::~StringValue()
{
	delete[] data;
}