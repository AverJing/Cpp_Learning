#include "ex14_32.h"

StrBlobPtr & StrBlobPtr_pointer::operator*()
{
	if (pointer)
		return *pointer;
	else
		return;
}

StrBlobPtr * StrBlobPtr_pointer::operator->()
{
	return & this->operator*();
}
