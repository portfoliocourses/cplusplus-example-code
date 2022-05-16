/*******************************************************************************
*
* Program: unique() Function Example
* 
* Description: Example of using the unique function in C++ to remove consecutive
* duplicates in a range.
*
* YouTube Lesson: https://www.youtube.com/watch?v=-MxLIBhMI0o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <vector>

// unique() is in the algorithm library so we should include this library, 
// though it may also be included when we include vector
#include <algorithm>

using namespace std;

// A custom function to determine when two elements in the range are equivalent,
// we can optionally pass this function to unique as a 3rd argument and it 
// will alter the the default behaviour of the function.  The function should 
// return true if two elements are considered equivalent and false otherwise, in
// this case we only return true if n1 is equal to n2 AND both numbers are less 
// than 10.
bool match(int n1, int n2)
{
  return n1 == n2 && n1 < 10 && n2 < 10;
}

int main()
{
  // In this vector, only 1,1, and 3,3 and 12,12 are CONSECUTIVE duplicates, 
  // the '2' elements are duplicates but not consecutive duplicates.
  vector<int> data = { 9,1,1,2,3,3,2,5,12,12 };
  
  // Output the vector before calling the unique function using an iterator to 
  // loop through the vector elements
  cout << "Before: ";
  for (auto it = data.begin(); it != data.end(); it++)
    cout << *it << " ";
  cout << endl;
  
  // Output the size of the vector before
  cout << "Before Size: " << data.size() << endl;
  
  // Call the unique function and passing an iterator to the beginning and end 
  // (technically one element past the end) of the range we wish to remove 
  // consecutive duplicates from.  The unique function will return an iterator 
  // to an element on past the last element to not be removed (i.e. the 'end' 
  // of a filtered and potentially shortened range).
  auto new_end = unique(data.begin(), data.end());
  
  // We can optionally provide a 3rd argument, a custom function to determine 
  // when elements are considered equivalent.  We use our match function which
  // will only find two elements to be equivalent if they are both < 10, which
  // will have the effect of not removing the second 12 element.  Comment out
  // the above call to unique and uncomment the below function call to test it 
  // it out...
  //
  // auto new_end = unique(data.begin(), data.end(), match);
  
  // If our filtered range is smaller than the original range, the elements in 
  // the range between the 'new end' and the 'old end' are no longer really  
  // needed, so we resize the vector to remove them.
  data.resize(distance(data.begin(), new_end));
  
  // Output the size of the vector after calling unique and re-sizing the vector
  cout << "After Size: " << data.size() << endl;
  
  // Output the vector contents afterwards as well
  cout << "After All: ";
  for (auto it = data.begin(); it != data.end(); it++)
    cout << *it << " ";
  cout << endl;
  
  return 0;
}