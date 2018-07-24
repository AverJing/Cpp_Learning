/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/


//11.1  Describe the differences between a map and a vector.
/*
A map is a collection of key-value pairs. we can get a value lookup by key efficiently.
A vector is a collection of objects, and every object has an associated index, which gives access to that object.
*/

//11.2 Give an example of when each of list, vector, deque, map, and set might be most useful.
/*
list : a to-do list. always need insert or delete the elements anywhere.
vector : save some important associated data, always need query elements by index.
deque : message handle. FIFO.
map : dictionary.
set : bad_checks.
*/

//11.5 Explain the difference between a map and a set. When might you use one or the other?
/*
set : the element type is the key type.
map : we should use a key-value pair, such as {key, value} to indicate that the items together from one element in the map.

I use set when i just need to store the key, In other hand, I¡¡would like use map when i need to store a key-value pair.
*/

//11.6 Explain the difference between a set and a list. When might you use one or the other?
/*
set is unique and order, but list is neither. using which one depend on whether the elements are unique and order to store.
*/

//11.15 What are the mapped_type, key_type, and value_type of a map from int to vector<int>?
/*
mapped_type : vector<int>
key_type : int
value_type : std::pair<const int, vector<int>>
*/

//11.16 Using a map iterator write an expression that assigns a value to an element.
/*
std::map<int, std::string> map;
map[25] = "Alan";
std::map<int, std::string>::iterator it = map.begin();
it->second = "Wang";
*/

//11.17 Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. 
//Indicate whether each call is legal:
/*
copy(v.begin(), v.end(), inserter(c, c.end())); // legal
copy(v.begin(), v.end(), back_inserter(c)); // illegal, no `push_back` in `set`.
copy(c.begin(), c.end(), inserter(v, v.end())); // legal.
copy(c.begin(), c.end(), back_inserter(v)); // legal.
*/

//11.18 Write the type of map_it from the loop on page 430 without using auto or decltype.
/*
	std::map<std::string, size_t> word_count;

	//! the orignal codes:
	// auto map_it = word_count.cbegin();

	std::map<std::string, size_t>::const_iterator map_it = word_count.cbegin();
	//! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//! the type ex11.18 required.

	// compare the current iterator to the off-the-end iterator
	while (map_it != word_count.cend()) {
	// dereference the iterator to print the element key--value pairs
	std::cout << map_it->first << " occurs " << map_it->second << " times"
	<< std::endl;
	++map_it; // increment the iterator to denote the next element
	}
*/

//11.19 Define a variable that you initialize by calling begin() on the multiset named bookstore from 11.2.2 (p. 425). 
//Write the variable¡¯s type without using auto or decltype.
/*
	using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
	std::multiset<Sales_data, compareType> bookstore(copareIsbn);
	std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
*/

//11.21 Assuming word_count is a map from string to size_t and word is a string, 
//explain the following loop:
//	while (cin >> word)
//		++word_count.insert({ word, 0 }).first->second;
/*
		++ (word_count.insert({word, 0}).first->second)
*/

//11.22 Given a map<string, vector<int>>, write the types
//used as an argument and as the return value for the version of insert that
//inserts one element.
/*
std::pair<std::string, std::vector<int>>    // argument
std::pair<std::map<std::string, std::vector<int>>::iterator, bool> // return
*/

//11.24 What does the following program do?
//	map<int, int> m;	 m[0] = 1;
/*
	add a key-value pair {0,1} into the map
*/

//11.25 Contrast the following program with the one in the previous exercise
//	vector<int> v;	v[0] = 1;
/*
Since the vector v is empty, the subsript operator [0] can not access v[0].
Thus, the statement v[0] = 1; is meaningless.
*/

//11.26 What type can be used to subscript a map? What type does the subscript
//! operator return? Give a concrete example¡ªthat is, define a map and then
//! write the types that can be used to subscript the map and the type that
//! would be returned from the subscript operator.
/*

//! ex11.26
std::map<int, std::string> map = {{1, "ss"}, {2, "sz"}};

std::map<int, std::string>::key_type type_to_subscript = 1;
//! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//! that is, int.

std::map<int, std::string>::mapped_type type_to_return =
map[type_to_subscript];
//! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//! that is, std::string

*/

//11.27 What kinds of problems would you use count to solve?
//When might you use find instead ?
/*
I would use count to deal with multimap or multi multiset.
As for the associative container that have unique key, I would use find
instead of count.
*/

//11.28 Define and initialize a variable to hold the result of calling
//find on a map from string to vector of int.
/*
	std::map<std::string, std::vector<int>> m;
	std::map<std::string, std::vectorr<int>>::iterator result = m.find(key_word);
*/

//11.29 What do upper_bound, lower_bound, and equal_range return
// when you pass them a key that is not in the container?
//  If the element is not in the multimap, then lower_bound
//  and upper_bound will return equal iterators; both will
//  refer to the point at which the key can be inserted without
//  disrupting the order.
//  If no matching element is found, then both the first and
//  second iterators refer to the position where this key can
//  be inserted.

//11.30 Explain the meaning of the operand pos.first->second
//used in the output expression of the final program in this section
/*
  pos                     a pair
  pos.first               the iterator refering to the first element with the
  matching key
  pos.first->second       the value part of the key-value of the first element
  with the matching key
*/