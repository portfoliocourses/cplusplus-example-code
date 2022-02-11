/*******************************************************************************
*
* Program: Constructor Delegation
* 
* Description: Example of using constructor delegation in C++ to have one
* constructor call another constructor in the same class, which helps to reduce
* code duplication.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rHXPFxaOIfo  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

class Rectangle
{
public:
  int length;
  int width;
  int area;
  string color;
  
  // This constructor initializes the length and width member variables, and 
  // computes and initializes the area member variable, it does not initialize 
  // color which will then be left as an empty string (which may be OK, 
  // perhaps it is optional).
  Rectangle(int l, int w)
  {
    length = l;
    width = w;
    area = length * width;
    cout << "Constructor 1" << endl;
  }
  
  // This constructor uses constructor delegation to call the above constructor 
  // with the l and w values it was provided, and it counts on that constructor 
  // to initialize the length, width and area member variables.  After this 
  // constructor function call is complete, this constructor's code will 
  // execute, and it initializes the color member variable.  This reduces code 
  // duplication, as otherwise this constructor would need to initialize these 
  // member variables as well, and it would repeat the exact same code to do so!
  Rectangle(int l, int w, string c) : Rectangle(l,w)
  {
    color = c;
    cout << "Constructor 2" << endl;
  }
  
  // out the Rectangle object's relevant information
  void print()
  {
    cout << "length: " << length << endl;
    cout << "width: " << width << endl;
    cout << "area: " << area << endl;
    cout << "color: " << color << endl;
  }
  
};

int main()
{
  // When we use the constructor with 3 arguments to create a Rectangle object,
  // notice how "Constructor 1" first outputs followed by "Constructor 2", this 
  // is because of constructor delegation!  The constructor that accepts 3 
  // arguments FIRST calles the constructor that only accepts 2 arguments, and 
  // THEN it executes its own code.  
  Rectangle rectangle1(5, 10, "red");
  
  rectangle1.print();
  
  return 0;
}