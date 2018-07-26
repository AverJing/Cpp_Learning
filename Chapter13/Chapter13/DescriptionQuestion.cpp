/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

//ex13.1 What is a copy constructor? When is it used?
/*
A copy constructor is a constructor which first parameter is a reference to the class type and any additional parameters have default values.

When copy initialization happens and that copy initialization requires either the copy constructor or the move constructor.

	Define variables using an =
	Pass an object as an argument to a parameter of non-reference type
	Return an object from a function that has a non-reference return type
	Brace initialize the elements in an array or the members of an aggregate class
	Some class types also use copy initialization for the objects they allocate.
*/

//ex13.2 Explain why the following declaration is illegal:
	//	Sales_data::Sales_data(Sales_data rhs);
/*
If declaration like that, the call would never succeed to call the copy constructor, 
Sales_data rhs is an argument to a parameter, thus, 
we'd need to use the copy constructor to copy the argument, but to copy the argument, 
we'd need to call the copy constructor, and so on indefinitely.
*/

//ex13.3 What happens when we copy a StrBlob? What about StrBlobPtrs?
/*
	// added a public member function to StrBlob and StrBlobPrts
	long count() {
	return data.use_count(); // and wptr.use_count();
	}

	// test codes in main()
	StrBlob str({"hello", "world"});
	std::cout << "before: " << str.count() << std::endl; // 1
	StrBlob str_cp(str);
	std::cout << "after: " << str.count() << std::endl;  // 2

	ConstStrBlobPtr p(str);
	std::cout << "before: " << p.count() << std::endl; // 2
	ConstStrBlobPtr p_cp(p);
	std::cout << "after: " << p.count() << std::endl; // 2
*/
/*
when we copy a StrBlob, the shared_ptr member's use_count add one.
when we copy a StrBlobPrts, the weak_ptr member's use_count isn't changed.(cause the count belongs to shared_ptr)
*/

//ex13.4 Assuming Point is a class type with a public copy constructor, 
//identify each use of the copy constructor in this program fragment:
/*
	Point global;
	Point foo_bar(Point arg) // 1
	{
		Point local = arg, *heap = new Point(global); // 2, 3
		*heap = local;
		Point pa[ 4 ] = { local, *heap }; // 4, 5
		return *heap; // 6
	}
*/

//13.6 What is a copy-assignment operator? When is this operator used? 
//What does the synthesized copy-assignment operator do? When is it synthesized?
/*
The copy-assignment operator is function named operator=.

This operator is used when assignment occurred.

The synthesized copy-assignment operator assigns each non-static member of the right-hand object to 
corresponding member of the left-hand object using the copy-assignment operator 
for the type of that member.

It is synthesized when the class does not define its own.
*/

//ex13.7 What happens when we assign one StrBlob to another? What about StrBlobPtrs?
/*
In both cases, shallow copy will happen. All pointers point to the same address. The use_count changed the same as 13.3.
*/

//13.9 What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?
/*
The destructor is a member function with the name of the class prefixed by a tilde(~).

As with the copy constructor and the copy-assignment operator, for some classes, 
the synthesized destructor is defined to disallow objects of the type from being destroyed. 
Otherwise, the synthesized destructor has an empty function body.

The compiler defines a synthesized destructor for any class that does not define its own destructor.
*/

//13.10 What happens when a StrBlob object is destroyed? What about a StrBlobPtr?
/*
When a StrBlob object destroyed, the use_count of the dynamic object will decrement. 
It will be freed if no shared_ptr to that dynamic object.

When a StrBlobPter object is destroyed the object dynamically allocated will not be freed.
*/

//ex13.12 How many destructor calls occur in the following code fragment?
/*
	bool fcn(const Sales_data *trans, Sales_data accum)
	{
		Sales_data item1(*trans), item2(accum);
		return item1.isbn() != item2.isbn();
	}   //3 times. There are accum, item1 and item2.
*/


//ex13.14 Assume that numbered is a class with a default constructor that generates a unique serial number for each object, 
//which is stored in a data member named mysn. 
//Assuming numbered uses the synthesized copy-control members and 
//given the following function:
//	void f (numbered s) { cout << s.mysn << endl; }
//what output does the following code produce?
//numbered a, b = a, c = b;
//f(a); f(b); f(c);
/*
Three identical numbers.
*/

//ex13.15 Assume numbered has a copy constructor that generates a new serial number. 
//Does that change the output of the calls in the previous Exercise? 
//If so, why? What output gets generated?
/*
Yes, the output will be changed. 
cause we don't use the synthesized copy-control members rather than own defined.
The output will be three different numbers.
*/

//ex13.16 What if the parameter in f were const numbered&? 
//Does that change the output? If so, why? What output gets generated?
/*
Yes, the output will be changed. cause the function f haven't any copy operators.
Thus, the output are the same when pass the each object to f.
*/

//ex13.20 Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes from 12.3 (p. 484).
/*
The member (smart pointer and container) will be copied.
*/

//ex13.21 Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members? 
//If so, why? If not, why not? 
//Implement whichever copy-control operations you think these classes require.
/*
As synthesized version meet all requirements for this case, no custom version control members need to define. Check #304 for detail.
https://github.com/Mooophy/Cpp-Primer/issues/304#issuecomment-124081395
*/

//ex13.23 Compare the copy-control members that you wrote for the solutions to the previous section¡¯s exercises to the code presented here. 
//Be sure you understand the differences, if any, between your code and ours.
//check HasPtr.h

//ex13.24 What would happen if the version of HasPtr in this section didn¡¯t define a destructor?
//What if HasPtr didn¡¯t define the copy constructor?
/*
If HasPtr didn't define a destructor, memory leak will happened. 

If HasPtr didn't define the copy constructor, when assignment happened, 
just points copied, the string witch ps points haven't been copied.
*/

//ex13.25 Assume we want to define a version of StrBlob that acts like a value. 
//Also assume that we want to continue to use a shared_ptr so that our 
//StrBlobPtr class can still use a weak_ptr to the vector. 
//Your revised class will need a copy constructor and copy-assignment operator 
//but will not need a destructor. Explain what the copy constructor and copy-assignment 
//operators must do. Explain why the class does not need a destructor.
/*
Copy constructor and copy-assignment operator should dynamically allocate 
memory for its own , rather than share the object with the right hand operand.

StrBlob is using smart pointers which can be managed with synthesized destructor, 
If an object of StrBlob is out of scope, the destructor for std::shared_ptr 
will be called automatically to free the memory dynamically allocated 
when the use_count goes to 0.
*/

//ex13.29 Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.
/*
swap(lhs.ps, rhs.ps); feed the version : swap(std::string*, std::string*) and swap(lhs.i, rhs.i); 
feed the version : swap(int, int). Both them can't call swap(HasPtr&, HasPtr&). Thus, the calls don't cause a recursion loop.
*/

//ex13.32 Would the pointer-like version of HasPtr benefit from defining a swap function? 
//If so, what is the benefit? If not, why not?
/*
@Mooophy:

Essentially, the specific avoiding memory allocation is the reason 
why it improve performance. As for the pointer-like version, 
no dynamic memory allocation anyway. 
Thus, a specific version for it will not improve the performance.
*/

//ex13.33 Why is the parameter to the save and remove members of Message a Folder&? 
//Why didn¡¯t we define that parameter as Folder? Or const Folder&?
/*
Because these operations must also update the given Folder. 
Updating a Folder is a job that the Folder class controls through 
its addMsg and remMsg members, 
which will add or remove a pointer to a given Message, respectively.
*/