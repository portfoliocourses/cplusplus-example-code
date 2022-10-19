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

#define MAX_LINES 1000

using namespace std;

int main(void)
{
  string filename;
  ifstream file;
  string array[MAX_LINES];

  cout << "Filename: ";
  cin >> filename;

  file.open(filename);

  if (file.fail())
  {
    cout << "File failed to open." << endl;
    return 1;
  }

  int lines = 0;
  while (!file.eof())
  {
    getline(file, array[lines]);
    lines++;

    if (lines == MAX_LINES)
    {
      cout << "Max storage reached" << endl;
      break;
    }
  }

  file.close();

  for (int i = 0; i < lines; i++)
    cout << array[i] << endl;

  return 0;
}