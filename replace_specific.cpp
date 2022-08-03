/*******************************************************************************
*
* Program: Replace A Specific Line In A File
* 
* Description: Example of how to replace a specific line in a file using C++ (by
* line number).  We solve the problem by reading each line of the file and 
* storing it into a vector, and then writing these lines back to the file 
* EXCEPT for the line we wish to replace where we write the replacement text 
* to the file as the new line instead.
*
* YouTube Lesson: https://www.youtube.com/watch?v=TUBVZvzEQAs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // variables for storing the filename of the file, the replacement line of 
  // text, and the line number to replace in the file
  string filename;
  string text;
  int line_number;
  
  // Prompt the user to enter the filename, store string entered into filename
  cout << "File: ";
  getline(cin, filename);
  
  // Prompt user to enter replacement text, store it into text
  cout << "Text: ";
  getline(cin, text);
  
  // Prompt the user to enter the line number to replace in the file, store it 
  // into line_number
  cout << "Line: ";
  cin >> line_number;
  
  // fstream object will be used to read all of the existing lines in the file
  fstream read_file;
  
  // Open the file with the provided filename
  read_file.open(filename);
  
  // If file failed to open, exit with an error message and error exit status
  if (read_file.fail())
  {
    cout << "Error opening file." << endl;

    // returning 1 instead of 0 is a signal to the shell that something went 
    // wrong in the execution of the program
    return 1;
  }
  
  // Create a vector to store all the file lines, and a string line to store 
  // each line that we read
  vector<string> lines;
  string line;
  
  // Read each line of the file and store it as the next element of the vector,
  // the loop will stop when there are no more lines to read
  while (getline(read_file, line))
    lines.push_back(line);
  
  // Close our access to the file since we are done reading with it
  read_file.close();
  
  // The vector will now contain an element for each line in the file, so the 
  // size of the vector is the number of lines in the file.  Check to make 
  // sure the line number requested does not exceed the number of lines in 
  // the file, if it does, exit with an error message and status.
  if (line_number > lines.size())
  {
    cout << "Line " << line_number;
    cout << " not in file." << endl;
    
    // Inform user how many lines ARE in the file as part of the error message
    cout << "File has " << lines.size();
    cout << " lines." << endl;

    return 1;
  }
  
  // Create ofstream object for writing to the file
  ofstream write_file;
  
  // Open the file with the provided filename
  write_file.open(filename);
  
  // If the file failed to open, exit with an error message and exit status
  if (write_file.fail())
  {
    cout << "Error opening file." << endl;
    return 1;
  }
  
  // Write all of the lines stored in the vector back to the file, EXCEPT the
  // line that we want to replace, in that case we'll write the replacement 
  // text instead.

  // Line number 1 will be stored at vector index 0, line number 2 will be 
  // stored at vector index 1, and so on because vectors are zero-indexed, so 
  // decrement line_number to help us identify when we've reached the 
  // associated line in the file.
  line_number--;

  // Loop through the vector elements to write each line back to the file 
  // EXCEPT the line we want to replace
  for (int i = 0; i < lines.size(); i++)
  {
    // If the current index is not the line number we wish to replace, write 
    // the line back to the file, OTHERWISE if it IS the line we want to  
    // replace write the replacement text back to the file instead.
    if (i != line_number)
      write_file << lines[i] << endl;
    else 
      write_file << text << endl; 
  }
  
  // Close our access to the file since we are done working with it
  write_file.close();

  return 0;
}
