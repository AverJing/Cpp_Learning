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
#include <type_traits>
#include <bitset>

template<typename T>
struct add_reference {
	typedef T& type;
};

template<typename T>
struct add_reference<T&> {
	typedef T& type;
};

template<typename T>
struct add_const_reference {
	using type = const T&;  //add lower const
};

//注意如果没有特化版本，当参数是左值引用时，type没有const
template<typename T>
struct add_const_reference<T&> {
	using type = const T&;
};

template<typename... Values> 
class tuple;

//base class: zero-length tuple
template<>
class tuple<> {};

template<typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
	using inherited = tuple<Tail...> ;
public:
	tuple() {}
	//tuple(Head v, Tail... vtail) :m_head(v), inherited(vtail...) {}

	tuple(typename add_const_reference<Head>::type v,
		typename add_const_reference<Tail>::type... vtail) :m_head(v), inherited(vtail...) {}
	
	typename add_reference<Head>::type head() { return m_head; }
	typename add_const_reference<Head>::type head() const{ return m_head; }
	typename add_reference<inherited>::type tail() { return *this; }
	typename add_const_reference<inherited>::type tail() const{ return *this; }
protected:
	Head m_head;
};

//实现tuple某个元素的类型，不借助位置返回类型
template<int I, typename... Tail>
struct tuple_element;

template<int I, typename Head, typename... Tail>
struct tuple_element<I, tuple<Head, Tail...>> {
	using type = typename tuple_element<I - 1, tuple<Tail...>>::type;
};

template<typename Head, typename... Tail>
struct tuple_element<0, tuple<Head, Tail...>> {
	using type = Head;
};

//very good
template<typename T, typename U>
struct is_same {
	static const bool value = false;
};

template<typename T>
struct is_same<T, T> {
	static const bool value = true;
};

//fantasy
int check_tuple_element_0[
	is_same<tuple_element<0, tuple<int&, float, double>>::type,
	int&>::value ? 1 : -1];

template<int I, typename Tuple> class get_impl;

template<int I, typename Head, typename... Tail>
class get_impl<I, tuple<Head, Tail...>>{
	//using Element = typename tuple_element<I - 1, tuple<Tail...>>::type;
	//using RJ = typename add_reference<Element>::type;
	//using PJ = typename add_const_reference<Element>::type;
	using Next = get_impl<I - 1, tuple<Tail...>>;
public:
	//version 1.0   
	
	static auto get(tuple<Head, Tail...>& t)
		->decltype(Next::get(t.tail())) {
		return Next::get(t.tail());
	}
	static auto get(const tuple<Head, Tail...>& t)
		->decltype(Next::get(t.tail())) {
		return Next::get(t.tail());
	}

	//version 2.0
	/*
	static RJ get(tuple<Head, Tail...>& t){
		return Next::get(t.tail());
	}
	static PJ get(const tuple<Head, Tail...>& t){
		return Next::get(t.tail());
	}*/
};

template<typename Head, typename... Tail>
class get_impl<0, tuple<Head, Tail...>> {
	//using Element = tuple<>
	//using RJ = add_reference<>::type;
	//using PJ = add_const_reference<>::type;
public:
	static auto get(tuple<Head, Tail...>& t)->decltype(t.head()) {
		return t.head();
	}
	static auto get(const tuple<Head, Tail...>& t)->decltype(t.head()) {
		return t.head();
	}
};

template<int I, typename... Tail>
auto get(tuple<Tail...>& t) -> decltype(get_impl<I, tuple<Tail...>>::get(t)){
	return get_impl<I, tuple<Tail...>>::get(t);
}

// Relational operators
inline bool operator==(const tuple<>&, const tuple<>&) { return true; }

template<typename T, typename... TTail, typename U, typename... UTail>
bool operator==(const tuple<T, TTail...>& t, const tuple<U, UTail...>& u) {
	return t.head() == u.head() && t.tail() == u.tail();
}

template<typename... TValues, typename... UValues>
bool operator!=(const tuple<TValues...>& t, const tuple<UValues...>& u) {
	return !(t == u);
}

inline bool operator<(const tuple<>&, const tuple<>&) { return false; }

template<typename T, typename... TTail, typename U, typename... UTail>
bool operator<(const tuple<T, TTail...>& t, const tuple<U, UTail...>& u) {
	return (t.head() < u.head() || (!(t.head() < u.head()) && t.tail() < u.tail()));
}

template<typename... TValues, typename... UValues>
bool operator>(const tuple<TValues...>& t, const tuple<UValues...>& u) {
	return u < t;
}

template<typename... TValues, typename... UValues>
bool operator<=(const tuple<TValues...>& t, const tuple<UValues...>& u) {
	return !(u < t);
}

template<typename... TValues, typename... UValues>
bool operator>=(const tuple<TValues...>& t, const tuple<UValues...>& u) {
	return !(t < u);
}

void test_relational_operators(tuple<int*, float*, double*> t3) {
	(void)(t3 == t3);
	(void)(t3 != t3);
	(void)(t3 < t3);
	(void)(t3 <= t3);
	(void)(t3 >= t3);
	(void)(t3 > t3);
};

int main(){
	tuple<int, std::bitset<15>, float> t(50, 521, 5.21);
	//std::cout << t.head() << ' ' << t.tail().head() << ' ' << t.tail().tail().head() << std::endl ;

	std::cout << get<2>(t);

	test_relational_operators(tuple<int*, float*, double*>(nullptr, nullptr, nullptr));
}	