/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

//12.1  How many elements do b1 and b2 have at the end of this code ?
/*
StrBlob b1;
{
 StrBlob b2 = {"a", "an", "the"}; b1 = b2; b2.push_back("about");
}
*/
/*
b2 is destroyed, but the elements in b2 must not be destroyed.

so b1 and b2 both have 4 elements.
*/

//12.3 Does this class need const versions of push_back and pop_back? 
//If so, add them. If not, why aren¡¯t they needed?
/*
You can certainly do this if you want to, but there doesn't seem to be any logical reason. 
The compiler doesn't complain because this doesn't modify data (which is a pointer) 
but rather the thing data points to, which is perfectly legal to do with a const pointer.
by David Schwartz.
*/

//12.4 In our check function we didn¡¯t check whether i was greater than zero. 
//Why is it okay to omit that check?
/*
Because the type of i is std::vector<std::string>::size_type 
which is an unsigned.When any argument less than 0 is passed in, 
it will convert to a number greater than 0.
In short std::vector<std::string>::size_type will ensure it is a positive number or 0.
*/

//12.5 We did not make the constructor that takes an initializer_list explicit (7.5.4, p. 296).
//Discuss the pros and cons of this design choice.
/*
keyword explicit prevents automatic conversion from an initializer_list to StrBlob. 
This design choice would easy to use but hard to debug.

Pros
The compiler will not use this constructor in an automatic conversion.
We can realize clearly which class we have used.
Cons
We always uses the constructor to construct a temporary StrBlob object.
cannot use the copy form of initialization with an explicit constructor. not easy to use.

*/

//12.8 Explain what if anything is wrong with the following function.
/*
	bool b() { int* p = new int;
	// ...
	return p;
	}
*/
/*
The p will convert to a bool, which means that the dynamic memory allocated has no chance to be freed. 
As a result, memory leakage will occur.
*/

//12.9 Explain what happens in the following code:
/*
	int *q = new int(42), *r = new int(100);
	r = q;
	auto q2 = make_shared<int>(42), r2 =
	make_shared<int>(100);
	r2 = q2;
*/
/*
Memory leakage happens. Because after r = q was executed, no pointer points to the int r had pointed to. 
It implies that no chance to free the memory for it.
*/

//12.16 Compilers don¡¯t always give easy-to-understand error
//messages if we attempt to copy or assign a unique_ptr.Write a program
//that contains these errors to see how your compiler diagnoses them.
/*
	unique_ptr<string> p1(new string("pezy"));
	// unique_ptr<string> p2(p1); // copy
	//                      ^
	// Error: Call to implicitly-deleted copy constructor of
	// 'unique_ptr<string>'
	//
	// unique_ptr<string> p3 = p1; // assign
	//                      ^
	// Error: Call to implicitly-deleted copy constructor of
	// 'unique_ptr<string>'
	std::cout << *p1 << std::endl;
	p1.reset(nullptr);
*/

//12.21 We could have written StrBlobPtr¡¯s deref member as follows:
//	std::string& deref() const
//	{ return (*check(curr, "dereference past end"))[curr]; }
//Which version do you think is better and why?

//the origin version is better. cause it's more readability and easier to debug.