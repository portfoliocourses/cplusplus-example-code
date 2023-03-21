/*******************************************************************************
*
* Program: fill() Function Examples
* 
* Description: Examples of using the fill() function in C++ to fill a range with
* a value.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rinv0JQAyDI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

// The fill() function is defined inside the algorithm library so we include it
// in order to use the function.
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  // Declare a vector to store int values, initialize 10 elements to 0.
  vector<int> items(10,0);

  // Value will store the user input value that all elements in the range will
  // be set to.
  int value = 0;
  
  // Prompt the user to enter the value and store it into the value variable.
  cout << "Enter Value: ";
  cin >> value;
  
  // Call the fill function to fill all the elements in the range with the 
  // provided value.  The first two arguments define a range from a first 
  // element to a last element, and all elements from the first element up to
  // but not including the last element will be set to the value, i.e. the
  // range to be filled is: [first, last).  The begin() member function of the
  // vector will return an iterator pointing to the first element of the 
  // vector and the end() member function will return an iterator pointing to 
  // an element one beyond the last vector element, so all vector elements 
  // will be set to the value provided as the third argument.
  //
  fill(items.begin(), items.end(), value);
  
  // Notably we can use operators + and - to alter the range, here the range 
  // will start at the element 5 deep into the vector and stop at the element 
  // 2 from the end of the vector.
  //
  // fill(items.begin() + 5, items.end() - 2, value);

  // Output the vector elements after calling the fill() function to see 
  // that the elements in the range have been set to the value provided
  for (auto item : items)
  {
    cout << item << " ";
  }
  cout << endl;

  return 0;


  // We can fill ranges of any type, including a C-style array as in the 
  // example below...
  //
  /*
  
  // Declare a C-style int array of length 10 
  int items[10];

  // Stores the value that all elements in the array will be set to
  int value = 0;
  
  // Prompt the user to enter the value to set all array elements to, store it
  // into the value variable
  cout << "Enter Value: ";
  cin >> value;
  
  // Pointer arithmetic is used to define the range as the entire array
  fill(items, items + 10, value);
  
  // Output the elements to check if they are all set to the value
  for (auto item : items)
  {
    cout << item << " ";
  }
  cout << endl;

  return 0;

  */
}
