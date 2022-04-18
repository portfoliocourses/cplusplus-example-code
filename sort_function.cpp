/*******************************************************************************
*
* Program: sort() Demonstration
* 
* Description: A demonstration of how to use the standard library sort() 
* function in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=hP7aIrTRqQw  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

// the sort() function is in the algorithm library so we must include it to use
// the function
#include <algorithm>
#include <vector>

using namespace std;

// A user defined type for representing squares
class Square
{
public:
  int side;
  
  Square(int side) : side(side) { }
};

// A function that defines how to compare two Square objects that we can use 
// to help sort Square objects.
bool compare_squares(Square x, Square y)
{
  return x.side > y.side;
}

int main()
{
  // a test array to sort
  int array1[] = {9,4,5,8,3,7,2,6,0,1};
  
  // If we call sort like this it will sort the array in descending order. 
  // We pass in a pointer to the first element in the array as the first 
  // argument and the pointer / memory address to stop sorting the array 
  // using pointer arithmetic... array1 + length of the array (10)
  // sort(array1, array1 + 10);
  
  // Sorts the array in ascending order by passing in a 3rd argument... a
  // function defining how to compare two elements, in this case we pass in 
  // what is effectively the greater operator (function) for int values.
  sort(array1, array1 + 10, greater<int>());
  
  // output the array to ensure it is sorted
  for (int i = 0; i < 10; i++)
    cout << array1[i] << " ";
  cout << endl;
  
  
  // Create an array of Square objects
  Square array2[] = {Square(6), Square(9), Square(4), Square(3)};
  
  // sort the array of Squares using compare_squares to define how to compare 
  // square objects for the sake of sorting/ordering them
  sort(array2, array2 + 4, compare_squares);
  
  // output the now sorted array of squares for verification
  for (int i = 0; i < 4; i++)
    cout << array2[i].side << " ";
  cout << endl;
  

  // sort() will work with any random access container, including vectors, so 
  // we test it with a vector as well
  vector<int> vector1{9,4,5,8,3,7,2,6,0,1};
  
  // we pass in as first and second arguments random access iterators that 
  // define a sequence of values
  sort(vector1.begin(), vector1.end());
  
  // output the vector values to verify sorting succeeded
  for (int value : vector1)
    cout << value << " ";
  cout << endl;  
  
  return 0;
}