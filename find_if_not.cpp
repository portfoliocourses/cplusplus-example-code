/*******************************************************************************
*
* Program: find_if_not() Function
* 
* Description: Example of using the find_if_not() function in C++ to find the 
* first element in a range for which a condition is not true.  More accurately, 
* the first element in a range for which a unary predicate (function) returns 
* false.
*
* YouTube Lesson: https://www.youtube.com/watch?v=3iCyLZHSftQ 
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
  // Declare a vector to store ints and initialize it with integers, notably
  // the first non-even integer is 7
  vector<int> data = {2,4,6,7,8,10};
  
  // find_if_not() will check the elements in the range of data.begin() up until
  // but not including data.end() to find the first element which returns false
  // when passed to isEven.  The function will return an iterator pointing to
  // that element, which we store into it.  The function will return the 2nd 
  // argument defining the end of the range if the function isEven returns 
  // true for all elements in the range.  
  //
  // data.begin() and data.end() are iterators, with data.begin() pointing 
  // to the first element in the vector, and data.end() pointing to the 
  // "theoretical" element one beyond the last element in the vector.
  //
  // We call the third argument a unary predicate, which is a function which
  // accepts a single element as an argument and returns a boolean value.
  //
  auto it = find_if_not(data.begin(), data.end(), isEven);
   
  // If find_if() returned data.end() then no non-even value was found   
  if (it == data.end())
  {
    cout << "No even value found in vector." << endl;
  }
  // Otherwise a non-even value was found, and we dereference the pointer to 
  // that element to output the value  
  else
  {
    cout << "1st non-even (odd) value: " << *it << endl;
  }
    
  return 0;
}