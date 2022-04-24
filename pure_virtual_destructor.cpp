/*******************************************************************************
*
* Program: Pure Virtual Destructor Example
* 
* Description: Example of how to use a pure virtual destructor in C++.  We 
* would use a pure virtual destructor when we want a class to be abstract BUT 
* we also don't want any of the other member functions to be pure virtual 
* member functions (perhaps so derived classes can optionally inherit and use 
* these member function implementations).
*
* YouTube Lesson: https://www.youtube.com/watch?v=76FlItOH8cE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// Base is an abstract class due to the pure virtual destructor, so we can't 
// create object instances of type Base
class Base
{
public:

  // All the other member functions are NOT pure virtiual functions, in this 
  // case just the function func(), despite the fact that it is an abstract 
  // class due to the pure virtual destructor.  This is a virtual member 
  // function so when derived classes overide this member function we will 
  // have dynamic binding / runtime polymorphism behaviour.
  virtual void func()
  {
    cout << "Base func()" << endl;
  }
  
  // Make the destructor a pure virtual destructor
  virtual ~Base() = 0;
};

// While it's possible to provide an implementation for all pure virtual member
// functions this is typically not done.  In the case of a virtual destructor 
// we *must* supply an implementation of the function (otherwise our code 
// below to delete object instances of derived types will fail when an attempt 
// is made to call the base class destructor).  We provide a simple definition 
// of the destructor below, we might normally do something like free dynamically
// allocated memory in a destructor to prevent a memory leak.
Base::~Base()
{
  cout << "Base Destructor" << endl;
}

// Derived1 is a derived class of Base, it is a concrete class so we can create
// object instaces of type Derived1
class Derived1 : public Base
{
public:

  // We overide func() 
  void func()
  {
    cout << "Derived1 overriding func()" << endl;
  }

  // Typically with pure virtual functions if the derived class does not provide
  // an implementation of all pure virtual functions in the base class then the 
  // derived class will ALSO be an abstract class.  But in the case of a pure 
  // virtual destructor the default destructor C++ provides to all objects will
  // be provided as an implementation of the destructor, and so despite the fact
  // that we do not explicitly provide an implementation of the destructor 
  // ourselves Derived1 will be a concrete class and not an abstract class.
  
};

// Derived2 is a derived class of Base, and is also a concrete class
class Derived2 : public Base
{
public:
  
  // We don't override func1() in Derived2, so Derived2 will use func1() as it 
  // is defined in the Base class (and inherited from Base).  

  // We provide an implementation of the destructor... because the Base class
  // destructor is virtual when an object of type Derived2 is deleted we can 
  // expect the Derived2 destructor to be called followed by the Base class 
  // destructor.
  ~Derived2()
  {
    cout << "Derived2 Destructor" << endl;
  }
};

int main()
{
  // Despite the fact that all member functions aside from the destructor 
  // are NOT pure virtual member functions, because the destructor IS a pure 
  // virtual destructor, Base is an abstract class!
  ///
  // So we cannot create an instance of the Base class as below:
  // 
  // Base base;
  
  // We can use Base as a pointer type, here we create an array of pointers of 
  // type Base to Derived1 and Derived2 object instances on the heap
  Base *array[] =
  {
    new Derived1(),
    new Derived2()
  };
  
  // We use dynamic binding / runtime polymorphism to work with the objects, 
  // calling the func() member function of each object.  In the case of 
  // the Derived1 object the overridden func1() will be called, in the case 
  // of the Derived2 object the func1() defined in the Base class will be 
  // called instead.  
  for (int i = 0; i < 2; i++)
    array[i]->func();
  
  // When we delete the object instances, in the case of the Derived1 object 
  // the "default destructor" is called before the Base class destructor 
  // and so we only see output from the Base class destructor (the default 
  // destructor does not have default output).  In the case of the Derived2 
  // object the Derived2 destructor is called followed by the Base class 
  // destructor.
  for (int i = 0; i < 2; i++)
    delete array[i];


  // So we have an abstract class Base, and yet aside from the destructor none 
  // of the member functions are pure virtual member functions, and the 
  // derived classes can use these implementations by not overriding them.
  //
  // Normally when we have an abstract class it's because we have a pure 
  // virtual member function that is not the destructor, and if our derived 
  // classes do not override all the pure virtual member functions they will 
  // become abstract classes themselves.  Here our derived classes are still 
  // concrete classes whether they overide the destructor or not, and they 
  // can utilize the implementation of the member function(s) in the base class.
  
  return 0;
}
