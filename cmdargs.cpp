/*******************************************************************************
*
* Program: Command-Line Arguments Example
* 
* Description: Example of how to use command line arguments in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=AjcAVVWt6Sk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// Command arguments are supplied to our program on the command line, e.g.
//
// ./cmdargs a1 a2
//
// Would run the program "cmdargs" and supply it with the arguments a1 and a2.
// These arguments serve as input to the program, e.g
//
// mkdir video
//
// will make a directory called video.

#include <iostream>

using namespace std;

// To use command line arguments we must include the parameters argc and 
// argv.  We can have either char **argv or char *argv[] as the argv parameter
// type because the two are equivalent... when we pass an array to a function 
// in C++ we are really passing a pointer to the first element in the array.
// argc is the number of command line arguments (including the program itself,
// so ./cmdargs in the above example).  argv is an array of pointers to 
// C strings containing the command-line arguments, beginning with the program
// name... i.e. the above example would result in:
//
//  argc = 3
//
//  argv[0] -> {'.', '/', 'c', 'm', 'd', 'a', 'r', 'g', 's', '\0'}
//  argv[1] -> {'a', '1', '\0'}
//  argv[2] -> {'a', '2', '\0'}
//
// Though notably if we want to have command-line arguments with spaces we can
// use single quotes or double quotes, so for example:
//
// ./cmdargs "a1 a2"         OR       ./cmdargs 'a1 a2'
//
// would result in argc = 2 and argv[1] = {'a', '1', ' ', 'a', '2', \0'}
//
int main(int argc, char *argv[])
{ 
  // We may want to check to make sure the number of supplied arguments matches
  // what is expected, e.g. if 2 arguments are required then argc should equal 3
  // as argc also includes the program name in the 'count'.
  if (argc == 3)
  {
    // Output each of the 3 strings stored in argv, which will be the program
    // name stored in the first index followed by the two arguments.
    cout << "argv[0]: " << argv[0] << endl;
    cout << "argv[1]: " << argv[1] << endl;
    cout << "argv[2]: " << argv[2] << endl; 
  }
  // Output the program with an error message and status if an incorrect 
  // number of command line arguments are provided.
  else 
  {
    cout << "Exactly 2 arguments required" << endl;
    return -1;
  }
  
  // We could use argc to access an arbitrary/unknown number of command 
  // line arguments... the below loop will have the counter variable i go 
  // through string that argv[] points to and output each string.
  for (int i = 0; i < argc; i++)
  {
    cout << "argv[" << i << "] = ";
    cout << argv[i] << endl;
  }
  
  // We could convert the C-style string to a C++ string object as follows...
  string convert1(argv[1]);
  
  // We can still output and use the string
  cout << "Convert1: " << convert1 << endl;

  // But we can use C++ string methods like length 
  cout << "Length: " << convert1.length() << endl;

  return 0;
}