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
  double side1 = 0;
  double side2 = 0;
  double side3 = 0;
  
  cout << "Enter Side 1 Length: ";
  cin >> side1;
  
  cout << "Enter Side 2 Length: ";
  cin >> side2;
  
  cout << "Enter Side 3 Length: ";
  cin >> side3;
  
  double perimeter = triangle_perimeter(side1, side2, side3);
   
  cout << "Perimeter: ";
  cout << fixed << setprecision(2) << perimeter << endl;

  return 0;
}

double triangle_perimeter(double side1, double side2, double side3)
{
  return side1 + side2 + side3;
}

