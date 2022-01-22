/*******************************************************************************
*
* Program: Class Member Functions (aka Methods)
* 
* Description: Demonstrates the basics of using class member functions in C++,
* also known as methods.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1oOWq4rpXIg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

//define a class Rectangle
class Rectangle
{

// private members can only be accessed within the class, not outside of it
private:

  // private member variables length, width for rectangle length, width
  double length;
  double width;
  
  // Member functions can ALSO be private, we cannot access area outside 
  // the Rectangle class.  Member functions can return a value as well, 
  // as the area function will return a double value.
  double area()
  {
    return length * width;
  }
  
// the public access specifier will make these member functions available 
// outside the class (e.g. in the main function below!)
public:
  
  // member functions can accept arguments, and include default values for 
  // parameters too (here w is set to a default of 5 if it is not provided)
  void set_dimensions(double l, double w = 5)
  {
    // member functions can access and use member variables, including 
    // private member variables
    length = l;
    width = w;
  }
  
  // member functions can be defined outside of the class definition so 
  // long as we provide a declaration (aka prototype) within the class
  double perimeter();
  
  // member functions can access other member functions, including private 
  // member functions such as area
  void print_area()
  {
    cout << "Area: " << area() << endl;
  }
  
};

// We use ClassName:: to connect this function definition to our class
double Rectangle::perimeter()
{
  return 2 * (length + width);
}

int main()
{
  // create a Rectangle object instance
  Rectangle rectangle1;
  
  // use set dimensions to set its length and width members
  rectangle1.set_dimensions(10, 20);

  // use the other public member functions to output the perimeter, area 
  cout << "Perimeter: " << rectangle1.perimeter() << endl;
  rectangle1.print_area();
  
  // create another Rectangle object instance
  Rectangle rectangle2;
  
  // if we only provide one argument to set_dimensions the default value for 
  // parameter w (width) is used
  rectangle2.set_dimensions(5);
  
  // output the perimeter and area of the 2nd rectangle
  cout << "Perimeter: " << rectangle2.perimeter() << endl;
  rectangle2.print_area();
  
  return 0;
}