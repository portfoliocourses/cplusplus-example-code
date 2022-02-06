/*******************************************************************************
*
* Program: 
* 
* Description: Demonstration of how to use cin to accept user input with C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1xY0rF399j0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A simple square shape type
class Square {
  
private:
  int side_length;

  // static member variables, also know as class variables, are 
  // variables of the class rather than specific to an individual 
  // object instance
  static int total_squares;
  
  // static member functions can be private, and only accessible within 
  // the class 
  static void incrementTotal()
  {
    // static member functions can alter static member variables
    total_squares++;
  }
  
public:
  
  Square(int length)
  {
    side_length = length;

    // we can call private static member functions in non-static member 
    // functions
    incrementTotal();
  }
    
  int area()
  {
    return side_length * side_length;
  }
  
  // public static member functions are available outside the class definition,
  // such as in the main function
  static int getTotal()
  {
    return total_squares;
  }
  
};

// initialize the private member variable
int Square::total_squares = 0;

int main()
{
  Square square1(5);
  
  cout << "square1 area: " << square1.area() << endl;
  
  // We can access the getTotal() static member function with the syntax 
  // ClassName::FunctionName() 
  cout << "total squares: " << Square::getTotal() << endl;
  
  Square square2(10);
  
  cout << "square2 area: " << square2.area() << endl;
  
  // We can also access the getTotal() static member function with any specific 
  // object instance, but using the ClassName::FunctionName() syntax is a 
  // best practice
  cout << "total squares: " << square2.getTotal() << endl;

  return 0;
}