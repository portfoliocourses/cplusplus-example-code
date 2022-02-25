/*******************************************************************************
*
* Program: setprecision Stream Manipulator
* 
* Description: Examples of using the setprecision stream manipulator in C++ to
* format the output of floating point values.
*
* YouTube Lesson: https://www.youtube.com/watch?v=lWSoZMggqco
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  double n = 42.123456;
  
  // setprecision will limit the number of digits output for the floating 
  // point value n to the argument provided (5,4,3,...)
  cout << "5: " << setprecision(5) << n << endl;
  cout << "4: " << setprecision(4) << n << endl;
  cout << "3: " << setprecision(3) << n << endl;
  cout << "2: " << setprecision(2) << n << endl;
  cout << "1: " << setprecision(1) << n << endl;

  cout << endl;
  
  // When used in conjunction with the stream manipulator fixed, we can have 
  // setprecision output a certain amount of *decimal* digits (digits after 
  // the decimal).  The stream manipulator fixed is for fixed-point notation.
  cout << "5: " << fixed << setprecision(5) << n << endl;
  cout << "4: " << fixed << setprecision(4) << n << endl;
  cout << "3: " << fixed << setprecision(3) << n << endl;
  cout << "2: " << fixed << setprecision(2) << n << endl;
  cout << "1: " << fixed << setprecision(1) << n << endl;
  
  cout << endl;
  
  // We can use scientific to get scientific notation output of the  number n,
  // again with a certain of amount of decimal digits.
  cout << "5: " << scientific << setprecision(5) << n << endl;
  cout << "4: " << scientific << setprecision(4) << n << endl;
  cout << "3: " << scientific << setprecision(3) << n << endl;
  cout << "2: " << scientific << setprecision(2) << n << endl;
  cout << "1: " << scientific << setprecision(1) << n << endl;
  
  cout << endl;
  
  double n1 = 34.2;
  double n2 = 23.456;
  
  // When using fixed and setprecision together, we will get the provided amount
  // of decimal digits of output even if those digits are 0s.  So in the case of
  // n1 for example we will get 34.200 even though the last 2 digits don't 
  // really provide any more information, and that's because setprecision(3) 
  // will ensure the number is output with 3 decimal digits.
  cout << "n1: " << fixed << setprecision(3) << n1 << endl;
  cout << "n2: " << fixed << setprecision(3) << n2 << endl;

  cout << endl;
  
  return 0;
}