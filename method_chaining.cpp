/*******************************************************************************
*
* Program: Method Chaining Example
* 
* Description: Example of implementing method chaining in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=61coy8tNgWM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// Basic Rectangle class, but with setter methods that allow for method chaining
class Rectangle
{
public:
  
  // rectangles will have length, width and color member variables
  int length;
  int width;
  string color;
  
  // a standard constructor for initializing the member variables
  Rectangle(int set_length, int set_width, string set_color)
  {
    length = set_length;
    width = set_width;
    color = set_color;
  }
  
  // a standard function for printing out member variable values
  void print()
  {
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Color: " << color << endl;
  }
  
  // A setter method that sets the color member variable to the value provided
  // as an argument, BUT the method ALSO returns a reference to the object 
  // instance for which it was called, allowing for method chaining.
  Rectangle& setColor(string set_color)
  {
    // set the member variable
    color = set_color;

    // this is a pointer to the object instance for which this method is 
    // executing, and when we dereference the pointer with * we return a 
    // reference to the object instance itself
    return *this;
  }
  
  // same as above, except for length member variable
  Rectangle& setLength(int set_length)
  {
    length = set_length;
    return *this;
  }
  
  // same as above, except for width member variable
  Rectangle& setWidth(int set_width)
  {
    width = set_width;
    return *this;
  }
  
};

int main()
{
  // Create a rectangle object 
  Rectangle rectangle1(4,5,"red");
  
  // Use method chaining with the setter methods
  //
  // When we call:
  //    rectangle1.setColor("orange")
  //
  // What is returned is a reference to rectangle1, and so then when we run 
  // .setLength(10) on this, it's effectively like running:
  //
  // rectangle1.setLength(10)
  //
  // (after having run rectangle1.setColor("orange"))
  //
  // And so on with setWidth(2).
  //
  rectangle1.setColor("orange").setLength(10).setWidth(2);
  
  // print the rectnagle so we can see the affect of the setter methods
  rectangle1.print();
  
  return 0;
}

// Let's say we have an object...
//
// ObjectType object1;
//
//
// We can call methods like this...
//
// object1.method1();
// object1.method2();
// object1.method3();
//
// - But we repeat object1 three times
//
//
// Method Chaining:
//
// object1.method1().method2().method3();
//
// - object1 is no longer repeated
// - We can read from left to right
//
//
// It's a debate whether method chaining is worth it or not,
// I will post a link to an interesting paper on the subject.
//
// Paper: "An Empirical Study of Method Chaining in Java"
//
// Link: https://static.csg.ci.i.u-tokyo.ac.jp/papers/20/nakamaru-msr2020.pdf
//
// It seems to be useful in situations where we have chains
// of methods that act on an object, e.g. setter methods.
//
// It is used extensively in jQuery, a very popular
// JavaScript library.
//
