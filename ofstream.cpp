/*******************************************************************************
*
* Program: ofstream Basics
* 
* Description: Demonstrates how to use ofstream to write to files in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Rfe2Jb2JP-Y 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // create the ofstream object
  ofstream outFile;

  // open file.txt using the append flag so content will be appended to the 
  // end of any existing content in file.txt
  outFile.open("file.txt", ofstream::app);

  // check if the file failed to open, fail gracefully if this is the case
  if (outFile.fail())
  {
    cout << "Error opening file." << endl;
    return 1;
  }

  // we use the stream insertion operator to write to the file, as we do 
  // when we use cout!
  outFile << "content" << endl;

  // declare and initialize some variables of different types
  double x = 4.5;
  int y = 10;
  string z = "abc";

  // we can output the content of variables as well!
  outFile << x << endl;
  outFile << y << endl;
  outFile << z << endl;

  // close the file, as a best practice when we are done with it
  outFile.close();

  return 0;
}