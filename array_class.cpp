/*******************************************************************************
*
* Program: array Class Examples
* 
* Description: Examples of using the array class in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=9fS9bkEae2U 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <array>

using namespace std;

// We can have array class function parameters & pass array objects to functions
void print_array(array<int,5> arr)
{
  cout << "Array: ";
  for (int element : arr)
    cout << element << " ";
  cout << endl;
}

int main()
{
  // Declare and initialize an array class object instance of size 5 to store 
  // the int values provided.  The array class is really a template class, so 
  // int and 5 are template arguments to use the template class to create an 
  // array class specific to this type (int) and size (5).
  array<int,5> array1 = {9,8,7,6,5};
  
  // Use the array index operator (scripting operator) to ouput the array 
  // element at index 1
  cout << "array1[1] = " << array1[1] << endl;
  
  // Use the at member function to output the array element at index 2
  cout << "array1.at(2) = " << array1.at(2) << endl;
  
  // The front member function will output the first element in the array
  cout << "array1.front() = " << array1.front() << endl;

  // The back member function will output the last element in the array
  cout << "array1.back() = " << array1.back() << endl;
  
  // The size member function will output the size of the array (in this case
  // 5), notably the compiler will replace the call to .size() with the 
  // size of the array as a constant value, so there is no "function call 
  // performance overhead" for using the .size() member function.
  cout << "array1.size() = " << array1.size() << endl;

  // The max_size() member function will return the same size as the size 
  // member function.  The array class is one of several sequence container 
  // classes, and the max_size() member function is more relevant to other 
  // sequence container classes. 
  cout << "array1.max_size() = " << array1.max_size() << endl;
  
  // Use the size member function to loop through and output the array elements
  for (int i = 0; i < array1.size(); i++)
    cout << "array1[" << i << "] = " << array1[i] << endl;
  
  // Declare another array object to store 5 ints
  array<int,5> array2;
  
  // Use the fill member function to set all array2 elements to 10
  array2.fill(10);
  
  // Loop through the array2 elements and output them to confirm all elements 
  // have been set to 10
  for (int i = 0; i < array2.size(); i++)
    cout << "array2[" << i << "] = " << array2[i] << endl;
  
  // Use the swap member function to swap the elements of array1 and array2
  array1.swap(array2);
  
  // All of the array1 elements will now be set to 10, here we use a range-based
  // for loop to out the array elements to verify this
  cout << "Array1: ";
  for (int element : array1)
    cout << element << " ";
  cout << endl;
  
  // Output all of the array2 elements to verify they match the old array1 
  // elements before the swap 
  cout << "Array2: ";
  for (int element : array2)
    cout << element << " ";
  cout << endl;
  
  // The empty member function will return true if the array size is 0 and false
  // otherwise, so array1 will not be empty
  if (array1.empty()) cout << "array1 is empty" << endl;
  else cout << "array1 is not empty" << endl;
  
  // Create an empty array
  array<int, 0> array3;
  
  // Verify that the empty member function can detect that array3 is empty
  if (array3.empty()) cout << "array3 is empty" << endl;
  else cout << "array3 is not empty" << endl;
  
  // The array class uses a C-style array internally to store the array data,
  // and we can use the data member function to return a pointer to this 
  // C-style array.  We can then use pointer notation and/or array notation 
  // to directly accesing the array elements.  Here we store the pointer to 
  // the C-style array (i.e. the memory address) into ptr.
  int *ptr = array1.data();

  // Use pointer notation to set the element at index 2 to 20
  *(ptr + 2) = 20;

  // Use array notation to set the element at index 3 to 30
  ptr[3] = 30;
  
  // Output array1 again to verify the above assignments worked correctly
  cout << "Array1: ";
  for (int element : array1)
    cout << element << " ";
  cout << endl;
  
  // We can also pass array objects to a function
  print_array(array1);
  
  // The array class allows us to use iterator objects to loop through the 
  // array.  The begin member function will return an iterator pointing to the 
  // first element in the array, and we increment the iterator until we reach 
  // the end of the array (the end member function will return an iterator 
  // pointing just past the last element in the array).
  cout << "Array (iterator print): ";
  for (array<int,5>::iterator it = array1.begin(); it != array1.end(); it++)
  {
    // de-reference the iterator and output the current element it's pointing to
    cout << *it << " ";
  }
  cout << endl;

  // The type of the iterator is complicated in the above loop, we can use the 
  // auto keyword instead and the compiler will use a type for 'it' variable 
  // based on the initialization of the variable.  This means if we later change
  // the size of the array, we don't need to change this code to match it.  We 
  // can use the member functions rbegin and rend to iterate through the array 
  // in reverse.  The rbegin, rend, begin and end functions are also available 
  // as global functions, which we use below. 
  cout << "Array (iterator print): ";
  for (auto it = rbegin(array1); it != rend(array1); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
  
  // If we compile the program in debug mode, we can detect array out of bounds
  // errors as below, where we try to access the 6th element in an array that is
  // only 5 elements in size.
  //
  // array1[5] = 10;
  
  // The at member function will also throw an exception if we try to access an 
  // element that is out of range.  We can use a try catch block to handle this 
  // exception, giving us another way of dealing with this issue.  This is not 
  // possible with C-style arrays.
  try
  {
    // try to access an array element that is out of bounds
    array1.at(5);
  }
  // catch the out_of_range exception and output an error
  catch (const out_of_range& orr)
  {
    cout << "ERROR OUT OF RANGE: " << orr.what() << endl;
  }
  
  return 0;
}