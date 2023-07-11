/*******************************************************************************
*
* Program: Check If A Number Is Prime
*
* Description: Check if a number is prime or not using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=BUNzco2GkBA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// Prime numbers are natural numbers greater than 1 divisible only by 1 and the 
// number itself.
//
// A number is divisible by another if the remainder after division is zero.
//
// 5 is a prime number
//
// 5 / 2 = 2 remainder 1
// 5 / 3 = 1 remainder 2
// 5 / 4 = 1 remainder 1
//
// 6 is not a prime number
//
// 6 / 2 = 3 remainder 0
// 6 / 3 = 2 remainder 0
// 6 / 4 = 1 remainder 2
// 6 / 5 = 1 remainder 1
//
// Our recursive functions will check if the number is divisible by any 
// divisor between 1 and the number itself.  Notably, we can stop checking
// for numbers greater than n/2 as it is not possible for n to be divisible
// by these numbers.

#include <iostream>

using namespace std;

bool isPrime(int n);

int main()
{
  // Check which integers between 1 and 20 are prime
  for (int j = 1; j <= 20; j++)
  {
    // Use isPrime() to check if each integer is prime
    if (isPrime(j))
    {
      cout << j << " is a prime number." << endl;
    }
    else
    {
      cout << j << " is not a prime number." << endl;
    }
  }
  
  return 0;
}

// Returns true if n is prime and false otherwise
bool isPrime(int n)
{
  // Numbers <= 1 are not prime by definition
  if (n <= 1) return false;
  
  // Check integers between (1 ... n/2] to see which if n is divisible by any
  // of them, if it is, return false as n is not prime
  for (int i = 2; i <= (n/2); i++)
  {
    if (n % i == 0) return false;
  }
  
  // If n is not divisible by any of the above integers n must be prime so 
  // the function can return true
  return true;
}