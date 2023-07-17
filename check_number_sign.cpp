/*******************************************************************************
*
* Program: Check If A Number Is Positive, Negative Or Zero
* 
* Description: Program to check if a number is positive, negative or zero using
* C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=NEM0AM5cmco 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // Declare a double type variable to store the number.  Type double is used
  // because double variables can store numbers with decimal places.
  double number;
  
  // Prompt the user to enter the number
  cout << "Number: ";

  // Store a number entered from user input into the variable number
  cin >> number;
  
  // The condition of this first "branch" of the if-else if-else statement will
  // check if the number is positive (i.e. greater than zero), and ONLY if this
  // condition is true will the block of code immediately below it execute 
  // where we output that the number is positive (and then the program's 
  // execution will jump 'below' this entire if-else if-else structure).  If 
  // the condition is false then the else if condition will be checked.
  if (number > 0)
  {
    // Outputting "endl" will make it so any further output from the program 
    // begins on the next line of the terminal. 
    cout << "Number is positive." << endl;
  }
  // If the above condition is false, then this condition will be checked, and
  // if it is true because the number is negative (i.e. less than zero) and ONLY
  // if this condition is true will the block of code immediately below it 
  // execute where we output that the number is negative (and then the program's
  // execution will jump 'below' this entire if-else if -else structure).  If 
  // the condition is false, the else statement block of code will execute.
  else if (number < 0)
  {
    cout << "Number is negative." << endl;
  }
  // If both of the above branch's conditions are false, then this block of 
  // code will execute (as the only possibility left is that the number is 
  // zero, there is no need to "check" another condition).  Then the program's
  // execution will jump below the if-else if-else structure.
  else
  {
    cout << "Number is zero." << endl;
  }

  // below
    
  return 0;
}