/*******************************************************************************
*
* Program: Area of a Triangle
* 
* Description: Demonstration of how to calculate the area of a triangle using 
* user input values for the triangle base and height with C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vRx67Z5PbNw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

double triangleArea(double height, double base);

int main()
{
  // Declare variables to store the triangle height, base and area.  We use
  // type double so we can handle heights, bases and areas with decimal
  // places like "2.45".
  double height = 0;
  double base = 0;
  double area = 0;

  // Prompt the user to enter the triangle height and store the entered height
  // into the height variable.  We use the cout object and the stream insertion
  // operator << to output the string "Height: " to the terminal to prompt the
  // user (*technically* it is output to what is called "standard output").  We
  // then use the cin object and the stream extraction operator to pause for
  // the user to input a number, and when they do enter a number and hit enter
  // the number will be stored into the height variable.
  cout << "Height: ";
  cin >> height;

  // Prompt the user to enter the triangle base and store the entered base
  // into the base variable.
  cout << "Base: ";
  cin >> base;

  // We could calculate the triangle area in the main() function by using the
  // multiplication operator * to multiply 0.5, base and height, and the
  // assignment operator = to store the result into the area variable.
  // area = 0.5 * base * height;

  // Or we could call the triangleArea() function we have created to calculate
  // and return the triangle area.  We pass the function the values of height
  // and base as arguments, and the return value is stored into the area
  // variable using the assignment operator.
  area = triangleArea(height, base);

  // Output the calculated area.  We first output the text "Triangle Area: " to 
  // provide a 'label' for the output value.  We then use the stream 
  // manipulators fixed and setprecision(2) from the iomanip library, which when
  // used together like this will modify the output format of the area variable
  // value so that it will output with 2 decimal digits of precision.  We then
  // use endl to output a newline character that will cause any future output
  // from the program to begin on the next line.
  cout << "Triangle Area: ";
  cout << fixed << setprecision(2) << area << endl;

  return 0;
}

// Returns the area of a triangle with the height and base values provided
// as arguments to the function.
double triangleArea(double height, double base)
{
  // Calculate the area of the triangle by multiplying 0.5, base & height
  // using the multiplication operator *, and return the value from the function
  // such that the resulting value will effectively "be placed" where this
  // function is called.
  return 0.5 * base * height;
}
