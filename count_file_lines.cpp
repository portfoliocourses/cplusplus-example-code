/*******************************************************************************
*
* Program: Count the total number of lines in a file
*
* Description: Program to count the total number of lines in a file using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=xi9TIHWBjPs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <fstream>  // included so we can use the ifstream object

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

  // line string variable to help read each line of the file as a string
  string line;

  // lines int variable to keep track of how many lines are in the file total
  int lines = 0;

  // The .eof() member function will return true when we reach the end of the
  // file, so we continue the loop so long as this is NOT true using !file.eof()
  while (!file.eof())
  {
    // getline() will read the next line of the file with each loop iteration
    // and store it into the string line
    getline(file, line);

    // output the line
    cout << line << endl;

    // Increment number of lines to keep track of the total number of lines in
    // the file, as we have read another line from the file.  Becaus this
    // will execute once for each line in the file, once this loop is done
    // executing lines will contain the total number of lines in the file.
    lines++;
  }

  // Close the file as we are now done working with it
  file.close();

  // Output the total number of lines in the file
  cout << "Total Lines: " << lines << endl;

  return 0;
}