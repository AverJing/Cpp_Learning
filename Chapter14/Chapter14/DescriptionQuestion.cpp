/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

//ex14.1 In what ways does an overloaded operator differ from a built-in operator? 
//In what ways are overloaded operators the same as the built-in operators?
/*
Differ:

We can call an overloaded operator function directly.
An overloaded operator function must either be a member of a class or have at least one parameter of class type.
A few operators guarantee the order in which operands are evaluated. These overloaded versions of these operators do not preserve order of evaluation and/or short-circuit evaluation, it is usually a bad idea to overload them.
In particular, the operand-evaluation guarantees of the logical AND, logical OR, and comma operators are not preserved, Moreover, overloaded versions of && or || operators do not preserve short-circuit evaluation properties of the built-in operators. Both operands are always evaluated.

Same:

An overloaded operator has the same precedence and associativity as the corresponding built-in operator.
*/

//ex14.3 Both string and vector define an overloaded == that can be used to compare objects of those types. 
//Assuming svec1 and svec2 are vectors that hold strings, identify which version of == is applied in each of the following expressions:
//(a) "cobble" == "stone"
//(b) svec1[0] == svec2[0]
//(c) svec1 == svec2
//(d) "svec1[0] == "stone"
/*
(a) neither. (b) string (c) vector (d) string
*/

//ex14.4 Explain how to decide whether the following should be class members:
//(a) % (b) %= (c) ++ (d) -> (e) << (f) && (g) == (h)()
/*
(a) symmetric operator. Hence, non-member

(b) changing state of objects. Hence, member

(c) changing state of objects. Hence, member

(d) = () [] -> must be member

(e) non-member

(f) symmetric , non-member

(g) symmetric , non-member

(h) = () [] -> must be member
*/

//ex14.6 Define an output operator for your Sales_data class.
//see Exercise 14.2.

//ex14.9 Define an input operator for your Sales_data class.
//see Sales_data.h

//ex14.10 Describe the behavior of the Sales_data input operator if given the following input:
/*
(a) 0-201-99999-9 10 24.95

(b) 10 24.95 0-210-99999-9

(a) correct format.

(b) illegal input. But .95 will be converted to a float stored in this object. As a result, the data inside will be a wrong one.

Output: 10 24 22.8 0.95
*/

//ex14.11  What, if anything, is wrong with the following Sales_data input operator? 
//What would happen if we gave this operator the data in the previous exercise?
/*
istream& operator>>(istream& in, Sales_data& s)
{
double price;
in >> s.bookNo >> s.units_sold >> price;
s.revenue = s.units_sold * price;
return in;
}


no input check. nothing happened.
*/

//ex14.12 Define an input operator for the class you used in exercise 7.40 from 7.5.1 (p. 291). 
//Be sure the operator handles input errors.
//see Book.h

//ex14.13 Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think Sales_data ought to support? 
//Define any you think the class should include.
//on others.

//ex14.14 Why do you think it is more efficient to define operator+ to call operator+= rather than the other way around?
//https://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the

//ex14.15  Should the class you chose for exercise 7.40 from 7.5.1 (p. 291) define any of the arithmetic operators? 
//If so, implement them. If not, explain why not.
// See Book.h

//ex14.16 Define equality and inequality operators for your StrBlob (12.1.1, p. 456), StrBlobPtr (12.1.6, p. 474), StrVec (13.5, p.526), and String (13.5, p. 531) classes.

//ex14.21 Write the Sales_data operators so that + does the actual addition and += calls +. 
//Discuss the disadvantages of this approach compared to the way these operators were defined in 14.3 (p. 560) and 14.4 (p.564).
/*
	Sales_data& Sales_data::operator+=(const Sales_data &rhs)
	{
		Sales_data old_data = *this;
		*this = old_data + rhs;
		return *this;
	}

	Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
	{
		Sales_data sum;
		sum.units_sold = lhs.units_sold + rhs.units_sold;
		sum.revenue = lhs.revenue + rhs.revenue;
		return sum;
	}

Disadvantages: Both + and +=, uses an temporary object of Sales_data. But it is no need for that.
*/

//ex14.41 Why do you suppose the new standard added lambdas? 
//Explain when you would use a lambda and when you would write a class instead.
/*
IMO, lambda is quite handy to use. Lambda can be used when the functor is not used frequently nor complicated, 
whereas functor is supposed to call more times than lambda or quite complicated to implement as a lambda.
*/

//ex14.42 Using library function objects and adaptors, define an expression to
//(a)Count the number of values that are greater than 1024
//(b)Find the first string that is not equal to pooh
//(c) Multiply all values by 2
/*
std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), _1, 2));
*/