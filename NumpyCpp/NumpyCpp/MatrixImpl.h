/*
*
*
*@author: Aver Jing
*@description：N维数组实现的辅助函数
*@date：
*
*
*/
#pragma once
#include <initializer_list>
#include <vector>
#include <array>

namespace Matrix_impl{

	//检查所有行是否都包含相同数目的元素
	template<typename List>
	bool check_non_jagged(const List& list) {
		auto i = list.begin();
		for (auto j = i + 1; j != list.end(); ++j)
			if (i->size() != j->size())
				return false;
		return true;
	}

	//如何实现非模板参数的模板函数的递归？
	//看测试部分代码
	/*template<typename List, typename Iter>
	void add_extents(size_t N, const List& list, Iter iter) {
		if (N == 1) *iter++ = list.size();
		else if (N > 1) {
			assert(check_non_jagged(list));
			*iter = list.size();
			add_extents(N-1, *(list.begin()), ++iter);
		}
	}*/

	template<size_t N, typename List, typename Iter>
	struct add_extents {
		void operator()(const List& list, Iter iter) {
			assert(check_non_jagged(list));
			*iter = list.size();
			add_extents<N-1, List::value_type, Iter>()(*(list.begin()), ++iter);
		}
	};
	template<typename List, typename Iter>
	struct add_extents<1, List, Iter> {
		void operator()(const List& list, Iter iter) {
			*iter++ = list.size();
		}
	};

	//根据Matrix_initializer添加维度信息
	//Init:Matrix_initializer   Ext:Matrix_slice.extents
	template<size_t N, typename List, typename Ext>
	inline void derive_extents(const List& list, Ext& ext) {
		add_extents<N, List, Ext::iterator>()(list, ext.begin());
	}

	template<typename T, typename Vec>
	void add_list(const T* first,
		const T* end, Vec& vec) {
		vec.insert(vec.end(), first, end);
	}

	template<typename T, typename Vec>//可以直接传指针
	void add_list(const std::initializer_list<T>* first,
		const std::initializer_list<T>* end, Vec& vec) {
		for (; first != end; ++first) {
			add_list(first->begin(), first->end(), vec);
		}
	}

	template<typename T, typename Vec>
	void insert_flat(const std::initializer_list<T>& list, Vec& vec) {
		add_list(list.begin(), list.end(), vec);
	}

	//template<size_t N, typename T, typename M>//M:Matrix_slice
	//std::ostream& pretty_print(std::ostream& os, size_t pos, M& m, T& data) {
	//	if (pos == N) {
	//		std::cout << '{';
	//		for (int i = 0; i < m.extents[N - 1]; ++i) {
	//			std::cout << data[m.start + i];
	//			std::cout << (i == m.extents[N - 1] - 1 ? "" : ", ");
	//		}
	//		m.start += m.extents[N - 1];
	//		std::cout << '}';
	//		return os;
	//	}
	//	else {
	//		std::cout << '{' << std::endl;
	//		for (int i = 0; i < m.extents[pos - 1]; ++i) {
	//			pretty_print<N>(os, pos + 1, m, data);
	//			std::cout << (i == m.extents[pos - 1] - 1 ? "" : ", ") << std::endl;
	//		}
	//		std::cout << '}' << std::endl;
	//	}
	//}

	template<size_t N, typename T, typename M>//M:Matrix_slice
	std::ostream& pretty_print(std::ostream& os, size_t pos, M& m, T& data, int index = 0) {
		if (pos == N) {
			std::cout << '{';
			for (int i = 0; i < m.extents[N - 1]; i+=m.strides[N-1], index += m.strides[N - 1]) {
				std::cout << data[index];
				std::cout << (i == m.extents[N - 1] - 1 ? "" : ", ");
			}
			std::cout << '}';
			return os;
		}
		else {
			std::cout << '{' << std::endl;
			for (int i = 0; i < m.extents[pos - 1]; ++i, index+= m.strides[pos - 1]) {
				pretty_print<N>(os, pos + 1, m, data, index);
				std::cout << (i == m.extents[pos - 1] - 1 ? "" : ", ") << std::endl;
			}
			std::cout << '}' << std::endl;
		}
	}

	//for Matrix_slice
	template<size_t N, typename T, typename M>//M:Matrix_slice
	std::ostream& pretty_print(std::ostream& os, size_t pos, M& m, T* data, int index = 0) {
		if (pos == N) {
			std::cout << '{';
			for (int i = 0; i < m.extents[N - 1]; i += m.strides[N - 1], index += m.strides[N - 1]) {
				std::cout << *(data+index);
				std::cout << (i == m.extents[N - 1] - 1 ? "" : ", ");
			}
			std::cout << '}';
			return os;
		}
		else {
			std::cout << '{' << std::endl;
			for (int i = 0; i < m.extents[pos - 1]; ++i, index += m.strides[pos - 1]) {
				pretty_print<N>(os, pos + 1, m, data, index);
				std::cout << (i == m.extents[pos - 1] - 1 ? "" : ", ") << std::endl;
			}
			std::cout << '}' << std::endl;
		}
	}

	template<size_t N, typename T, typename M> //M:Matrix_slice
	void update_ref(size_t pos, M& m, T* data, const T* elems, int index = 0) {
		for (int i = 0; i < m.extents[N - 1]; i += m.strides[N - 1], index += m.strides[N - 1]) {
			*(data + index) = *(elems + i);
		}
		return;
	}

	//更新Matrix_ref中的元素，可以考虑将输出和更新整合在一起。
	template<size_t N, typename T, typename M, typename D> //M:Matrix_slice
	void update_ref(size_t pos, M& m, T* data, const D* elems, int index = 0) {
		if (pos == N) {
			update_ref<N>(pos, m, data, elems, index);
		}
		else {
			for (int i = 0; i < m.extents[pos - 1]; ++i, index += m.strides[pos - 1], ++elems) {
				update_ref<N>(pos + 1, m, data, elems->begin(), index);
			}
		}
	}

	template<size_t N, typename M1, typename M2>
	void slice_dim(size_t n, M1& m1, M2& m2) {
		
	}

	template<size_t N, typename M, typename T>
	size_t do_slice_dim(const M& os, M& ns, const T& s) {
		ns.strides[N] = os.strides[N] * s.stride;
		ns.extents[N] = s.length;
		return os.strides[N] * s.start;
	}

	template<size_t N, typename M>
	size_t do_slice_dim(const M& os, M& ns, const int& s) {
		ns.strides[N] = os.strides[N];
		ns.extents[N] = 1;
		return os.strides[N] * s;
	}

	template<size_t N, typename M>
	size_t do_slice(const M& os, const M& ns) {
		return 0;
	}

	template<size_t N, typename M, typename T, typename... Args>
	size_t do_slice(const M& os, M& ns, const T& s, const Args&... args) {
		size_t m = do_slice_dim<N - sizeof...(Args) - 1>(os, ns, s);
		size_t n = do_slice<N>(os, ns, args...);
		return m + n;
	}
}