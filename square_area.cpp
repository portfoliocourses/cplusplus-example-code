/*******************************************************************************
*
* Program: Square Area Using User Input
*
* Description: Demonstration of how to calculate the area of a square using a
* user input value for the square side length with C++.  Remember that the area
* of a square is side x side.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Jnebx24jHmg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

double squareArea(double side);

int main()
{
  // Declare variables to store the square side length and area.  We use type 
  // double so we can handle side lengths and areas with decimal places like 
  // "2.45".
  double side = 0;
  double area = 0;

  // Prompt the user to enter the square side length and store the entered value
  // into the side variable.  We use the cout object and the stream insertion
  // operator << to output the string "Side Length: " to the terminal to prompt 
  // the user (*technically* it is output to what is called "standard output"). 
  // We then use the cin object and the stream extraction operator to pause for
  // the user to input a number, and when they do enter a number and hit enter
  // the number will be stored into the side variable.
  cout << "Side Length: ";
  cin >> side;

  // We could calculate the square area in the main() function by using the
  // multiplication operator * to multiply the side length with itself, and the
  // assignment operator = to store the result into the area variable.
  // area = side * side;

  // Or we could call the squareArea() function we have created to calculate and
  // return the square area.  We pass the function the value of side length as 
  // an argument, and the return value is stored into the area variable using 
  // the assignment operator.
  area = squareArea(side);

  // Output the calculated area.  We first output the text "Square Area: " to 
  // provide a 'label' for the output value.  We then use the stream 
  // manipulators fixed and setprecision(2) from the iomanip library, which when
  // used together like this will modify the output format of the area variable
  // value so that it will output with 2 decimal digits of precision.  We then
  // use endl to output a newline character that will cause any future output
  // from the program to begin on the next line.
  cout << "Square Area: ";
  cout << fixed << setprecision(2) << area << endl;

  return 0;
}

// Returns the area of a square with the side length value provided as an 
// argument to the function.
double squareArea(double side)
{
  // Calculate the area of the square by multiplying side length with itself
  // using the multiplication operator *, and return the value from the function
  // such that the resulting value will effectively "be placed" where this
  // function is called.
  return side * side;
}