/*******************************************************************************
*
* Program: Convert Kilometers To Miles
* 
* Description: Program to convert a distance in kilometers to a distance in 
* miles using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=2GdvqM-j-C0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // Variables to store distances in miles and kilometers.  Type double is
  // used because distances may have decimal places and double type variables
  // can store numbers with decimal places.
  double miles, kilometers;
  
  // Prompt the user to enter the distance in kilometers
  cout << "Kilometers: ";
  
  // Store the entered distance in the variable kilometers
  cin >> kilometers;
  
  // Convert the distance in kilometers to the distance in miles and store 
  // the result in the variable miles using the formula found here:
  // https://en.wikipedia.org/wiki/Kilometre
  miles = 0.621371 * kilometers;
  
  // Output the text "Miles: "
  cout << "Miles: ";
  
  // Then output the value stored in the variable miles with 2 decimal digits 
  // of precision using the stream manipulators fixed and setprecision.
  cout << fixed << setprecision(2) << miles << endl;

  return 0;
}