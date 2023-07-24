/*******************************************************************************
*
* Program: Count The Number Of Digits In An Integer Number
* 
* Description: Program to count the number of digits in an integer number using
* C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=w8A3GW9ILc4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int count_digits(int number);

int main()
{
  // Test the function out with the number 5365 which has 4 digits
  cout << "The number of digits in 5365: ";
  cout << count_digits(5365) << endl;
  
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
// digits in the number.  In the "special case" that the original number 
// is already 0 we can say it has 1 digit.

// Returns the number of digits in the int number
int count_digits(int number)
{
  // In the 'special case' the number is 0 to begin with we just return 1 as 
  // 0 has 1 digit
  if (number == 0)
  {
    return 1;
  }
  
  // The variable digits stores the running count of digits in the number,
  // we continually divide the number by 10 until it is equal to zero and 
  // count the number of divisions (i.e. the number of digits in the 
  // number) by incrementing digits, which we then return.
  int digits = 0;
  
  while (number != 0)
  {
    number = number / 10;
    digits++;
  }
  
  return digits;
}