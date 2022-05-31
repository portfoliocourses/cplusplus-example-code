/*******************************************************************************
*
* Program: Defaulted Functions Example
* 
* Description: Example of using defaulted functions in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=OupyUY7FKUI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// A simple class for storing some data with a single public member value
class Data
{
public:
  
  // public member variable value
  int value;
  
  // If we define a parameterized constructor in our class, the default 
  // constructor that the C++ compiler normally includes in our class will NOT
  // be included in our class!  UNLESS we use a defaulted function as below.
  Data(int set_value)
  {
    value = set_value;
  }
  
  // We use the '= default;' specifier to create a defaulted function, in this 
  // case the default constructor.  We are telling the compiler to explicitly 
  // still include the default constructor, despite the fact that we have 
  // provided a parameterized constructor above (which would normally cause the 
  // default constructor to NOT be included in our class).
  Data() = default;
  
};

int main()
{
  // Initialize a Data object using the default constructor (with no parameter).
  // If we comment out the defaulted function: "Data() = default;" in the Data 
  // class the compiler will produce an error, because without explicitly 
  // including the default constructor with the default specifier, the default 
  // constructor will NOT be included when we have provided our own 
  // parameterized constructor!
  Data data1;
  
  // set the member variable
  data1.value = 8;
  
  // output the data object's value member variable
  cout << "data1.value = " << data1.value << endl;
  
  return 0;
}


// We can use defaulted functions to include the default versions of these 
// special member functions:
//
// Constructor
// Destructor
// Copy constructor
// Copy assignment
// Move constructor
// Move assignment