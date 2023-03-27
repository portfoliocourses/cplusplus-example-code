/*******************************************************************************
*
* Program: Exception Handling Examples
* 
* Description: Examples of using exception handling in C++.  Exception handling
* allows us to handle unwanted or unexpected events by throwing exceptions to 
* interrupt regular execution and jump to a catch block to handle the exception.
*
* YouTube Lesson: https://www.youtube.com/watch?v=5nCXSDv6e4I 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// We can create our own custom types of exceptions and throw and catch them, 
// here were create a derived class of the exception class
class custom_exception : public exception
{
  // define our own what method to provide a custom string message
  virtual const char* what() const noexcept
  {
    return "Custom Exception";
  }
};

// Functions we define can throw exceptions.  If an exception is thrown inside
// a function called by another function that we call (and so on in a series
// of function calls), the exception will "propogate upwards" through the 
// chain of calls until the closest catch block is able to catch it. 
void myfunction2()
{
  throw 5.6;
}

// Calls a function which throws an exception.  
void myfunction1()
{
  myfunction2();
}

int main()
{
  // string with only 4 characters
  string word = "four";
  
  // A try block will essentially "listen" for exceptions and allow us to 
  // catch and handle the exception with a catch block.  Together we call 
  // the blocks a try-catch block.
  try
  {
    // if we try to access the 5th character in the sting an out_of_rnage
    // exception will be thrown
    // cout << word.at(4) << endl;

    // if we try to allocate an int array this large a bad_alloc exception
    // will be thrown
    // int *array = new int[9999999999999999];   
    
    // we can throw our own custom exceptions
    // throw custom_exception();

    // we don't need to throw an exception-type object, we can throw any 
    // value such as an int or a double
    // throw 20;
    // throw 5.6;
    
    // If we call a function that either throws an exception or calls a 
    // function which throws an exception (and so on through a series of
    // function calls), then we can catch the exception.
    myfunction1();
  }
  // Catch block that will match and handle out_of_range exception.  The 
  // object e represents the exception, and the what() method may provie
  // additional information about the exception.
  catch (out_of_range& e)
  {
    cout << "First Catch: " << e.what() << endl;
  }
  // We can have multiple catch blocks, and the first catch block to match from
  // top to bottom is the catch block that will execute.  Here we catch a 
  // bad_alloc type exception.
  catch (bad_alloc& e)
  {
    cout << "Second Catch: " << e.what() << endl;
  }
  // The exception type is the most general exception-type object, the base
  // class of an inheritance hierarchy of exception-type objects.  
  // See: https://en.cppreference.com/w/cpp/error/exception
  // Because exceptions like bad_alloc are ALSO of type 'exception' if this 
  // catch block were first, those exceptions would be caught by this 
  // catch block!  So we need to be mindful of this when ordering our 
  // catch blocks.
  catch (exception& e)
  {
    cout << "Exception Caught: " << e.what() << endl;
  }
  // We can throw and catch any type of value, for example here we catch 
  // an int.
  catch (int code)
  {
    cout << "Error Code: " << code << endl;
  }
  // The ... is a special "catch all" catch block case that allows to catch
  // ANY type of exception.
  catch (...)
  {
    cout << "Default catch case!" << endl;
  }

  return 0;
}