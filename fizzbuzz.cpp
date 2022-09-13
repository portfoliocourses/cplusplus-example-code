/*******************************************************************************
*
* Program: FizzBuzz Problem
* 
* Description: A program that outputs the first 100 values in the FizzBuzz 
* problem using C++.  See the Wikipedia article on the FizzBuzz problem: 
* https://en.wikipedia.org/wiki/Fizz_buzz.
*
* YouTube Lesson: https://www.youtube.com/watch?v=GyoP6GzhL7Q 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // The FizzBuzz sequence involves ouputting the numbers from 1, 2, on upward
  // by 1.  Except for numbers divisible by 3 we output "Fizz", for numbers 
  // divisible by 5 we output "Buzz", and for numbers divisibly by 3 and by 5
  // we output "FizzBuzz".  We'll output the first 100 values in the sequence.
  
  // Increment a counter variable i from 1 to 100 by 1 with each loop iteration
  for (int i = 1; i <= 100; i++)
  {
    // A number is divisible by 3 if there is zero remainder when we divide it
    // by 3.  We can check if a number is divisible by 5 in the same way.  The 
    // modulus operator % will return the remainder of a division calculation, 
    // so i % 3 gives us the remainder of i divided by 3.  So we check if 
    // the remainder is zero with i % 3 == 0, letting us know if i is divisible
    // by 3 or not.  We can do the same with 5 to check if i is divisible by 
    // 5 or not.
    //
    // In the below if-else if-else control structure, we FIRST check if i 
    // is divisible by 3 and 5, if it is we output FizzBuzz, then we check if i 
    // is divisible by 3 and if it is we output Fuzz, then we check if i is 
    // divisible by 5 and if it is we output Buzz, and finally if none of these
    // is true we output the number.  This will give us the correct value in 
    // the FizzBuzz sequence.  It is important we first check if i is divisible
    // by 3 and 5 before we check if it is divisible by one OR the other.  If 
    // we checked that i is divisible by 3 first for example, we would never 
    // reach the case where i is divisible by 3 and by 5 if it were true, 
    // as the first condition would already be true (i is divisible by 3).  
    // This is a common mistake made when implementing the algorithm!
    //
    if (i % 3 == 0 && i % 5 == 0)
      cout << "FizzBuzz" << endl;
    else if (i % 3 == 0)
      cout << "Fizz" << endl;
    else if (i % 5 == 0)
      cout << "Buzz" << endl;
    else
      cout << i << endl;
  }
  
  return 0;
}

// The Fizz Buzz sequence from 1 - 17:
//
//  1
//  2
//  Fizz       (3 % 3 == 0)
//  4
//  Buzz       (5 % 5 == 0)
//  Fizz       (6 % 3 == 0)
//  7
//  8
//  Fizz       (9 % 3 == 0)
//  Buzz       (10 % 5 == 0)
//  11
//  Fizz       (12 % 3 == 0)
//  13
//  14
//  Fizz Buzz  (15 % 3 == 0 AND 15 % 5 == 0)
//  16
//  17
//  ...
