/*******************************************************************************
*
* Program: Base Class Access Specifier Examples
* 
* Description: Demonstration of how the base class access specifier works with
* inheritance in C++.  The base class access specifier works in conjunction 
* with the base class member access specifiers to determine the access 
* specification of the members in the derived class, in this code we go over 
* the different combinations with examples.
*
* YouTube Lesson: https://www.youtube.com/watch?v=eFoHKBCRbKQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/


//  This table shows which access specifier will result in the derived class for 
//  which combination of base class access specifier and member access specifier
//  in the base class.
// 
//
//                    *              Member Access Level
//  Base Class        *
//  Access Specifier  *   Private          Protected       Public
//  *****************************************************************
//                    *
//  Public            *   Inaccessible     Protected       Public
//                    *
//  Protected         *   Inaccessible     Protected       Protected
//                    *
//  Private           *   Inaccessible     Private         Private
//
//
//  The base class access specifier will affect how members are inherited by the
//  derived class.  For example, when using the proteted acces specifier when 
//  inheriting the base class, the public members of the base class will become 
//  protected members of the derived class.  Generally, we use the public 
//  specifier. Notably, if no access specifier is provided the default is 
//  private.
//

#include <iostream>

using namespace std;

// A simple BaseClass with public, protected and private members
class BaseClass
{
public:
  int _public_member;
  
protected:
  int _protected_member;
  
private:
  int _private_member;
};

// A derived class using the PUBLIC base class access specifier
class DerivedClass1 : public BaseClass
{
public:
  void member()
  {
    // private members of the base class will be inaccessible in the derived 
    // class
    // _private_member = 20;
    
    // protected members of the base class will become protected members of 
    // the derived class and thus accessible in the derived class
    _protected_member = 30;
    
    // public members of the base class will become public members of the 
    // derived class
    _public_member = 10;
  }
};

// A derived class using the PROTECTED base class access specifier
class DerivedClass2 : protected BaseClass
{
public:
  void member()
  {
    // private members of the base class will become inaccessible in the derived
    // class
    // _private_member = 30;
  
    // protected members of the base class will become protected members in the 
    // derived class
    _protected_member = 20;

    // public members of the base class will ALSO become protected members in 
    // the derived class    
    _public_member = 10;
  }
};

// A derived class using the PRIVATE base class access specifier
class DerivedClass3 : private BaseClass
{
public:
  void member()
  {
    // private members of the base class will become inaccessible in the derived
    // class    
    // _private_member = 30;

    // both protected and public members of the base class will become private 
    // members in the derived class 
    _protected_member = 10;
    _public_member = 20;
  }
};

// If we make a derived class of DerivedClass3, we find that we cannot access 
// _protected_member and _public_member because they were both made private 
// members of DerivedClass3 when it inherited them from BaseClass using the 
// private base class access specifier!
class NextLevel : public DerivedClass3
{
public:
  void member()
  {
    // _protected_member = 20;
    
    // _public_member = 30;
  }
};


int main()
{
  // create an instance of DerivedClass1 to confirm the usual behaviours of 
  // the members variables based on their access specification
  DerivedClass1 derived1;
  
  // we can't access the protected member outside of the class, as is the usual 
  // case with a protected member
  //
  // derived1._protected_member = 30;
  
  // we can access a public member outside the class, as is the usual case with 
  // a public member
  derived1._public_member = 10;
  
  // create an instance of DerivedClass2 to confirm the usual behaviours of 
  // the members variables based on their access specification  
  DerivedClass2 derived2;
  
  // we can't access the protected member outside of the class, as is the usual 
  // case with a protected member
  //
  // derived2._protected_member = 30;
  
  // _public_member has now been turned into a protected member in DerivedClass2
  // because we used the protected base class access specifier, and so we can 
  // no longer access it outside DerivedClass2
  //
  // derived2._public_member = 30;
  
  // create an instance of DerivedClass3 to confirm the usual behaviours of 
  // the members variables based on their access specification    
  DerivedClass3 derived3;
  
  // We cannot access _public_member or _protected_member because when we used 
  // the private base class access specifier when inheriting BaseClass it gave 
  // both these variabales a private access specification.
  //
  // derived3._public_member = 20;
  // derived3._protected_member = 30;
  
  return 0;
}

