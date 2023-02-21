/*******************************************************************************
*
* Program: Find The Smallest Number In A File
*
* Description: Program to find the smallest number in a file using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=uC8DkIJlKLI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// This program assumes the file is formatted as follows, with a number on each
// line, possibly a real number number that includes decimal places and not
// only integers without decimal places:
//
// 4.4
// 5.3
// 9.5
// 2.8
// 10.2


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // Declare a string variable to store the name of the file
  string filename;

  // Prompt the user to enter the name of the file, store what they enter
  // into the filename string variable
  cout << "Filename: ";
  getline(cin, filename);

  // Create an ifstream object to access the file
  ifstream file;

  // Use the open() member function of the ifstream object to open the file
  // with the provided filename so we can read the numbers from the file
  file.open(filename);

  // It's possible an error could occur when opening the file, for example the
  // file may not exist.  If an error occurs, the fail() member function will
  // return true, in which case the program will exit with an error message
  // and status.
  if (file.fail())
  {
    // Output 'error opening file' as an exit message to inform the user what
    // has gone wrong.
    cout << "Error opening file." << endl;

    // Returning 1 will exit the program with an error status
    return 1;
  }

  // Declare number to store each number that is read from the file
  double number = 0;

  // Declare min to store the smallest number read thus far from the file
  double min = 0;

  // Declare firstNumber to keep track of whether we have read the first 
  // number from the file or not.
  bool firstNumber = true;

  // We can read each number from the file using the stream extraction operator
  // >> with file >> number.  file >> number will return true if a number is
  // successfully read from the file, and false when we reach the end of the
  // file.  As a result the loop will continue to execute until we reach the
  // end of the file, and with each iteration of the loop the variable
  // 'number' will be set to the next number in the file.
  while (file >> number)
  {
    // If this is the first number we've read from the file, by default it's 
    // also the minimum number we've read from the file so far, so we set 
    // min to the number read from the file.
    if (firstNumber)
    {
      min = number;

      // Acknowledge we've read a number by setting firstNumber to false
      firstNumber = false;
    }
    // Otherwise if it's not the first number we've read from the file we 
    // check if it is smaller than min (the smallest number we've read so 
    // far), and if it is we update min and set it to the number.
    else if (number < min)
    {
      min = number;
    }
  }

  // By the end of the loop min will contain the smallest number found in the 
  // file as we will have checked all numbers in the file and updated min 
  // whenever we found a number smaller than min.
  //
  // If firstNumber is still set to true that means we NEVER read any numbers 
  // from the file, in which case we'll output a message indicating this.  
  // Otherwise we'll output the smallest number we read from the file.
  if (firstNumber) 
  {
    cout << "No numbers in file." << endl;
  }
  else 
  {
    cout << "Min: " << min << endl;
  }

  // Close the file as we are done working with it now
  file.close();

  return 0;
}