/*******************************************************************************
*
* Program: Function Templates Demonstration
* 
* Description: Example of using function templates in C++ to reduce code 
* duplication.
*
* YouTube Lesson: https://www.youtube.com/watch?v=XgGEJylsWsQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// This template prefix allows us to create a function template find_max, with 
// a single type parameter T which we can also call a template variable.  When 
// we call find_max in our program, the compiler will at compile time create 
// and use a type specific version of the find_max function called a template 
// function (so if we call find_max with ints, T will be replaced with int, if 
// we call find_max with double T will be replaced with double).  The find_max 
// function will find the maximum of a and b.
template <typename T>
T find_max(T a, T b)
{
  if (a > b) return a;
  else return b;
}

// We can create function templates with multiple type parameters by seperating 
// them by commas.  Here we return the max size in bytes of two parameters a 
// and b using two different type parameters T1 and T2.
template <typename T1, typename T2>
int find_max_size(T1 a, T2 b)
{
  if (sizeof(a) > sizeof(b)) return sizeof(a);
  else return sizeof(b);
}

int main()
{
  // create two doubles to find a max
  double x = 10.6;
  double y = 5.3;
  
  // Use our function template find_max and explicitly provide 'double' as an 
  // argument for the template parameter T.  The compiler will create a version
  // of the find_max function specific to the type double and use it here.
  double max_double = find_max<double>(x,y);
  
  // verify the correct maximum double value is returned 
  cout << "max_double: " << max_double << endl;
  

  // create two ints to find a max
  int m = 5;
  int n = 3;
  
  // Use our function template find_max again, this time with int arguments. 
  // Note that if we don't explicitly provide a type like find_max<int>(m,n) it 
  // will still work because the compiler can figure out the type needed 
  // based on our arguments.
  int max_int = find_max(m,n);
  
  // verify the correct maximum int value is returned
  cout << "max_int: " << max_int << endl;
  

  // try max_size below using different arguments like x,m,c,b, etc.
  char c;
  byte b;

  // Find the maximum size of the two arguments provided... any combination 
  // of types can be used because we have two type parameters in oru function 
  // template find_max_size.
  int max_size = find_max_size(c, b);
  
  // verify the correct maximum size of the two arguments is output 
  cout << "max_size: " << max_size << endl;
  
  return 0;
}


// At compile time, based on how we use the function template in our function 
// calls, the compiler will decide to generate different type-specific versions
// of the function to be used at run-time (called template functions).  The 
// process is visualized below.
//
//
// double x = 10.6                           int m = 5;
// double y = 5.3;                           int n = 3;
//
// find_max(x,y)     <- Function Calls ->    find_max(m,n)
//              \                           /
//               \                         /
//                \                       /
//                 \                     /
//
//                  template <typename T>
//                  T find_max(T a, T b)
//  Function        {
//  Template ->       if (a > b) return a;
//                    else return b;
//                  }
//
//                 /               \
//                /                 \
//               /                   \
//              /                     \
//
// double find_max(double a,       int find_max(int a,
//                 double b)                    int b)
// {                               {
//   if (a > b) return a;            if (a > b) return a;
//   else return b;                  else return b;
// }                               }
//
//                \                  /
//                 Template Functions