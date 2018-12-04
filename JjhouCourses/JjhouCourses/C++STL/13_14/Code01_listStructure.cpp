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

/// Common part of a node in the %list.
struct _List_node_base
{
	_List_node_base* _M_next;
	_List_node_base* _M_prev;
	/*
	static void
		swap(_List_node_base& __x, _List_node_base& __y);

	void
		_M_transfer(_List_node_base* const __first,
			_List_node_base* const __last);

	void
		_M_reverse();
	void
		_M_hook(_List_node_base* const __position);

	void
		_M_unhook();*/
};

/// The %list node header.
struct _List_node_header : public _List_node_base
{
#if _GLIBCXX_USE_CXX11_ABI
	std::size_t _M_size;
#endif

	_List_node_header()
	{
		_M_init();
	}

#if __cplusplus >= 201103L
	_List_node_header(_List_node_header&& __x) noexcept
		: _List_node_base{ __x._M_next, __x._M_prev }
# if _GLIBCXX_USE_CXX11_ABI
		, _M_size(__x._M_size)
# endif
	{
		if (__x._M_base()->_M_next == __x._M_base())
			this->_M_next = this->_M_prev = this;
		else
		{
			this->_M_next->_M_prev = this->_M_prev->_M_next = this->_M_base();
			__x._M_init();
		}
	}

	void
		_M_move_nodes(_List_node_header&& __x)
	{
		_List_node_base* const __xnode = __x._M_base();
		if (__xnode->_M_next == __xnode)
			_M_init();
		else
		{
			_List_node_base* const __node = this->_M_base();
			__node->_M_next = __xnode->_M_next;
			__node->_M_prev = __xnode->_M_prev;
			__node->_M_next->_M_prev = __node->_M_prev->_M_next = __node;
# if _GLIBCXX_USE_CXX11_ABI
			_M_size = __x._M_size;
# endif
			__x._M_init();
		}
	}
#endif

	void
		_M_init()
	{
		this->_M_next = this->_M_prev = this;
#if _GLIBCXX_USE_CXX11_ABI
		this->_M_size = 0;
#endif
	}

private:
	_List_node_base* _M_base() { return this; }
};

//the difference between header and actual node in list

/// An actual node in the %list.
template<typename _Tp>
struct _List_node : public _List_node_base
{
#if __cplusplus >= 201103L
	__gnu_cxx::__aligned_membuf<_Tp> _M_storage;
	_Tp*       _M_valptr() { return _M_storage._M_ptr(); }
	_Tp const* _M_valptr() const { return _M_storage._M_ptr(); }
#else
	_Tp _M_data;
	_Tp*       _M_valptr() { return std::__addressof(_M_data); }
	_Tp const* _M_valptr() const { return std::__addressof(_M_data); }
#endif
};

/**
 *  @brief A list::iterator.
 *
 *  All the functions are op overloads.
*/
template<typename _Tp>
struct _List_iterator
{
	typedef _List_iterator<_Tp>		_Self;
	typedef _List_node<_Tp>			_Node;

	//这5个成员是迭代器必须的
	typedef ptrdiff_t				difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef _Tp				value_type;
	typedef _Tp*				pointer;
	typedef _Tp&				reference;

	_List_iterator() _GLIBCXX_NOEXCEPT
		: _M_node() { }

	//gcc中_List_node_base放在detail命名空间下的
	explicit
		_List_iterator(_List_node_base* __x) _GLIBCXX_NOEXCEPT
		: _M_node(__x) { }

	_Self
		_M_const_cast() const _GLIBCXX_NOEXCEPT
	{
		return *this;
	}

	// Must downcast from _List_node_base to _List_node to get to value.
	reference
		operator*() const _GLIBCXX_NOEXCEPT
	{
		return *static_cast<_Node*>(_M_node)->_M_valptr();
	}

	pointer
		operator->() const _GLIBCXX_NOEXCEPT
	{
		return static_cast<_Node*>(_M_node)->_M_valptr();
	}

	_Self&
		operator++() _GLIBCXX_NOEXCEPT
	{
		_M_node = _M_node->_M_next;
		return *this;
	}

	_Self
		operator++(int) _GLIBCXX_NOEXCEPT
	{
		_Self __tmp = *this;
		_M_node = _M_node->_M_next;
		return __tmp;
	}

	_Self&
		operator--() _GLIBCXX_NOEXCEPT
	{
		_M_node = _M_node->_M_prev;
		return *this;
	}

	_Self
		operator--(int) _GLIBCXX_NOEXCEPT
	{
		_Self __tmp = *this;
		_M_node = _M_node->_M_prev;
		return __tmp;
	}

	friend bool
		operator==(const _Self& __x, const _Self& __y) _GLIBCXX_NOEXCEPT
	{
		return __x._M_node == __y._M_node;
	}

	friend bool
		operator!=(const _Self& __x, const _Self& __y) _GLIBCXX_NOEXCEPT
	{
		return __x._M_node != __y._M_node;
	}

	// The only member points to the %list element.
	_List_node_base* _M_node;
};

/**
   *  @brief A list::const_iterator.
   *
   *  All the functions are op overloads.
  */
template<typename _Tp>
struct _List_const_iterator
{
	typedef _List_const_iterator<_Tp>		_Self;
	typedef const _List_node<_Tp>		_Node;
	typedef _List_iterator<_Tp>		iterator;

	typedef ptrdiff_t				difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef _Tp				value_type;
	typedef const _Tp*			pointer;
	typedef const _Tp&			reference;

	_List_const_iterator() _GLIBCXX_NOEXCEPT
		: _M_node() { }

	explicit
		_List_const_iterator(const __detail::_List_node_base* __x)
		_GLIBCXX_NOEXCEPT
		: _M_node(__x) { }

	_List_const_iterator(const iterator& __x) _GLIBCXX_NOEXCEPT
		: _M_node(__x._M_node) { }

	iterator
		_M_const_cast() const _GLIBCXX_NOEXCEPT
	{
		return iterator(const_cast<__detail::_List_node_base*>(_M_node));
	}

	// Must downcast from List_node_base to _List_node to get to value.
	reference
		operator*() const _GLIBCXX_NOEXCEPT
	{
		return *static_cast<_Node*>(_M_node)->_M_valptr();
	}

	pointer
		operator->() const _GLIBCXX_NOEXCEPT
	{
		return static_cast<_Node*>(_M_node)->_M_valptr();
	}

	_Self&
		operator++() _GLIBCXX_NOEXCEPT
	{
		_M_node = _M_node->_M_next;
		return *this;
	}

	_Self
		operator++(int) _GLIBCXX_NOEXCEPT
	{
		_Self __tmp = *this;
		_M_node = _M_node->_M_next;
		return __tmp;
	}

	_Self&
		operator--() _GLIBCXX_NOEXCEPT
	{
		_M_node = _M_node->_M_prev;
		return *this;
	}

	_Self
		operator--(int) _GLIBCXX_NOEXCEPT
	{
		_Self __tmp = *this;
		_M_node = _M_node->_M_prev;
		return __tmp;
	}

	friend bool
		operator==(const _Self& __x, const _Self& __y) _GLIBCXX_NOEXCEPT
	{
		return __x._M_node == __y._M_node;
	}

	friend bool
		operator!=(const _Self& __x, const _Self& __y) _GLIBCXX_NOEXCEPT
	{
		return __x._M_node != __y._M_node;
	}

	// The only member points to the %list element.
	const __detail::_List_node_base* _M_node;
};

int main(){
	
}	