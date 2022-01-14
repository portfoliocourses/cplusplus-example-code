/*******************************************************************************
*
* Program: cin Basics
* 
* Description: Demonstration of how to use cin to accept user input with C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=hKqNb3Wo6z0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// cin is included in the iostream library
#include <iostream>

using namespace std;

int main()
{
  
  // prompt the user for an int value 
  int x;
  cout << "Enter an integer: ";

  // use cin to store the value the user enters into x... if for some reason 
  // it cannot be done, the expression will evaluate to false
  if (cin >> x)
  {
    // if an integer was successfully received, output the value
    cout << "You entered the integer " << x << endl;
  }
  else
  {
    // if there was an error, clear the error, and inform the user 
    // they provided invalid input
    cin.clear();
    cout << "Invalid input" << endl;
  }
  
  // will clear the input stream of any characters, up to either 1000 
  // characters or the first newline whichever comes first
  cin.ignore(1000, '\n');
  

  // variables for rectangle dimensions, area
  double height = 0;
  double width = 0;
  double area = 0;
  
  // prompt the user for a height and width value
  cout << "Enter height and width (separated by a space):";

  // we can use cin to accept multiple values at once, so inputting a height
  // value and a width value separated by whitespace characters will work, 
  // e.g. entering 5     20.5
  cin >> height >> width;
  area = height * width;
  cout << height << " x " << width << " = " << area << endl;
  

  // clear the input stream of any characters (e.g. a newline)
  cin.ignore(1000, '\n');
  
  // prompt the user for their name
  string name;
  cout << "Enter your name: ";
  
  // will only store the string up until the first space character, so a 
  // name like 'kevin browne' will only be stored as 'kevin' into name
  // cin >> name;
  
  // will store the string up until the first newline character into name, 
  // so a name like 'kevin browne' will be stored entirely
  getline(cin, name);

  // say hello to the user by using their name  :-)
  cout << "Hello " << name << "!" << endl;
  
  return 0;
}
