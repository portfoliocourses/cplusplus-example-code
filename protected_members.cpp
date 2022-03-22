/*******************************************************************************
*
* Program: Protected Class Members
* 
* Description: Demonstration of how the protected access specifier works with 
* class members in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=jFtvOnkf9Dw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A base class with public, private and protected member variables
class BaseClass
{
public:
  int _public_member;
  
private:
  int _private_member;
  
protected:
  int _protected_member;
};

// A derived class that inherits from the base class
class DerivedClass : public BaseClass
{
public:
  
  void member_function()
  {
    // the derived class can access public members of the base class, just like
    // the rest of the program
    _public_member = 10;

    // the derived class CANNOT access private members of the base class, just
    // like the rest of the program (the below statement will cause a compiler
    // error if uncommented)
    // _private_member = 20;

    // but the derived class CAN access protected members of the base class, 
    // unlike the rest of the program that does not have access
    _protected_member = 30;
    
    // output the values that were just set
    cout << "_public_member: " << _public_member << endl;
    cout << "_protected_member: " << _protected_member << endl;
    // cout << "_private_member: " << _private_member << endl;
  }
};

// here we define AnotherClass that inherits from the DerivedClass above
class AnotherClass : public DerivedClass
{
public:
  void new_function()
  {
    // the DerivedClass above will inherit the protected member AS a protected 
    // member when the public access specifier is used to inherit from the 
    // Class, i.e.: class DerivedClass : public BaseClass, 
    // so when we inherit the DerivedClass here in Another class, also using 
    // the public access specifier, we can again access the protected member
    _protected_member = 20;
  }
};

int main()
{
  BaseClass base;

  // the rest of the program can access a base class public member  
  base._public_member = 10;

  // the rest of the program CANNOT access a base class private member
  // base._private_member = 20;
  
  // the rest of the program ALSO cannot access a base class protected member,
  // only a derived class can
  // base._protected_member = 30;

  DerivedClass derived;
  
  // test our function to ensure we're really accessing the protected member
  derived.member_function();

  return 0;
}
