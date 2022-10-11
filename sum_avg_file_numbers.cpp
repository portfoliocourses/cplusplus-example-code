/*******************************************************************************
*
* Program: Find The Sum And Average Of Numbers In A File
*
* Description: Program to find the sum and average of numbers contained on each
* line of a file using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=MM8DCSdicrI
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
  cin >> filename;

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
    cout << "Error opening file!" << endl;

    // Returning 1 will exit the program with an error status
    return 1;
  }

  // Declare number to store each number that is read from the file
  double number = 0;

  // Declare sum to store the sum of the numbers in the file
  double sum = 0;

  // Declare total to store the total amount of numbers in the file
  double total = 0;

  // We can read each number from the file using the stream extraction operator
  // >> with file >> number.  file >> number will return true if a number is
  // successfully read from the file, and false when we reach the end of the
  // file.  As a result the loop will continue to execute until we reach the
  // end of the file, and with each iteration of the loop the variable
  // 'number' will be set to the next number in the file.
  while (file >> number)
  {
    // Add the number to the sum
    sum = sum + number;

    // Increase total by 1 to reflect that we have read another number
    total = total + 1;
  }

  // By the end of the loop sum will contain the sum of all the numbers in the
  // file, and we can now output this to the user
  cout << "Sum: " << sum << endl;

  // Calculate the average by dividing the sum by the total amount of numbers
  // in the file
  double average = sum / total;

  // Output the averae to the user
  cout << "Average: " << average << endl;

  // Close the file as we are done working with it now
  file.close();

  return 0;
}
