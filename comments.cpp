/*******************************************************************************
*
* Program: Comments Examples
*
* Description: Examples of using single line and multiline comments in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=dKErkyRxPyE
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  double x, y, sum; // Declare 3 variables

  // Prompt the user to enter the two numbers
  cout << "Enter two numbers: ";

  /*
   Accept user input for:
   - variable x
   - variable y
   */
  cin >> x >> y;

  // add together x and y
  // to produce the sum
  sum = x + y;

  // sum = y + x;

  cout << x << " + " << y << " = " << sum << endl;

  return 0;
}