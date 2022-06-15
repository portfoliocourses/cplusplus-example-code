/*******************************************************************************
*
* Program: gcd() Built-In Greatest Common Divisor Function Example
* 
* Description: Example of how to use the built-in gcd() greatest common divisor 
* function in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=VnfkG8NtrjA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

// With C++17 onwards we include numeric and use the gcd() function
#include <numeric>

// In C+14 we use the algorithm library and the __gcd() function
// #include <algorithm>

using namespace std;

int main()
{
  // We call the function by providing two integers as arguments and it returns
  // the greatest common divisor.
  int divisor = gcd(20,12);
  
  // We can't provide a double value as an argument, this will result in a 
  // compilation error if we uncomment the statement below.
  // int divisor = gcd(20,12.0);
  
  // We call the function like this with __ prefix when using C++14 version
  // int divisor = __gcd(20,12);

  // Output the GCD
  cout << "divisor: " << divisor << endl;
  
  return 0;
}

// Greatest common divisor concept reminder...
//
// A divisor is a number that divides another number with no remainder.
//
// In the case of 20 and 12 we have the following divisors:
//
// 20 - 20, 10, 5, 4*, 2, 1
//
// 12 - 12, 6, 4*, 3, 2, 1
//
// With 4 being the greatest *common* divisor!

