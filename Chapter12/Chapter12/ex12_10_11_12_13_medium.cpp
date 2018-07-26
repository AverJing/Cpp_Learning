/*
*
*@author£ºAver Jing
*@description£ºExplain whether the following call to the process function
*defined on page 464 is correct. If not, how would you correct the call?
*shared_ptr<int> p(new int(42));
*process(shared_ptr<int>(p));
*@date£ºJuly 25, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

void process(std::shared_ptr<int> ptr)
{
	std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

void ex12_10(){
	std::shared_ptr<int> p(new int(42));
	process(std::shared_ptr<int>(p));

	/**
	* codes below shows how the reference count change.
	*/
	std::cout << p.use_count() << "\n";
	auto q = p;
	std::cout << p.use_count() << "\n";
	std::cout << "the int p now points to is:" << *p << "\n";
}

//What would happen if we called process as follows?
void ex12_11() {
	std::shared_ptr<int> p(new int(42));

	/**
	* @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr
	* and copy it
	*          to the parameter.However it is not a copy of p. As a result, at
	* end of this
	*          main function p will free the memory that has been freed inside
	* process ().
	*          That's why "double freed or corruption" was generated.
	*/
	process(std::shared_ptr<int>(p.get()));
}

//! Using the declarations of p and sp explain each of the following calls to
//! process. If the call is legal, explain what it does. If the call is illegal,
//! explain why:
//See comments below.
void ex12_12() {
	auto p = new int();
	auto sp = std::make_shared<int>();

	/** @brief
	*  legal. Just copy sp which is a shared_ptr to process().
	*/
	// process(sp);

	/** @brief
	*  illegale.plain pointer can not convert to smart pointer implicitly.
	*/
	// process(new int());

	/** @brief
	*  illegale.plain pointer can not convert to smart pointer implicitly.
	*/
	// process(p);

	/** @brief
	*  Legal. But it's a bad practice to do so.
	*  Because using smart pointer together with raw pointer could potentially
	* cause problems.
	*  For example double free as shown in #145.
	*
	*  Check issue #145 for detail, thx @endyul for reporting
	*/
	// process(std::shared_ptr<int>(p));
}

//What happens if we execute the following code?
void ex12_13() {
	//generate a runtime error : double free
	auto sp = std::make_shared<int>();
	auto p = sp.get();
	delete p;
}

int main()
{

}