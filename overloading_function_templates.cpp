/*******************************************************************************
*
* Program: Overloading Function Templates
* 
* Description: Example of how to overload function templates in C++, combining 
* the benefits of function overloading with the benefits of function templates.
*
* YouTube Lesson: https://www.youtube.com/watch?v=l0Tg_95OKWw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// Create a function template called sum that accepts two parameters and 
// returns a value of type parameter T.  The function will return the sum 
// of the two parameters, and so the addition operator + must be supported 
// by whatever type argument is provided when we use the function template.
template <typename T>
T sum(T a, T b)
{
  cout << "template sum" << endl;
  return a + b;
}

// Create a function template ALSO called sum (i.e. sum is overloaded) that 
// works the same as the above function template, except with 3 parameters.
template <typename T>
T sum(T a, T b, T c)
{
  return a + b + c;
}

// We can continue to overload sum with a non-template function that uses 
// two double parameters and a double return value specifically, creating 
// a potentially (but not actually) ambiguous situation as to which function
// is called when two double arguments are provided... either the function 
// template above that accepts two arguments of some type, OR this non-template
// function that uses type double specifically.
double sum(double a, double b)
{
  cout << "non-template sum" << endl;
  return a + b;
}

int main()
{
  // Either our non-template function OR our 1st two-parameter function template 
  // could be used here, so which does the compiler choose?  By default in C++ 
  // the compiler will run the non-template function when there is an ambiguity 
  // like this between a function template and a non-template function.  Notice
  // the "non-template sum" in the output.  
  cout << sum(2.0,3.5) << endl;
  
  // At compile-time the compiler will determine that we are using the sum 
  // function template that accepts three arguments, and that we are using 
  // type double arguments, and it will generate a 'template function' using 
  // this function template that uses the type double in-place of T.  That 
  // function will then be called at runtime when this statement is executed.
  cout << sum(1.0,1.1,1.4) << endl;
  
  // Here when we pass int values to sum, the compiler will use the function 
  // template that accepts two arguments as the non-template function accepts 
  // double arguments.  As above, the compiler will use the function template 
  // to generate at compile-time a type-specific 'template function' that uses
  // the type int, and THAT function will be called at runtime when this 
  // statement is executed.
  cout << sum(1,3) << endl;
  
  // The compiler will use the function template that accepts 3 arguments, but 
  // this time it will create the type-specific template function using int as 
  // the type.  We've effectively combined the benefits of function templates 
  // AND function overloading as we're able to use both a varying number and 
  // type of arguments with sum.
  cout << sum(1,3,5) << endl;
  
  return 0;
}