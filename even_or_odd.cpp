/*******************************************************************************
*
* Program: Check If A Number Is Even Or Odd
*
* Description: Program to check if a number is even or odd using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=kZ_taVVjhwU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// If an integer is divisible by 2 it is even, otherwise it is odd.  If an
// integer is divisible by 2, this means when the integer is divided by 2 there
// will be zero remainder.
//
// So for example:
//
// 8 / 2 = 4 with 0 remainder     <--- 8 is even
// 9 / 2 = 4 with 1 remainder     <--- 9 is odd
//
// When dividing an integer by 2 the remainder will either be 0 or 1.  If the
// remainder is 0 the integer is even, if it is 1 the integer is odd.  These
// are the only two posibilities, so if the remainder is not 0 it will be 1,
// and vice versa.

bool isEven(int number);
bool isOdd(int number);

int main()
{
  // Declare an int variable to store the integer the user enters
  int number = 0;

  // Prompt the user to enter an integer and store the integer into the number
  // variable
  cout << "Enter Integer: ";
  cin >> number;

  // If the integer is odd output that the integer is odd, otherwise output
  // that it is even.
  if (isOdd(number))
    cout << number << " is odd." << endl;
  else
    cout << number << " is even." << endl;

  // We could have also used the isEven() function like this...
  /*
  if (isEven(number))
    cout << number << " is even." << endl;
  else
    cout << number << " is odd." << endl;
  */

  // Or we could have done the check to see if the number is even or odd
  // right in the if statement condition like this...
  /*
  if (number % 2 == 0)
    cout << number << " is even." << endl;
  else
    cout << number << " is odd." << endl;
  */

  return 0;
}

// Returns true if the number is even, and false if it is odd
bool isEven(int number)
{
  // The modulus operator % will give us the remainder of number divided by 2,
  // and if that remainder is equal to 0 (as checked by ==) then the number
  // is even and we return true, otherwise we return false.
  return (number % 2 == 0);
}

// Returns true if the number is odd, and false if it is even
bool isOdd(int number)
{
  // We use the modulus operator again, this time we check if the remainder is
  // equal to 1, in which case we return true that the number is odd, otherwise
  // we return false.
  return (number % 2 == 1);
}