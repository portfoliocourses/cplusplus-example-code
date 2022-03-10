/*******************************************************************************
*
* Program: Inheritance Demonstration
* 
* Description: A basic demonstration of how to use inheritance in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rJlJ8qqVm3k 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// MenuItem is a "Base Class" or what we could also call a "Parent Class", it 
// contains a few simple member variables and a member function for printing 
// them out.
class MenuItem
{
public:
  string name;
  double calories;
  
  void print()
  {
    cout << name << " (" << calories << " cal)" << endl;
  }
};

// We want our Drink class to "have and do" everything that a MenuItem class 
// can do... we could copy and paste the code from MenuItem into the Drink 
// class, but then we would have duplicate code (a "code clone" we can call 
// it).  The problem with duplicate code is that it becomes harder to maintain,
// if we need to make a change we would need to make it in two places!
//
// So instead we us : public MenuItem to make Drink a "Derived Class" off the 
// the MenuItem class (also called a "Child Class").  The Drink class will be 
// given the member variables and member functions of its base class MenuItem,
// i.e. our Drink objects will have public member variables name, calories,
// and the print function too!
//
// We can still define in the Drink class new member variables, like ounces,
// and new member functions, like cal_per_ounce.
//
class Drink : public MenuItem
{
public:
  double ounces;
  
  double cal_per_ounce()
  {
    return calories / ounces;
  }
};

int main()
{
  // instantiate and use a MenuItem object
  MenuItem french_fries;
  french_fries.name = "French Fries";
  french_fries.calories = 400;
  french_fries.print();

  
  // We can also instantiate and use a Drink object, using the same name
  // and calories member variables, and the same print member function, in 
  // addition to the new member variable calories and the new member function
  // cal_per_ounce().
  //
  Drink hot_chocolate;
  hot_chocolate.name = "Hot Chocolate";
  hot_chocolate.calories = 300;
  hot_chocolate.ounces = 8;

  hot_chocolate.print();
  cout << "cal/ounce: " << hot_chocolate.cal_per_ounce()
       << endl;
  

  // We can use a derived class anywhere a base class can be used and it will 
  // work!  This is a feature of polymorphism, another concept that allows 
  // inheritance to help us write better code.  We describe the relationship 
  // between Drink and MenuItem as an "is a" relationship, in that a Drink 
  // object "is a" MenuItem object.  A Drink object can be used anywhere that a 
  // Menu item object can, in the sense that a Drink object has the same member
  // variables and same member functions available.
  //
  // Here we make a pointer to an MenuItem variable, and we assign it the 
  // memory address of the hot_chocolate Drink object instance.  This seems odd
  // but polymorphism will allow for this, and we can even call the drink 
  // member function via the pointer, and it's OK.  What makes this work is that
  // we *know* a Drink object will have a print object by virtue of it being 
  // a MenuItem too.
  //
  MenuItem *ptr;
  ptr = &hot_chocolate;  
  ptr->print();
  
  return 0;
}