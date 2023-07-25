/*******************************************************************************
*
* Program: Count The Number Of Digits In An Integer Number Using Recursion
* 
* Description: Program to count the number of digits in an integer number using
* recursion with C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Kjib8QiOK9k 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int count_digits(int number);

int main()
{
  // Test the function out with the number 3512 which has 4 digits
  cout << count_digits(3512) << endl;
  
  return 0;
}


// We can count the number of digits in a number by continually dividing the 
// starting number and resulting quotients by 10 until the number is 0:
//
//  5365 / 10 = 536
//   536 / 10 = 53
//    53 / 10 = 5
//     5 / 10 = 0
//
// The number of division operations required to reach 0 is the number of 
// digits in the number.

// Returns the number of digits in the int number using recursion
int count_digits(int number)
{
  // The recursive case for this function uses number / 10 to remove one 
  // digit from the number, calling itself again to count the remaining digits
  // and adding 1 to the returned value to account for the number that was 
  // just removed.  Eventually recursion must stop at a 'base case'.
  //
  // We treat the case that number / 10 == 0 as the base case, returning 1 to 
  // account for the "last digit" in the number (or the only digit in the case
  // the original number the function was first called with only had one digit).

  if (number / 10 == 0) return 1;
  return 1 + count_digits(number / 10);
}