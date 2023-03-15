/*******************************************************************************
*
* Program: count_if() Standard Library Function Examples
* 
* Description: Examples of using the count_if() standard libary function in C++.
* The count_if() function allows us to check how many elements in a range 
* satisfy a condition.  It accepts a range and function as arguments, and 
* returns how many times the function returns true when called with each 
* element in the range.
*
* YouTube Lesson: https://www.youtube.com/watch?v=sfeTeqmW3eQ
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

// count_if() is defined inside of algorithm so we include the library
#include <algorithm>
#include <vector>

using namespace std;

// Returns true if the int is passed is even and false otherwise
bool isEven(int n)
{
  return (n % 2 == 0);
}

int main()
{ 
  // Declare and initialize a vector that has 5 even numbers
  vector<int> test {2,4,6,8,1,3};

  // Call count_if() to count the number of elements for which the isEven 
  // function will return true when each element is passed to isEven as 
  // an argument.  The calls to test.being() and test.end() return 
  // iterators that define the start and end of the range.
  int evenCount = count_if(test.begin(), test.end(), isEven);
  
  // Output the number of even numbers in the vector
  cout << "Even Numbers: " << evenCount << endl;
  
  // count_if() will work with all types of ranges, such as C-style arrays as 
  // declared and initialized below.
  int array[] = {1,2,3,4,5,6,7,8,9,10};
  
  // Call count_if() with isEven() again to count the number of even integers
  // in array.
  //
  // We pass array and "array+10" to specify the range in which to count the 
  // occurrences of 2.  Technically array is a pointer to the first element in
  // the array and array+10 is a pointer to an element 10 elements ahead of 
  // this first element (i.e. one past the actual last element in the array 
  // where X is above).  The count_if function will call isEven on elements 
  // in the range...
  //
  // [start, end)
  //
  // In other words, it will count up until but not included the end that 
  // we specify.  The start and end arguments that specify the range are 
  // iterators, but in C++ pointers are iterators.
  //
  int evenArrayCount = count_if(array, array + 10, isEven);
  
  // Output the number of even numbers in the array
  cout << "Array Even Numbers: " << evenArrayCount << endl;
  
  return 0;
}