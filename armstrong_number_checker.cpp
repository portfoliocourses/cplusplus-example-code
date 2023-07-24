/*******************************************************************************
*
* Program: Check If A Number Is An Armstrong Number
* 
* Description: Program to check if a number is an Armstrong number using C++.
* An Armstrong number is defined here, and also see informal definition below: 
* https://en.wikipedia.org/wiki/Narcissistic_number
*
* YouTube Lesson: https://www.youtube.com/watch?v=tmXDtb1xhGY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// An Armstrong number is a number where the sum of each digit to the power of 
// the number of digits in the number is equal to the number itself.
//
// So for example 153 is an Armstrong number because...
//
// 153 = 1^3 + 5^3 + 3^3
// 153 = 1 + 125 + 27
// 153 = 153
//
// Where the number 153 has 3 digits, and so we take each digit 1,5,3, raise 
// them to the power of 3, and the sum of these numbers is equal to 153.
//
// To determine if a number is an Armstrong number or not we will need to 
// determine the number of digits in the number and 'extract' each digit in the
// number.  We can do this by dividing the number by 10, and continually 
// dividing the quotient of the previous division operation by 10 until the 
// quotient/number is equal to 0.  The number of division operations until the
// number is equal to 0 is the number of digits in the number, and the 
// remainders of these division operations are the digits...
//
// 153 / 10 = 15 remainder 3
// 15 / 10  = 1 remainder 5
// 1 / 10   = 0 remainder 1
//
// In C++ we can get the quotient of each division operation with the integer
// division operation / and the remainder with the modulus operator %...
//
//  / - integer division, quotient
//  % - modulus, remainder

#include <iostream>

using namespace std;

int count_digits(int number);
bool is_armstrong(int number);
int power(int x, int y);

int main()
{
  // Test the function out with 153 which is an Armstrong number
  if (is_armstrong(153))
  {
    cout << "153 is an Armstrong number." << endl;
  }
  return 0;
}

// Returns x to the power of y
int power(int x, int y)
{
  // Multiply x by result y times and store the result into power each time, 
  // to calculate and return x to the power of y
  int result = 1;
  
  for (int i = 0; i < y; i++)
  {
    result *= x;
  }
  
  return result;
}

// Returns the number of digits in the int value number
int count_digits(int number)
{
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

// Returns true if the int number is an Armstrong number and false otherwise
bool is_armstrong(int number)
{
  // Use count_digits() to find the total number of digits in the number and 
  // store the result into total_digits.
  int total_digits = count_digits(number);
  
  // Stores the running sum of each digit in the number taken to the power 
  // of the total number of digits in the number
  int sum = 0;

  // We'll follow the same process as in count_digits() of dividing the number
  // by 10 continually to go through each digit in the number.  But we'll also
  // need to compare the original number to the sum of each digit in the 
  // number taken to the power of the total number of digits in the number,
  // and we can't do this if we no longer have the original number due to 
  // modifying it as part of this process.  So we create a copy of the 
  // original number in temp.
  int temp = number;
  
  // We continually divide temp (i.e. number) by 10 until it is zero, each 
  // time we use modulus (temp % 10) to extract the next digit in the 
  // number.  We add this digit to the power of the total number of digits
  // to the sum. 
  while (temp != 0)
  {
    int digit = temp % 10;
    temp = temp / 10;
    sum += power(digit, total_digits);
  }

  // If the sum of each digit to the power of the total number of digits is 
  // equal to the number, return true as it is an Armstrong number, otherwise
  // we return false as it is not. 
  return sum == number;
}