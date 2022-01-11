/*******************************************************************************
*
* Program: cout Basics
* 
* Description: Demonstrates the basics of using cout in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=JJC1Ws0GXAs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
  // cout is the 'standard output stream object' and the << operator is the 
  // stream insertion operator, this statement will output the text "test" 
  // to the standard output stream (by default, the console)
  cout << "test";
   
  // outputs a newline to the console, so that subsequent output will print
  // to the next line
  cout << endl;
  
  // we MUST output an endl (or \n) to get a newline, as abc123xyz will output
  // all on one line if we execute the below code
  cout << "abc";
  cout << "123";
  cout << "xyz";
  cout << endl;
  
  // we can also use the special newline character \n to output a newline
  cout << "another line of text\n";
  
  // we can chain multiple stream insertion operators together in one statement
  cout << "let's learn how to " << "use cout!\n";
  
  // we can insert multiple endl stream manipulators in a single statement
  cout << "line 1" << endl << "line 2" << endl;
  
  // we can output the value of a variable using the insertion operator
  int x = 20;
  cout << "x: " << x << endl;
  
  // this is useful for outputing dynamic information that may change as our 
  // program is running as part of output, for example an age value that 
  // might be calculator somehow or set by the user
  int age = 45;
  cout << "His father is " << age << " years old.\n";
  
  return 0;
}