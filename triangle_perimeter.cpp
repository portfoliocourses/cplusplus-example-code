/*******************************************************************************
*
* Program: Triangle Perimeter Using User Input Values
*
* Description: Demonstration of how to calculate the perimeter of a triangle 
* using user input values with C++.  Remember that the perimeter of a triangle 
* is the sum of the length of its 3 sides.
*
* YouTube Lesson: https://www.youtube.com/watch?v=r521nk9hqP8
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

double triangle_perimeter(double side1, double side2, double side3);

int main()
{
  // Variables to store the 3 triangle side lengths, double is used because side
  // lengths may contain decimal places, e.g. 6.5
  double side1 = 0;
  double side2 = 0;
  double side3 = 0;
  
  // Prompt the user to enter each side length, store the entered value into 
  // variables side1, side, side3
  cout << "Enter Side 1 Length: ";
  cin >> side1;
  
  cout << "Enter Side 2 Length: ";
  cin >> side2;
  
  cout << "Enter Side 3 Length: ";
  cin >> side3;
  
  // We could directly calculate the perimeter by adding the 3 side lengths 
  // together and storing the result into a new double variable perimeter
  // double perimeter = side1 + side2 + side3;
  
  // Or we could call the function we've created to calculate the side lengths,
  // passing it the 3 side lengths as arguments, and storing the return value
  // into the new double perimeter variable.  
  double perimeter = triangle_perimeter(side1, side2, side3);
  
  // Output the triangle perimeter with 2 decimal digits of precision using 
  // the stream manipulators fixed and setprecision()
  cout << "Perimeter: ";
  cout << fixed << setprecision(2) << perimeter << endl;

  return 0;
}

// Return the perimeter of a triangle with side lengths side1, side, side3.
// The advantage of defining a function to calculate the perimeter is that
// we do not need to repeat the expression "side1 + side2 + side3" all 
// over the place in our code wherever a triangle perimeter calculation
// is needed.
double triangle_perimeter(double side1, double side2, double side3)
{
  return side1 + side2 + side3;
}
