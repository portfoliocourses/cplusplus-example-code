/*******************************************************************************
*
* Program: Rectangle Perimeter Using User Input Values
*
* Description: Demonstration of how to calculate the perimeter of a rectangle 
* using user input values with C++.  Remember that the perimeter of a rectangle 
* is 2 x length + 2 x width of the rectangle.
*
* YouTube Lesson: https://www.youtube.com/watch?v=aSCQQSz0kGQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

double rectangle_perimeter(double length, double width);

int main()
{
  // Declare variables to store the rectangle length, width and perimeter.  We 
  // use type double so we can handle lengths, widths and perimeters with 
  // decimal places like "2.45".
  double length = 0;
  double width = 0;
  double perimeter = 0;

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

  // We could calculate the rectangle perimeter in the main() function by using 
  // the multiplication operator * to multiply the length and width by 2 and 
  // the addition operator + to add the result of these multiplications 
  // together, and the assignment operator = to store the result into the 
  // perimeter variable.
  //
  // perimeter = 2 * length + 2 * width;

  // Or we could call the rectangle_perimeter() function we have created to 
  // calculate and return the rectangle perimeter.  We pass the function the 
  // values of length and width as arguments, and the return value is stored 
  // into the perimeter variable using the assignment operator.
  perimeter = rectangle_perimeter(length, width);

  // Output the calculated perimeter.  We first output the text "Perimeter: " 
  // to provide a 'label' for the output value.  We then use the stream 
  // manipulators fixed and setprecision(2) from the iomanip library, which when
  // used together like this will modify the output format of the perimeter 
  // variable value so that it will output with 2 decimal digits of precision.  
  // We then use endl to output a newline character that will cause any future 
  // output from the program to begin on the next line.
  cout << "Perimeter: ";
  cout << fixed << setprecision(2) << area << endl;

  return 0;
}

// Returns the perimeter of a rectangle with the length and width values 
// provided as arguments to the function.
double rectangle_perimeter(double length, double width)
{
  // Calculate the perimeter of the rectangle by multiplying length and width by 
  // 2 using the multiplication operator * and adding the result of these 
  // together with the addition operator +, and return the value from the 
  // function such that the resulting value will effectively "be placed" where 
  // this function is called.
  return 2 * length + 2 * width;
}
