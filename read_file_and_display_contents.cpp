/*******************************************************************************
*
* Program: Read A File And Display Its Contents
* 
* Description: Example of how to read and display all the contents of a file 
* using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=tma4agtKt6Q 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
  // Used to store the filename entered by the user.
  string filename;
  
  // Prompt the user to enter the name of the file to read
  cout << "Filename: ";

  // Read the name entered by the user and store it into filename
  getline(cin, filename); 

  // Declare the ifstream object used to open and read the file contents
  ifstream inFile;
  
  // Attempt to open the file with the filename provided by the user
  inFile.open(filename);
  
  // If the file failed to open, for example because it does not exist, the 
  // fail() member function will return true.  If it does we will exit the 
  // program with an error message and status.
  if (inFile.fail())
  {
    // Output the error message to the user
    cout << "Error opening file." << endl;

    // Exiting the program by returning 1 instead of returning 0 is a signal to
    // the shell (terminal) that something has gone wrong with the execution
    // of the program.
    return 1;
  }
  
  // rdbuf() will return a pointer to the stream buffer object associated with
  // the stream, and the stream extraction operator << will use it to keep 
  // reading the stream until its exhausted (i.e. until all file content has 
  // been output).
  cout << inFile.rdbuf(); 

  // As an alternative approach, we could read the contents of the file one 
  // character at a time using get().  The get() function will read the next 
  // character from the file each time it is called and store it into the 
  // char variable c.  It will return false when there is no more characters
  // to read from the file, stopping the loop, otherwise it will return true.
  // We output the character read with each iteration of the loop to output
  // all the characters in the file.
  //
  // char c;
  // while (inFile.get(c)) cout << c;

  // Close the file as we are done working with it
  inFile.close();

  return 0; 
}