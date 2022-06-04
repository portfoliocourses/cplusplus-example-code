/*******************************************************************************
*
* Program: Singleton Design Pattern
* 
* Description: Example implementation of the Singleton Design Pattern in C++.
* This implementation is thread-safe and uses lazy instantiation. For more 
* information Singletons see: https://en.wikipedia.org/wiki/Singleton_pattern.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wP3glUDGhi8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// The Singleton class
class Singleton
{

// We make the constructor a protected member so that Singleton objects cannot
// be constructed from outside the class, to help enforce that only one 
// Singleton object should ever be instantiated.  We use the default specifier 
// to have the compiler-produced default constructor used for our class.
protected:
  Singleton() = default;
  
public:
  
  // We'll give our Singleton object a member variable to help test it out
  int data;
  
  // The static member function get_instance will be responsible for creating 
  // and allowing access to the one Singleton object instance.  Being a static 
  // member function the function is really connected to the Singleton class 
  // rather than any Singleton object instance, so we don't need a Singleton 
  // object instance to exist in order to use it!  The function uses a local 
  // static variable to create a Singleton object instance.  When the function 
  // is first called the Singleton object instance will be created, but 
  // because it's a STATIC local variable the lifetime of that Singleton 
  // object instance will be until the program completes execution.  The 
  // function will return a reference to this Singleton instance.  So the first
  // time the function is called the instance is created and returned, but then 
  // on all subsequent function calls the SAME instance will be returned! 
  //
  // This approach to managing the creation of a single Singleton object 
  // instance has a coupe advantages.  Static local variables are thread-safe 
  // as of C++11, which means multiple threads can use the Singleton without 
  // the danger of multiple Singleton object instances being created as we 
  // may have with some other approaches to implementing the Singleton 
  // design pattern.  And because it's a static local variable, the Singleton 
  // object instance will not be instantiated UNTIL the function is called. 
  // So if our program NEVER calls get_instance (say because it doesn't need the
  // Singleton), then the Singleton object is NEVER created.  This can be a good
  // property to have because resources like memory will not be used unless they
  // are needed.  We call this property 'lazy instantiation' and its in contrast
  // to 'eager instantiation' where the Singleton object instance is created 
  // in advance.
  static Singleton& get_instance()
  {
    static Singleton instance;
    return instance;
  }
  
  // C++ classes are provided with some special member functions by default such
  // as the copy constructor, move constructor, copy assignment operator, and 
  // move assignment operator.  These member functions would allow for the 
  // creation of additional Singleton object instances if they were to be used,
  // so we use the delete specifier to turn them into deleted functions, i.e. 
  // functions that we explicitly tell the compiler NOT to provide our class.  
  // This way if programmers use our class attempt to use any of these member 
  // functions, a compiler error will result, making our implementation less 
  // error prone and more robust.
  Singleton(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;
  
};

int main()
{
  // Because the Singleton constructor is protected, attempting to instantiate
  // a Singleton object outside of the class will result in an error.  Try 
  // uncommenting the below line to see the error.
  //
  // Singleton bad_singleton;
  
  // Use get_instance() to obtain the reference to the Singleton object 
  // instance, because this is the first time get_instance() is used we know 
  // the Singleton object instance is also being created at this point.
  Singleton &singleton1 = Singleton::get_instance();
  
  // singleton1 is a reference to the Singleton object instance, and we can use
  // this reference to set the data member variable
  singleton1.data = 20;
  
  // We can also use the singleton1 reference to output the data member variable
  // of this Singleton object instance
  cout << "singleton1.data = " << singleton1.data << endl;
  
  // If we make another reference to the Singleton object instance by calling 
  // get_instance() again, it will be a reference to the SAME Singleton object.
  // As this is the second time we call get_instance() we know that the 
  // Singleton object instance will have already been created, and now a 
  // reference to that object is being returned.
  Singleton &singleton2 = Singleton::get_instance();
  
  // If we use singleton2 to access and output the data member variable we will
  // again get the value 20 because singleton2 is a reference to the SAME single
  // Singleton object instance in memory.
  cout << "singleton2.data = " << singleton2.data << endl;
  
  // We don't really need to create a reference variable to access the Singleton
  // object, as get_instance() returns a reference we could use the reference 
  // directly as below to access the data member variable...
  Singleton::get_instance().data = 50;
  
  // We again use the reference returned from get_instance() to access the 
  // Singleton object instance and the data member variable, this time to print 
  // it out...
  cout << "data: " << Singleton::get_instance().data << endl;
  
  // And again we'll see if we use the singleton1 or singleton2 references to 
  // access the Singleton object instance that the data member variable will 
  // have the same value because they are both *references* to the *same* 
  // Singleton object instance.
  cout << "singleton1.data = " << singleton1.data << endl;
  cout << "singleton2.data = " << singleton2.data << endl;
  
  // Had we not turned the copy constructor into a deleted function, then the 
  // below code would result in the copy constructor producing a new Singleton 
  // object instance... now instead we'll get a compiler error if we uncomment
  // this code.  We want that compiler error to occur because it prevents a 
  // programmer from incorrectly creating an additional Singleton object 
  // instance (or *mistakenly*, if they forgot the & when trying to make a 
  // reference variable).
  //
  // Singleton singletonN = singleton1;
  
  // If the copy constructor is NOT a deleted function and we CAN use the above
  // statement, a new Singleton object instance will be created.  We can observe
  // this is the case by setting the data member variable of SingletonN, and 
  // noticing it will be a different value then the data member variable for 
  // the Singleton object instance that singleton1 is a reference to. 
  //
  // singletonN.data = 100;
  // cout << "singleton1.data = " << singleton1.data << endl;
  // cout << "singletonN.data = " << singletonN.data << endl;
  
  return 0;
}
