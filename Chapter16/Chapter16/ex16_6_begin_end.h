#pragma once
#ifndef EX16_6_BEGIN_END_H
#define EX16_6_BEGIN_END_H

template<typename T, unsigned N>
T* begin(const T(&a)[N]) {
	return a;
}

template<typename T, unsigned N>
T* end(const T(&a)[N]) {
	return a+N;
}

#endif // !EX16_6_BEGIN_END_H
