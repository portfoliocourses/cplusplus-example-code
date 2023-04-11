/*******************************************************************************
*
* Program: Reverse A String Using reverse()
*
* Description: Example of how to reverse a string in C++ using the reverse()
* function of the algorithm library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4ysRvfzjmhQ
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
  // create a test string
  string text1 = "There is no hand to catch time";
  
  // we call reverse and pass it the range of the entire string
  reverse(text1.begin(), text1.end());
  
  // output the reversed string
  cout << text1 << endl;
  
  // create a C-style test string
  char text2[] = "All that glitters is not gold";
  
  // we use pointer arithmetic to pass it the range of the entire string
  reverse(text2, text2 + strlen(text2));
  
  // output the reversed string
  cout << text2 << endl;
  
  return 0;
}