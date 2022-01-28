/*******************************************************************************
*
* Program: Destructor Basics
* 
* Description: Demonstrates the basics of using destructor functions in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=abOMO8GY6io 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// a simple "Number" class
class Number
{
  
// the class has one private member variable, a pointer to a double
private:
  double *number;
  
public:
  
  // the constructor
  Number(double num)
  {
    // allocate space for a double value, have the private member variable 
    // number pointo that space 
    number = (double *) malloc(sizeof(double));

    // dereference the pointer, store the value num at the allocated space
    *number = num;

    // output statements to trace execution of when the constructor is called
    cout << "Constructor executing!" << endl;
    cout << "Number: " << *number << endl << endl;
  }
  
  // Destructor function runs when the object is destroyed, and is generally 
  // used to do clean up work such as making free dynamically allocated memory.
  // We put a ~ symbol in front of the class name to define the destructor, and 
  // destructors cannot have parameters.
  ~Number()
  {
    // output statements to trace execution of when the destructor is called
    cout << "Destructor executing!" << endl;
    cout << "Number: " << *number << endl << endl;

    // free the dynamically allocated memory to make it available again and 
    // prevent a memory leak
    free(number);
  }
  
};

// very basic function that creates a Number object locally
void test()
{
  // Number object is created here, and destroyed when the function completes 
  // execution... at this point the destructor is called but it is implicit 
  // in the sense that we don't write any statement to explicitly invoke it
  Number six(6);
}

int main()
{
  // when we create an object on the heap with dynamically allocated memory
  // using 'new', the constructor will be called
  Number *five = new Number(5);

  // when we use delete to destroy the object and free the memory, the 
  // destructor will then be called, and in this sense we are more explicitly 
  // "calling" the destructor 
  delete five;

  // call the test function, which will cause an object to be created and 
  // destroyed when the function completes execution
  test();
  
  // we create an object that will be destroyed when the program terminates, 
  // calling the destructor at that time
  Number seven(7);

  return 0;
}