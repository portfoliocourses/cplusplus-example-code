/*******************************************************************************
*
* Program: count() Standard Library Function Examples
* 
* Description: Examples of using the count() standard libary function in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=VaQDB3kCqgU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

// count() is defined inside of algorithm so we include the library
#include <algorithm>
#include <vector>

using namespace std;

// A very simple class for geometric squares with a side length
class Square
{
public:

  // Square side length
  int side;
  
  // Constructor to set square side length
  Square(int side) : side(side) {}
  
  // Overloaded == equality operator, squares are equal if they have the 
  // same side length as determined by comparing the side lengths
  bool operator==(const Square &squareA)
  {
    return (side == squareA.side);
  }
};

int main()
{
  // An array of ints with 3 occurrences of the value '2'
  //                                ,X
  int array[] = {1,2,3,4,5,1,2,1,2,3};
  
  // Call count() to count the occurrences of the value 2 in the array.  We 
  // pass array and "array+10" to specify the range in which to count the 
  // occurrences of 2.  Technically array is a pointer to the first element in
  // the array and array+10 is a pointer to an element 10 elements ahead of 
  // this first element (i.e. one past the actual last element in the array 
  // where X is above).  The count function will count the occurrences of the 
  // value 2 in the range:
  //
  // [start, end)
  //
  // In other words, it will count up until but not included the end that 
  // we specify.  The start and end arguments that specify the range are 
  // iterators, but in C++ pointers are iterators.
  //
  int count2 = count(array, array+10, 2);
  
  // Output the count of occurrences of the value 2 in the array
  cout << "2s: " << count2 << endl;
  
  
  // Declare and initialize a vector to store int values with 1 occurrence of 
  // the value 1.
  //
  //                                   ,X
  vector<int> test {3,4,5,6,7,1,2,3,4,5};
   
  // Call count() to count the occurrences of the value 1 in the vector test. 
  // The .begin() and .end() vector member functions return an iterator to the 
  // first element in the vector, and an iterator to the 'hypothetical' element 
  // one past the last element in the vector (visualized with X above).  And so
  // count() will count the occurrences of 1 that occur between the first and 
  // last elements in the vector.
  //
  int count1 = count(test.begin(), test.end(), 1);
  
  // Output the count of 1s
  cout << "1s: " << count1 << endl;
  
  
  // Create a vector of square objects, with two squares having a side length 
  // of 3
  vector<Square> squares { Square(2), Square(3), Square(3), Square(1) };
  
  // Create a square object with a side length of 3
  Square tocount = Square(3);

  // Technically the count() function returns the number of elements in the 
  // range that "compare equally" to the 3rd argument.  What that means is that 
  // it returns the number of elements that when compared using the equality 
  // operator == with the 3rd argument result in the value true.  In the 
  // Square class we have overloaded the equality operator so that Squares are 
  // considered equal if they have the same side lengths.  As a result when 
  // comparing the Square tocount to the Squares in our vector, we expect that 
  // the two Squares with side lengths of 3 in the vector will compare equally
  // with to count (which has a side length of 3), and therefore we will have 
  // a count return value of 2.
  //
  int count3 = count(squares.begin(), squares.end(), tocount);

  // Output the number of squares with a side length of 3 
  cout << "Squares with side==3 -> " << count3 << endl;

  return 0;
}