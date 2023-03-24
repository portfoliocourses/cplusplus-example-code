/*******************************************************************************
*
* Program: Write All Vector Elements To A File
* 
* Description: How to write all the elements of a vector to a file in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=7HXElMVtBu8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(void)
{
  vector<int> test;

  test.push_back(1);
  test.push_back(2);
  test.push_back(3);

  string filename;

  cout << "Filename: ";
  getline(cin, filename); 

  ofstream outFile;

  outFile.open(filename);

  if (outFile.fail())
  {
    cout << "Error opening file." << endl; 
    return 1;
  }
  
  for (auto element : test)
  {
    outFile << element << endl;         
  }
 
  outFile.close();

  return 0;
}