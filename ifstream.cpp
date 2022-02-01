/*******************************************************************************
*
* Program: ifstream Basics
* 
* Description: Demonstrates how to use ifstream to read from files in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wVhCnzFwxt4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // Uncomment/comment the below code blocks and modify the contents of file.txt
  // in order to test out the different examples of reading content from a file.

  // create an ifstream object
  ifstream inFile;

  // attempt to open file.txt
  inFile.open("file.txt");

  // if file.txt fails to open, fail() will return true, and we'll exit 
  // gracefully by telling the user what went wrong and exiting with status 1 
  // which is a signal to the shell that something wen't wrong in the execution
  // of our program
  if (inFile.fail())
  {
    cout << "Error opening file." << endl;
    return 1;
  }


  // Assume file.txt contains the text:
  // 4
  //

  // variable to store number in the file
  int number = 0;
  
  // attempt to read in the number
  inFile >> number;

  // if we attempt to read in another number it will fail and we can also 
  // detect this using the fail() function 
  /*
  inFile >> number;
  if (inFile.fail())
  {
    cout << "Error file format incorrect." << endl;
    return 1;
  }
  */

  cout << number << endl;


  // Attempt to read in a file with the format:
  // 1.1 1.2 1.3
  // 2.1 2.2 2.3
  // 3.1 3.2 3.3
  //
  // Notice howe can read in multiple values, also notice how we use the
  // eof() function to detect the end of a file... allowing us to process 
  // a file with an arbitrary number of lines, where each line has 3 
  // double values per line.
  //

  /*
  double x1 = 0, x2 = 0, x3 = 0;

  while (true)
  {
    inFile >> x1 >> x2 >> x3;
    if (inFile.eof()) break;
    else 
      cout << x1 << " " << x2 << " " << x3 << endl;
  }
  */

  
  // We could also store the values into a 2D array for usage later.  Notice 
  // how we use the stream extraction operator IN the while loop condition... 
  // it will return true when extraction is successful, and false when it is 
  // not (e.g. we reach the end of the file).  This is an alternative way of 
  // reading in the values from the file.  Also notice how we increment i 
  // in each iteration of the loop to store the values in the next row of the 
  // 2D array.
  //
  /*
  double a[3][3];
  int i = 0;
  while (inFile >> a[i][0] >> a[i][1] >> a[i][2])
    i++;

  cout << endl;
  for (int j = 0; j < 3; j++)
  {
    cout << a[j][0] << " ";
    cout << a[j][1] << " ";
    cout << a[j][2] << endl;
  }
  */

  // If the file contents are:
  // This is a string.
  // 
  // Then if we use the stream extraction operator, only the keyword "This" 
  // will be stored into line... because the operator will stop at the first 
  // whitespace character.  We can use getline() to read in the entire line 
  // including spaces, because it will stop at the first newline in the file.
  //
  /*
  string line;
  // inFile >> line;
  getline(inFile, line);
  cout << line << endl;
  */

  // we close the file when we are done with it as a best practice, it also has
  // the effect of free-ing up some memory too
  inFile.close();

  return 0;
}