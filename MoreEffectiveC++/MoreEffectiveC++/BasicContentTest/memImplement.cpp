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
#include <cassert>

//blog.csdn.net/z702143700/article/details/47107701
void* memmoveBB(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	//dst <= src表示，如果dst在src的前面，从前往后复制不会覆盖src中还没有复制的内容

	if (dst <= src || (char*)dst >= ((char*)src + count))
	{
		//从前往后复制，则不会出现覆盖src中没有复制的内容
		while (count--)
		{
			*(char*)dst = *(char*)src; //char类型指针，表示一个字节一个字节的复制
			dst = (char*)dst + 1; //移动一个字节
			src = (char*)src + 1;
			//为什么*(char*)dst++  这样会直接报错？？ 而必须赋值后再进行移位
			//http://landcareweb.com/questions/42889/zhuan-huan-zhi-zhen-bu-hui-chan-sheng-zuo-zhi-wei-shi-yao
		}
	}
	else
	{
		//从后往前复制，则不会出现覆盖src中没有复制的内容
		dst = (char*)dst + count - 1;//移动到末尾
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1; //移动一个字节
			src = (char*)src - 1;
		}
	}
	//返回dst的头指针，还方便左值操作。
	//如：ptstr = memmove(ptstr,src,count); cout << memmove(ptstr,src,count);
	return ret;
}

void* memmoveByJing(void* dst, void* src, size_t count) {
	assert(dst != nullptr && nullptr != src);
	char* tmpDst = static_cast<char*>(dst);
	char* tmpSrc = static_cast<char*>(src);
	//说明从前到后复制，不会覆盖
	if (tmpDst < tmpSrc || tmpDst >= tmpSrc + count) {
		while (count--) {
			*tmpDst++ = *tmpSrc++;
		}
	}
	else {
		tmpSrc = tmpSrc + count - 1;
		tmpDst = tmpDst + count - 1;
		while (count--) {
			*tmpDst-- = *tmpSrc--;
		}
	}
	return dst;
}
//memcpy没有考虑覆盖的问题，效率更高
void* memcpyByJing(void* dst, void* src, size_t count) {
	assert(dst != nullptr && nullptr != src);
	char* tmpDst = static_cast<char*>(dst);
	char* tmpSrc = static_cast<char*>(src);
	while (count--) {
		*tmpDst++ = *tmpSrc++;
	}
	return dst;
}

void* memsetByJing(void* dst, int val, size_t count) {
	assert(dst != nullptr);
	void* ret = dst;
	while (count--) {
		*(char*)dst = (char)val;
		dst = (char*)dst+1;
	}
	return ret;
}

int main(){
	
	return 0;
}