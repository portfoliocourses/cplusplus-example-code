/*******************************************************************************
*
* Program: Convert Fahrenheit To Celsius
* 
* Description: Program to convert a temperature in Fahrenheit to a temperature 
* in Celsius using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4gWfLJB7W10  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // Variables to store temperatures in celsius and fahrenheit.  Type double is
  // used because temperatures may have decimal places and double type variables
  // can store numbers with decimal places.
  double celsius, fahrenheit;
  
  // Prompt the user to enter the temperature in fahrenheit
  cout << "Enter Temperature (F): ";
  
  // Store the temperature entered into the variable fahrenheit
  cin >> fahrenheit;
  
  // Convert the temperature in fahrenheit to the temperature in celsius using 
  // the formula: https://en.wikipedia.org/wiki/Celsius.  Store the 
  // converted temperature into the variable celsius.
  celsius = (fahrenheit - 32) * (5.0/9.0);
  
  // Output the temperature in celsius with 2 decimal digits of precision 
  // using the stream manipulators fixed and setprecision from the iomanip
  // library.
  cout << "Temperature (C): ";
  cout << fixed << setprecision(2) << celsius << endl;

  return 0;
}