/*******************************************************************************
*
* Program: Read A Specific Line From A File
* 
* Description: Read a specific line from a file using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Re417iwYM84 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // Use the ifstream object file to read the file
  ifstream file;
  
  // filename will store the name of the file and line_number the line number
  string filename;
  int line_number;
  
  // Prompt the user to enter the filename
  cout << "File: ";

  // Store the string the user enters into filename
  cin >> filename;
  
  // Prompt the user to enter the line number
  cout << "Line: ";

  // Store the line number the user enters into line_number
  cin >> line_number;
  
  // The line number must be >= 1 so exit with an error message and status if 
  // it is not... returning '1' is an exit status that indicates an error to 
  // the shell/terminal.
  if (line_number <= 0)
  {
    cout << "Line number must be >= 1" << endl;
    return 1;
  }
  
  // Open the file with the provided filename
  file.open(filename);
  
  // If there was a failure opening the file (perhaps it does not exist) then
  // exit with an error message and status.
  if (file.fail())
  {
    cout << "File failed to open." << endl;
    return 1; 
  }
  
  // We'll read in the file one line at a time until we find the line we're 
  // looking for... current_line will keep track of the current line number 
  // of the line we're reading in, and line will store the line content/string.
  int current_line = 0;
  string line;
  
  // Continue to read the file one line at a time, unless we reach the end of 
  // the file at which point we stop
  while (!file.eof())
  {
    // Increment the current line number being read as we are reading in the 
    // next line now
    current_line++;

    // Read the next line from the 'file' into the 'line' string 
    getline(file, line);

    // If current line number of the line we've read in matches the line number 
    // that we're looking for, use break to stop the loop
    if (current_line == line_number) break;
  }
  
  // It's possible that the file does not contain as many lines as the line 
  // number that the user requested, if this is the case we output an error
  // message and inform the user how many lines are in the file.
  if (current_line < line_number)
  {
    cout << "Line not found!" << endl;
    cout << "File contains " << current_line;
    cout << " lines total." << endl;
  }
  // Otherwise we output the line content/string
  else cout << "Line: " << line << endl;
  
  // Close the file as we are done working with it
  file.close();

  return 0;
}