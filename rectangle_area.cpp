/*******************************************************************************
*
* Program: Rectangle Area Using User Input Values
*
* Description: Demonstration of how to calculate the area of a rectangle using
* user input values with C++.  Remember that the area of a rectangle is
* length x width of the rectangle.
*
* YouTube Lesson: https://www.youtube.com/watch?v=co91qbu3rh0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

double rectangleArea(double length, double width);

int main()
{
  // Declare variables to store the rectangle length, width and area.  We use
  // type double so we can handle lengths, widths and areas with decimal
  // places like "2.45".
  double length = 0;
  double width = 0;
  double area = 0;

  // Prompt the user to enter the rectangle length and store the entered length
  // into the length variable.  We use the cout object and the stream insertion
  // operator << to output the string "Length: " to the terminal to prompt the
  // user (*technically* it is output to what is called "standard output").  We
  // then use the cin object and the stream extraction operator to pause for
  // the user to input a number, and when they do enter a number and hit enter
  // the number will be stored into the length variable.
  cout << "Length: ";
  cin >> length;

  // Prompt the user to enter the rectangle width and store the entered width
  // into the width variable.
  cout << "Width: ";
  cin >> width;

  // We could calculate the rectangle area in the main() function by using the
  // multiplication operator * to multiply the length and width, and the
  // assignment operator = to store the result into the area variable.
  // area = length * width;

  // Or we could call the rectangleArea() function we have created to calculate
  // and return the rectangle area.  We pass the function the values of length
  // and width as arguments, and the return value is stored into the area
  // variable using the assignment operator.
  area = rectangleArea(length, width);

  // Output the calculated area.  We first output the text "Area: " to provide
  // a 'label' for the output value.  We then use the stream manipulators
  // fixed and setprecision(2) from the iomanip library, which when used
  // together like this will modify the output format of the area variable
  // value so that it will output with 2 decimal digits of precision.  We then
  // use endl to output a newline character that will cause any future output
  // from the program to begin on the next line.
  cout << "Area: ";
  cout << fixed << setprecision(2) << area << endl;

  return 0;
}

// Returns the area of a rectangle with the length and width values provided
// as arguments to the function.
double rectangleArea(double length, double width)
{
  // Calculate the area of the rectangle by multiplying length and width
  // using the multiplication operator *, and return the value from the function
  // such that the resulting value will effectively "be placed" where this
  // function is called.
  return length * width;
}
