/*******************************************************************************
*
* Program: Add Two Numbers
* 
* Description: Program to add together two numbers provided from user input and 
* output the resulting sum using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Fk-9KCBOsp8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // Declare 3 double variables, x and y to store the two numbers, and sum to 
  // store the resulting sum
  double x, y, sum;
  
  // Prompt the user to enter two numbers
  cout << "Enter two numbers: ";
  
  // Store the two numbers that the user enters into the variables x and y
  cin >> x >> y;
  
  // Sum the values of x and y and store the result into sum
  sum = x + y;
  
  // Output the resulting sum of x and y in the format x + y = sum
  cout << x << " + " << y << " = " << sum << endl;

  // Note that we could have used int type variables to store the numbers, but 
  // then the numbers could not contain decimal places as int type variables 
  // can only store integer values like -4,6,etc.

  return 0;
}