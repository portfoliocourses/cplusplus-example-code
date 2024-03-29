/*******************************************************************************
*
* Program: Christmas Tree Printer
* 
* Description: Example of printing out a Christmas tree in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0d2hre6YY3c 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main(void)
{
  // ask the user for the height of the tree, store it into height
  int height = 0; 
  cout << "Enter height: ";
  cin >> height;
  
  // output a newline to separate the user input from the outputting of the tree
  cout << endl;
  
  // we'll print out a decreasing number of spaces and an increasing number 
  // of stars on each line from the top of the tree to the bottom of the tree  
  for (int i = 1; i <= height; i++)
  {
    // star count will go from 1 up until 2x height - 1    
    int starCount = (i * 2) - 1;
    
    // space count starts off at the center of the tree to print the top star, 
    // and from their decreases as i increases in order as we have more stars 
    // to print per line   
    int spaceCount = height - i + 1;
    
    // print out the spaces    
    for (int j = 0; j < spaceCount; j++)
      cout << " ";
    
    // print out the stars    
    for (int j = 0; j < starCount; j++)
      cout << "*";
    
    // print out a new line so the next line of stars starts on a new line    
    cout << endl;
  }
  
  // creates a 3 star "base" for the tree, at the center of the tree
  for (int i = 0; i < 3; i++)
  {
    // print out enough spaces to reach the center of the tree
    for (int j = 0; j < height; j++)
      cout << " ";

    // print out a star, followed by a newline so the next part of the trunk
    // stars on a another line
    cout << "*";
    cout << endl;
  }
  
  return 0;
}

// The above code can be used to generate trees like the below. Merry Christmas!
//
//          *
//         ***
//        *****
//       *******
//      *********
//     ***********
//    *************
//   ***************
//          *
//          *
//          *