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
  /*
  cout << "Number of Elements: ";
  
  int total = 0;
  
  cin >> total;
  
  vector<int> data(total);
  
  for (int i = 0; i < total; i++)
  {
    cout << "Element " << i << ": ";
    cin >> data[i];
  }
  */
  
  vector<int> data;
  
  int i = 0;
  int value = 0;
  cout << "Enter -1 To Complete Input!" << endl;
  while (true)
  {
    cout << "Element " << i << ": ";
    cin >> value;
    if (value == -1) break;
    data.push_back(value);
    i++;
  }
  
  for (auto elem : data)
    cout << elem << " ";
  cout << endl;
  
  return 0;
}