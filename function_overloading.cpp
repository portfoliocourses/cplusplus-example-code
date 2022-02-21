/*******************************************************************************
*
* Program: Function Overloading Example
* 
* Description: Examples of using function overloading in C++ to have multiple 
* functions with the same name in the same scope.
*
* YouTube Lesson: https://www.youtube.com/watch?v=A9COxBajDng 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// add function with 2 int parameters
int add(int x, int y)
{
  return x + y;
}

// add function with 3 int parameters... because the number of parameters are
// different than the function above, C++ will allow this
int add(int x, int y, int z)
{
  return x + y + z;
}

// add function with 3 double parameters... because the types of parameters 
// are different than the function above, C++ will allow this too!
double add(double x, double y, double z)
{
  return x + y + z;
}

// Even though the NAMES of the parameters are different, we will get an error
// with the below add function because the number and types of parameters are 
// identical to the add function above!
/*
double add(double a, double b, double c)
{
  return a + b + c;
}
*/

// Member functions can also be overloaded, as this Add class has two member
// functions called add
class Add
{
public:
  
  // add function with two int parameters
  int add(int x, int y)
  {
    return x + y;
  }
  
  // add function with two double parameters, because the type of a parameter 
  // is different (in this case, both parameter's types), C++ will allow this
  double add(double x, double y)
  {
    return x + y;
  }
  
};

int main()
{
  // call the 3 different add functions
  cout << add(10,5) << endl;
  cout << add(10,5,2) << endl;
  cout << add(10.5,3.2,4.1) << endl;

  // If we try the below an error will result as it is ambiguous which add 
  // function we intend to call.  In the above with the floating-point literal 
  // 10.5 it is clear we intend to call the add function with 3 double
  // parameters, but the integer literal 10 makes it unambiguous.
  // cout << add(10,3.2,4.1) << endl;

  
  // create an add object
  Add add_obj;
  
  // test out both the 'int' and 'double' add member functions
  cout << add_obj.add(10,5) << endl;
  cout << add_obj.add(10.5,4.5) << endl;
  
  return 0;
}