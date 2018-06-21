#pragma once
#ifndef EX14_32_H
#define EX14_32_H

#include "ex14_16_StrBlob.h"

class StrBlobPtr_pointer {
public:
	StrBlobPtr_pointer() = default;
	StrBlobPtr_pointer(StrBlobPtr* p) :pointer(p) {}

	StrBlobPtr& operator*();
	StrBlobPtr* operator->();
private:
	StrBlobPtr * pointer = nullptr;
};

#endif // !EX14_31_H
