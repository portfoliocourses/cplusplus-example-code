/*******************************************************************************
*
* Program: Convert A String To An Int
* 
* Description: Two approaches to convert a string to an int in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=a43R5WBs2zQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  // Approach #1: Use stoi()


  // Create a test string.
  string number1 = "42";
  
  // The stoi() function from the string library will accept a string as an 
  // argument and convert it to an int, returning the int value, which we then
  // store into n1.
  int n1 = stoi(number1);
  
  // Output n1 to check that the conversion was successful.
  cout << n1 << endl;
  
  // The stoi() function is only available in C++11 onwards, so the above 
  // approach will not work in older versions of C++.



  // Approach #2: Use a stringstream object


  // Declare the stringstream object, we can use the stream insertion and 
  // extraction operator with this stream in a similar way we do with 
  // other streams like cin and cout.
  stringstream convert;
  
  // Create a test string.
  string number2 = "4";
  
  // Use the stream insertion operator to put the string onto the stream.
  convert << number2;
  
  // Declare an int variable to store the converted into value.
  int n2;
  
  // Use the stream extraction operator to extract the converted int value.
  convert >> n2;
  
  // Output n2 to confirm the conversion was successful.
  cout << n2 << endl;

  return 0;
}