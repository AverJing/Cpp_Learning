#pragma once
#ifndef EX16_7_CONSTEXPR_H
#define EX16_7_CONSTEXPR_H

template <typename T, unsigned N>
constexpr unsigned SizeOfArray(const T(&arr)[N])
{
	return N;
}

#endif // !EX16_7_CONSTEXPR_H
