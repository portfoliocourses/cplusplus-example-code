/*******************************************************************************
*
* Program: Clear Input Buffer
* 
* Description: Example of using cin.ignore() to clear the input buffer in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=fcygVtDXanM  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // Try to read in an int and store it into number.  When we use cin the 
  // characters the user enters will end up in an 'input buffer', a temporary 
  // place before the values are stored into variables like number.
  int number = 0;
  cout << "number: ";
  cin >> number;
  
  // After the user enters in a number like '5' and hits enter the input buffer 
  // will contain the characters:
  //
  // 5\n
  //
  // And the cin >> number statement will then rip off the character 5 to store 
  // the int 5 into the number variable.  This will leave the input buffer with
  // the character:
  //
  // \n
  //
  // The problem is the below attempt to read in a line of input from the user 
  // will then fail because getline() stops reading input at the first newline 
  // character encountered, and in this case we *already* have a newline 
  // character in the input buffer, so getline() stop immediately rather than 
  // pausing for user input.
  //
  // We can use cin.ignore(#, xchar) to ignore up to # amount of characters in 
  // the input buffer ("ripping them off") or up until the first xchar (where 
  // xchar is some character), whichever comes first.  So if we were to run:
  //
  // cin.ignore(1, '\n');
  //
  // This would rip off the newline character from the input buffer, and the 
  // getline() would allow the user to enter a string as the buffer would then 
  // be empty. But if the user enters something like this:
  //
  // 5----\n
  //
  // where each - represents a space character, then we would need to ignore 
  // up to 5 characters in order for the input stream to be blank again!  So 
  // we use:
  // 
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  //
  // where numeric_limits<streamsize>::max() is the maximum number of characters
  // that can possibly occur in an input buffer, ensuring that the buffer MUST 
  // be completely cleared after running cin.ignore().
  //
  // If we comment out the below line, notice how the call to getline() fails!
  //
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
  // read in a line of string input from the user, getline will stop reading 
  // in characters at the first newline (up to 256 characters)
  char line[256];
  cout << "line: ";
  cin.getline(line, 256);
  
  // output the number and line values
  cout << endl;
  cout << "number: " << number << endl;
  cout << "line: " << line << endl;
  
  return 0;
}