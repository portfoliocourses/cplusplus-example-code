/*******************************************************************************
*
* Program: Sum Of Digits Of A Number Using Recursion
* 
* Description: Finds the sum of the digits of a number using recursion with C++
* (where the number is a non-negative integer).
*
* YouTube Lesson: https://www.youtube.com/watch?v=DWY-m1EWsaA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// To find the sum of the digits of a non-negative integer we can divide 
// the number by 10, i.e. get both the quotient and remainder.  We can 
// repeat this process, dividing the quotient by 10, until the number 
// is equal to 0.  If we then add up the remainders produced by these 
// division operations, we'll get the sum of the digits of the number!
//
// number = 237
//
// 237 / 10 = 23 remainder 7
//  23 / 10 =  2 remainder 3
//   2 / 10 =  0 remainder 2
//                         --
//                         12
//
// In C++ we can use the modulus operator % to get the remainder of a division
// operation, i.e.  237 % 10 = 7.
// 
// We can use the integer division operator / to get the quotient of a division
// operation, i.e. 237 / 10 = 23.
//

// Recursive function to find the sum of the digits of a number (specifically a
// non-negative integer).  The function applies the algorithm above, in the 
// recursive step the function applies the modulus operator to extract the next 
// digit of the number, and sums this with the result of calling itself again 
// with the quotient of the number divided by 10 (i.e. the number with the 
// 'remaining digits' after the last digit is extracted by number % 10).
// In the base step recursion stops when the number is equal to 0 and the 
// function just returns 0.
//
int sum_digits(int number)
{
    if (number == 0) return 0;
    
    return number % 10 + sum_digits(number / 10);
}

// Calling the function looks like this...
//
// sum_digits(237) = 7 + 3 + 2 + 0 -> 12
//                      
// sum_digits(23) = 3 + sum_digits(2)
//
// sum_digits(2) = 2 + sum_digits(0)
//
// sum_digits(0) = 0

int main()
{
  // Store the number whose digits we want to find the sum of
  int number = 0;
  
  // Prompt the user to enter the number, store it into the number variable
  cout << "Enter Number: ";
  cin >> number;
   
  // Call the function, pass it the number, and output the result
  cout << "Digits Sum: " << sum_digits(number) << endl;

  return 0;
}
