/*******************************************************************************
*
* Program: Convert Miles To Kilometers
* 
* Description: Program to convert a distance in miles to a distance in 
* kilometers using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4Cd8pKAfrMA  
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
  
  // Prompt the user to enter the distance in miles
  cout << "Miles: ";
  
  // Store the entered distance in the variable miles
  cin >> miles;
  
  // Convert the distance in miles to the distance in kilometers and store 
  // the result in the variable kilometers using the formula found here:
  // https://en.wikipedia.org/wiki/Kilometre
  kilometers = miles / 0.621371;
  
  // Output the text "Kilometers: "
  cout << "Kilometers: ";
  
  // Then output the value stored in the variable kilometers with 2 decimal 
  // digits of precision using the stream manipulators fixed and setprecision.
  cout << fixed << setprecision(2) << kilometers << endl;

  return 0;
}