#pragma once
#ifndef EX16_4_FIND_H
#define EX16_4_FIND_H

template<typename Iter, typename T> Iter find(Iter begin, Iter end,const T& value) {
	for (; begin != end; ++begin)
		if (*begin == value)
			return begin;
	return end;
}

#endif // !EX16_4_FIND_H
