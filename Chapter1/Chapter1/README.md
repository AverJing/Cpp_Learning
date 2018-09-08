# Chapter 1: Getting Started

## Exercise1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

- easy

## Exercise1.2

> Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

[code](https://github.com/AverJing/Cpp_Learning/blob/master/Chapter1/Chapter1/ex01_2.cpp)

## Exercise1.3

> Write a program to print Hello, World on the standard output.

[code](https://github.com/AverJing/Cpp_Learning/blob/master/Chapter1/Chapter1/ex01_3.cpp)

## Exercise1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

[code](https://github.com/AverJing/Cpp_Learning/blob/master/Chapter1/Chapter1/ex01_4.cpp)

## Exercise1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

[code](https://github.com/AverJing/Cpp_Learning/blob/master/Chapter1/Chapter1/ex01_5.cpp)

## Exercise1.6

> Explain whether the following program fragment is legal.
>
> ```cpp
> std::cout << "The sum of " << v1; << " and " << v2; << " is " << v1 + v2 << std::endl;
> ```
>
> If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

It's illegal. Fixed it.

```cpp
std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
```

## Exercise1.7

> Compile a program that has incorrectly nested comments.

Example:

```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
  return 0;
}
```

Such comments begin with a /* and end with the next */. These comments can include anything that is not a */, including newlines. The compiler treats everything that **falls** between the /\* and */ as part of comments.

## Exercise1.8

>  Indicate which, if any, of the following output statements are legal:
>
> ```cpp 
> std::cout << "/*";
> std::cout << "*/";
> std::cout << /* "*/" */;
> std::cout << /* "*/" /* "/*" */;
> ```
>
> After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

correct.

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";   //here
std::cout << /* "*/" /* "/*" */;
```



## Exercise1.9

>  Write a program that uses a while to sum the numbers from 50 to 100.

[code](https://github.com/AverJing/Cpp_Learning/tree/master/Chapter1/Chapter1)

## Exercise1.10

>  In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.

[code](https://github.com/AverJing/Cpp_Learning/tree/master/Chapter1/Chapter1)

## Exercise1.11

> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

[code](https://github.com/AverJing/Cpp_Learning/tree/master/Chapter1/Chapter1)

## Exercise1.12

> What does the following for loop do? What is the final value of sum?
>
> ```cpp
> int sum = 0;
> for (int i = -100; i <= 100; ++i)
>  sum += i;
> ```

the loop sums the numbers from -100 to 100. the final value of sum is 0

## Exercise1.13

> Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

[code](https://github.com/AverJing/Cpp_Learning/tree/master/Chapter1/Chapter1)

## Exercise1.14

>  Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?

@pezy:

- Advantage of `for` and disadvantage of `while`:
    - Locality, the variable in the scope of the loop.
    - Pattern happens so often: using a variable in a condition and incrementing that variable in the body.
- Advantage of `while` and disadvantage of `for`:
    - Clear when there is only one static condition.
    - Readable when the global variables incremented in the body.

-----

[A similar question on Stack Overflow](http://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)

## Exercise1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

ignore. If you are not familiar with that, check it.

## Exercise1.16

>  Write your own version of a program that prints the sum of a set of integers read from cin.

```cpp
int sum = 0;
for(int value = 0; std::cin >> value;)	//cin and cout in header <iostream>
    sum += value;
std::cout << sum << std::endl;
```

## Exercise1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If all equal, the count of this numerb will be printed out. If there is no equal, a new line will be printed out when you enter a number.

## Exercise1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

[code](https://github.com/AverJing/Cpp_Learning/tree/master/Chapter1/Chapter1)

## Exercise1.19

>  Revise the program you wrote for the exercises in § 1.4.1 (p.13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

check ex1.11

## Exercise1.20

> <http://www.informit.com/title/032174113> contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

[code](https://github.com/AverJing/Cpp_Learning/blob/master/Chapter1/Chapter1/Excercise1_all.cpp)

## Exercise1.21

> Write a program that reads two Sales_item objects that have the same ISBN and produces their sum

[code](https://github.com/AverJing/Cpp_Learning/blob/master/Chapter1/Chapter1/Excercise1_all.cpp)

## Exercise1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

[code](https://github.com/AverJing/Cpp_Learning/blob/master/Chapter1/Chapter1/Excercise1_all.cpp)

## Exercise1.23

> Write a program that reads several transactions and counts how many transactions occur for each ISBN.

[code](https://github.com/AverJing/Cpp_Learning/blob/master/Chapter1/Chapter1/Excercise1_all.cpp)

## Exercise1.24

> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

check 1.23

## Exercise1.25

> Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.

[code](https://github.com/AverJing/Cpp_Learning/tree/master/Chapter1/Chapter1)