/*******************************************************************************
*
* Program: Abstract Class With Pure Virtual Function Example
* 
* Description: Example of how to use a pure virtual function to create an 
* abstract class in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wE0_F4LpGVc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// Shape is a base class for Square and Triangle, and we want to be able to 
// use polymorphism to work with arrays of pointers to Square, Triangle and 
// other object instances so that we can execute member functions like 
// area() to calculate the area of shapes.  The problem is that there is NO 
// "generic shape area", the area calculation is really only defined for 
// specific types of shapes.  So instead we create a pure virtual function 
// area() in our base class shape, which makes the Shape class an abstract 
// class (having 1 or more pure virtual member function makes any class a 
// an abstrac class).  We then leave it to Square, Triangle and any other 
// derived class to override the area member function (if they do not, they 
// will also become abstract classes).  Notably, we cannot create an instance
// of an abstract class like Shape, but we CAN have pointers and references 
// of the type of an abstract class.
//
class Shape
{
public:

  // The virtual keyword will make the area() function a virtual function that 
  // allows for dynamic binding (i.e. runtime polymorphism).  The = 0 assignment
  // will make it a pure virtual function, and makes Shape an abstract class.
  virtual double area() = 0;
};

// Square inherits from Shape, and overrides the area pure virtual function. 
// Because Square overrides all of the pure virtual functions of its base 
// class, we can create Square object instances, and we would call Square 
// a concrete class.
class Square : public Shape
{
public:
  double side;
  
  Square(double side) : side(side) {}
  
  double area()
  {
    return side * side;
  }
};

// Triangle also inherits from Shape, and also overrides the area pure virtual
// function with a calculation that works for triangles.
class Triangle : public Shape
{
public:
  double base;
  double height;
  
  Triangle(double base, double height) :
    base(base), height(height) {}
  
  double area()
  {
    return 0.5 * base * height;
  }
};

int main()
{
  // We *cannot* make a Shape object instance because it is an abstract class.
  // So the below code will cause a compiler error if we uncomment it.
  //
  // Shape shape;

  // We CAN create pointers and references of the type of an abstract class,
  // allowing us to create an array of pointers to object instances of 
  // derived classes of Shape.
  Shape *shapes[] =
  {
    new Square(5),
    new Triangle(8,10),
    new Square(7),
    new Triangle(3,4)
  };
  
  // Because we have an array of pointers to Shapes, which support dynamic 
  // binding of the area() member function, we can use runtime polymorphism 
  // to loop through our array of pointers to Shapes and call the area 
  // member function for each object!  This allows us to utilize polymorphism,
  // BUT without implementing a "generic Shape" area member function that 
  // would not make any sense.
  //
  for (int i = 0; i < 4; i++)
    cout << "Shape " << i << ": " << shapes[i]->area() << endl;
   
  return 0;
}