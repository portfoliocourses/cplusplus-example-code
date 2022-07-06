/*******************************************************************************
*
* Program: Initialize A Vector With User Input
*
* Description: Program to initialize a vector with user input in C++ using two 
* different approaches. In the first approach we know the number of elements to
* initialize in advance of prompting the user for the values.  In the second 
* approach there is an indeterminate number of elements to be initialized and a
* sentinel value is used to terminate user input. 
*
* YouTube Lesson: https://www.youtube.com/watch?v=18r4P6UNSYk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // In the first approach, which is commented out, we first prompt the user 
  // for the number of elements.  We then initialize a vector with this size,
  // and prompt the user for each element value and set the element value 
  // using the element index.  To test this code you can uncomment the below 
  // code and comment out the code for the second approach.
  //

  /*
  // Prompt the user for the number of elements to be entered, store the result
  // into total
  cout << "Number of Elements: ";
  int total = 0;
  cin >> total;
  
  // Create a vector of size total to store ints
  vector<int> data(total);
   
  // Prompt the user for total number of int values, store them into the vector
  for (int i = 0; i < total; i++)
  {
    // Output i so the user knows the index of the element being set
    cout << "Element " << i << ": ";

    // Store the value in the vector at index i
    cin >> data[i];
  }
  */
  
  // In the second approach, we don't know how many values the user will enter 
  // before we begin asking the user to provide the values.  We use a sentinel 
  // value (-1) to terminate user input in this case.  We create a vector with 
  // no initialize size provided and add vector elements using the push_back()
  // method until the sentinel value is entered.
  
  // Create the vector
  vector<int> data;
  
  // i will be used to output the element index being set, value will store 
  // each value entered by the user
  int i = 0;
  int value = 0;

  // inform the user how to terminate user input with the -1 sentinel value
  cout << "Enter -1 To Complete Input!" << endl;

  // the loop will run an indeterminate number of times
  while (true)
  {
    // prompt the user for the value and store it into the value variable
    cout << "Element " << i << ": ";
    cin >> value;

    // if the user enters -1, terminate the loop to complete user input
    if (value == -1) break;

    // if the sentinel value was not entered, add the value as the next 
    // element in the vector using push_back()
    data.push_back(value);

    // increment i so that the correct index is output when the user is 
    // prompted for the next element value
    i++;
  }
  
  // Print out the vector elements using a range-based for loop to verify that 
  // the vector element values were set correctly
  for (auto elem : data)
    cout << elem << " ";
  cout << endl;
  
  return 0;
}
