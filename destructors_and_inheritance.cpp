/*******************************************************************************
*
* Program: Destructors And Inheritance Example
* 
* Description: Example of how destructors work with inheritance in C++ when we 
* have a base class and a derived class.
*
* YouTube Lesson: https://www.youtube.com/watch?v=jOnVin6eHV8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A simple base class
class BaseClass
{
public:
  
  // base class constructor
  BaseClass()
  {
    cout << "BaseClass constructor executing" << endl;
  }
 
  // base class destructor
  ~BaseClass()
  {
    cout << "BaseClass destructor executing" << endl;
  }
  
};

// a simple derived class that inherits from the above base class
class DerivedClass : public BaseClass
{
public:
  
  // derived class constructor
  DerivedClass()
  {
    cout << "DerivedClass constructor executing" << endl;
  }
  
  //derived class destructor
  ~DerivedClass()
  {
    cout << "DerivedClass destructor executing" << endl;
  }
};

void func()
{
  // The derived class will be constructed at this point when we declare example
  //
  // In the case of constructors in a derived class, first the base class 
  // constructor will run and THEN the derived class constructor will run.
  //
  DerivedClass example;
  
  // output and endline to separate the constructor/destructor output
  cout << endl;

  // When the function returns the example object will be destroyed. 
  //
  // In the case of destructors, first the derived class destructor will run 
  // and THEN the base class destructor will run...  the opposite order of 
  // the constructors!
}

int main()
{
  // call the function func so we can create and destroy a DerivedClass object
  // instance to explore how destructors work
  func();
  
  // output an endline to separate any output from the above function with any 
  // end of program output
  cout << endl;
  
  return 0;
}