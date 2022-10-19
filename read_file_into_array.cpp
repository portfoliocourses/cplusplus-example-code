/*******************************************************************************
*
* Program: Read And Store Each Line Of A File Into An Array Of Strings
*
* Description: Program to read and store each line of a file into an array of
* strings using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=K7Pi0jGnyqw
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <fstream>

// Defines the maximum number of lines that can be read from the file and stored
// into the array.
#define MAX_LINES 1000

using namespace std;

int main(void)
{
  // stores the name of the file to be opened
  string filename;

  // ifstream file object is used to access the file
  ifstream file;

  // array of strings used to store each line of the file, it has length
  // MAX_LINES using the MAX_LINES preprocessor constant defined above
  string array[MAX_LINES];

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

  // lines will keep track of the number of lines read in from the file (both
  // so far as each line is read in, and in total).  We initialize it to 0
  // because we have not read any lines from the file yet.
  int lines = 0;

  // The .eof() member function will return true when we reach the end of the
  // file, so we continue the loop so long as this is NOT true using !file.eof()
  while (!file.eof())
  {
    // getline() will read the next line from the file and store it into the
    // string in the array at the index lines.
    getline(file, array[lines]);

    // Increment lines so that the next line in the file is stored in the next
    // index of the array.
    lines++;

    // If lines reaches MAX_LINES we cannot read any more lines from the file
    // as we have reached the length of the array.  So we output a message to
    // inform the user, and then use 'break' to stop the loop.
    if (lines == MAX_LINES)
    {
      cout << "Max storage reached" << endl;
      break;
    }
  }

  // Close the file as we are now done working with it
  file.close();

  // To confirm we've succesfully read the lines from the file into the array,
  // output each element of the array that contains a line from the file.  The
  // lines from the file were stored in the indexes 0 onwards, with the
  // variable 'lines' storing the total number of lines read.  So we have the
  // counter variable i go from 0 up until 'lines' to output the elements at
  // these indexes in the array that store the lines from the file.
  for (int i = 0; i < lines; i++)
    cout << array[i] << endl;

  return 0;
}
