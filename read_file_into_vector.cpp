/*******************************************************************************
*
* Program: Read And Store All File Lines Into A Vector
*
* Description: Program to read and store all the lines in a file into a vector
* using C++
*
* YouTube Lesson: https://www.youtube.com/watch?v=XajKINSkLII
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void)
{
  // stores the name of the file to be opened
  string filename;

  // ifstream file object is used to access the file
  ifstream file;

  // Prompt the user to enter the filename of the file to open and store what
  // the user enters into the filename string variable.
  cout << "Filename: ";
  cin >> filename;

  // Use the open member function of the ifstream file object to open the file
  // with the filename provided by the user.
  file.open(filename);

  // If the file fails to open for some reason (e.g. the file doesn't exist),
  // the fail member function of the ifstream file object will return true.
  // If it does, we exit the program with an error message and status.
  if (file.fail())
  {
    // Output an error message for the user
    cout << "File failed to open." << endl;

    // Exit the program with an error status.  When we use a return statement in
    // in the main function the program will terminate, and returning '1'
    // (instead of returning 0) is a signal to the shell/terminal/console that
    // the program exited with an error status.
    return 1;
  }

  // contents vector to store each line of the file as a string
  vector<string> contents;

  // line string variable to help read each line of the file as a string
  string line;

  // The .eof() member function will return true when we reach the end of the
  // file, so we continue the loop so long as this is NOT true using !file.eof()
  while (!file.eof())
  {
    // getline() will read the next line of the file with each loop iteration
    // and store it into the string line
    getline(file, line);

    // Add the line (string) to the vector as a new element, push_back() will
    // insert the new element as the last element in the vector, meaning
    // the lines of the file will be stored in the vector in the same sequence
    // as they occur in the file.
    contents.push_back(line);
  }

  // Close the file as we are now done working with it
  file.close();

  // Use a range-based for loop to access each element of the vector contents
  // using the variable name 'file_line' and out the string to confirm the
  // lines of the file have been read successfully.
  for (auto file_line : contents)
    cout << file_line << endl;

  return 0;
}