/*******************************************************************************
*
* Program: Append Text To A File
* 
* Description: Example of appending text to a file using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4Vsp22HQYhw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main(void)
{    
  // Declare an ofstream object which allows us to write to a file
  ofstream outFile;
  
  // If we open the file called file.txt WITHOUT the 2nd argument to open(),
  // then the new content written to the file will REPLACE the existing file 
  // content (i.e. the existing file content will be erased, and whatever we
  // write to the file will be the new file content).  If we supply ios::app as
  // a second argument (or std::ios::app if we do not have using namespace std
  // as above), then the file is opened in "append mode" and any text we write
  // to the file will be appended to the existing content. 
  outFile.open("file.txt", ios::app);
  
  // If the file fails to open the fail() member function will return true,
  // in this case we exit the program with an error message and status.  When
  // we return 1 instead of returning 0 to exit the program, that is a signal
  // to the shell/terminal that something has gone wrong in the execution of
  // our program.
  if (outFile.fail())
  {
    cout << "Error opening file." << endl;
    return 1;
  }

  // Write some new content to the file.  
  outFile << "New content" << endl;
  
  // Close the file as we are done working with the file.
  outFile.close();

  return 0; 
}