/*******************************************************************************
*
* Program: setbase Example
* 
* Description: Example of using setbase to output integers as hexadecimal and 
* octal numbers in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=b5vLRm4XDQI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

// setbase is in the iomanip library, so we must include it to use it
#include <iomanip>

using namespace std;

int main()
{
  int number = 17;
  
  // normally integers will output in base 10, i.e. deciaml, the way numbers 
  // are typically represented
  cout << "number: " << number << endl;
  
  // setbase is a stream manipulator, if we pass in the value 8 using it as 
  // below future ints output in the stream will be output as base 8 (octal) 
  // numbers 
  cout << "number: " << setbase(8) << number << endl;

  // if we pass in the value 16 subsequent integers will be outpiut using base 
  // 16, i.e. hexadecimal numbers
  cout << "number: " << setbase(16) << number << endl;

  // we can switch it back to base 10 / decimal with setbase(10)
  cout << "number: " << setbase(10) << number << endl;
  
  // output the numbers 0-32 as decimal, octal and hexadecimal numbers
  for (int i = 0; i <= 32; i++)
  {
    cout << setbase(10) << i << " ";
    cout << setbase(8) << i << " ";
    cout << setbase(16) << i << endl;
  }
  
  return 0;
}