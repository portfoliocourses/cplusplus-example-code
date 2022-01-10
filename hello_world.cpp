/*******************************************************************************
*
* Program: Hello, World!
* 
* Description: A "Hello, World" program in C++.  A "Hello, World" program is 
* the traditional first program to write when learning a new language.
*
* YouTube Lesson: https://www.youtube.com/watch?v=DRCfF4j-rGg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// We can annotate our C++ programs with what are called comments by 
// starting a line with //.  Comments are intended to be read by other 
// programmers to help explain the source code.

// includes the Standard Input Output Streams Library which lets us use cout
#include <iostream>


/*

 This is an example of a mult-line comment!

 use the namespace std
 
 but we can have more than one line!
 
 */

// C++ programs use namespaces to help organize the names of variables and 
// other things, this statement has our program use the std namespace that 
// iostream uses above, allowing us to use cout as we do below
using namespace std;

// the main function is where program execution will begin, it returns an 
// int value as an exit code to the operating system (letting the 
// operating system know 'how' our program exited)
int main()
{
  // Outputs Hello, World to the standard output stream, using the cout 
  // object defined in iostream, and 'inserting' the "Hello, World\n" 
  // string literal into the standard output stream using the << operator.
  // The "Hello, World\n" is a sequence of characters, and the \n is a
  // special character for a newline.
  cout << "Hello, World\n";
  
  // returning 0 exits the program with a status of 0, which is a signal 
  // to the operating system that our program completed successfully
  return 0;
}