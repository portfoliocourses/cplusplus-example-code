/*******************************************************************************
*
* Program: Multilevel Inheritance Example
* 
* Description: Demonstration of multilevel inheritance in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=eWx6AMcNRr0  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// MenuItem is the base class of the Drink class (i.e. the "parent class", which
// makes it the "grandparent" of the HotDrink class).
class MenuItem
{
public:

  // menu items will have a name and number of calories
  string name;
  double calories;

  // member function to print the menu item member variables  
  void print()
  {
    cout << name << " (" << calories << " cal)" << endl;
  }
};

// Drink is a derived class of MenuItem AND a base class of HotDrink.  Being
// a derived class of MenuItem it will be inherit the member variables name
// and calories as well as the member function print.
class Drink : public MenuItem
{
public:

  // Drink objects will have an additional member variable, the number of 
  // ounces in the drink
  double ounces;
};

// HotDrink is a derived class of Drink, making the Drink class its "parent 
// class" and the MenuItem class its "grandparent class".  Being a derived 
// class of Drink it will inherit the member variable ounces AS WELL AS 
// the member variable name and calories, and the member function print, 
// that Drink inherited from MenuItem!
class HotDrink : public Drink
{
public:

  // hot drinks will also have a serving temperature
  double temperature;
  
  // a member function to output the serving instructions for the hot drink
  void serving_instructions()
  {
    cout << "Serve " << ounces << " ounces at "
         << temperature << " degrees F" << endl;
  }
};

int main()
{
  // create a HotDrink object instance
  HotDrink hot_chocolate;
  
  // notice how we can access all the member variables, including those 
  // inherited over multiple levels of inheritance
  hot_chocolate.name = "Hot Chocolate";
  hot_chocolate.calories = 200;
  hot_chocolate.ounces = 8;
  hot_chocolate.temperature = 77;
  
  // notice how we can call the print member function that was inherited over 
  // multiple levels of inheritance
  hot_chocolate.print();
  hot_chocolate.serving_instructions();
  
  return 0;
}

//  Visualization of Multilevel Inheritance
//
//
//      Base Class X
//           ↑
//           |
//           | - Y inherits from X
//           |
//           |
//  Derived AND Base Class Y
//           ↑
//           |
//           | - Z inherits from Y
//           |
//           |
//     Derived Class Z
//
//
//  Y is a parent class of Z, and we can think of X as a
//  "grandparent" class of Z.
