/*******************************************************************************
*
* Program: find_if() Function
* 
* Description: Example of using the find_if() function in C++ to find the first
* element in a range that matches a condition.  More accurately, the first 
* element in a range for which a unary predicate (function) returns true.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1AitPnSLaEk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Returns true if n is even and false otherwise
bool isEven(int n)
{
  // An even number will have a remainder of 0 when divided by 2, so we return
  // true when this is the case, and false otherwise.  The modulus operator %
  // gives us the remainder of n divided by 2.
  return (n % 2) == 0;
}

int main()
{
  // Declare a vector to store int values called data
  vector<int> data;
  
  // Insert values into the vector
  data.push_back(3);
  data.push_back(8);
  data.push_back(7);
  data.push_back(9);
   
  // find_if() will check the elements in the range of data.begin() up until 
  // but not including data.end() to find the first element which returns true
  // when passed to isEven.  The function will return an iterator pointing to
  // that element, which we store into it.  The function will return the 2nd 
  // argument defining the end of the range if the function isEven returns 
  // false for all elements in the range.  
  //
  // data.begin() and data.end() are iterators, with data.begin() pointing 
  // to the first element in the vector, and data.end() pointing to the 
  // "theoretical" element one beyond the last element in the vector.
  //
  // We call the third argument a unary predicate, which is a function which
  // accepts a single element as an argument and returns a boolean value.
  //
  auto it = find_if(data.begin(), data.end(), isEven);
   
  // If find_if() returned data.end() then no even value was found in the vector
  if (it == data.end())
  {
    cout << "No even value found in vector." << endl;
  }
  // Otherwise an even value was found, and we dereference the pointer to that 
  // element to output the value
  else
  {
    cout << "First even value in vector: " << *it << endl;
  }
  
  return 0;
}