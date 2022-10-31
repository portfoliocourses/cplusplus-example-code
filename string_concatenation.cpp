/*******************************************************************************
*
* Program: String Concatenation Examples
*
* Description: Examples of string concatenation in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ZoAe4HKNMPg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  // Create two strings
  string firstName = "Margaret";
  string lastName = "Hamilton";

  // We can use the + operator to concatenate these strings and create a new
  // string... we can also use a string literal together with a string object
  // and have multiple + operators in one expression.
  string fullName = firstName + " Heafield " + lastName;

  // Output the concatenated full name string
  cout << fullName << endl << endl;



  // We can sometimes use the + operator with char values/variables and
  // C-style strings
  string s1 = "ABC";
  char c1 = 'D';
  char CStyleString[] = "DEF";

  // We can concatenate a string with a char
  string test = s1 + D;

  // We can also concatenate a string with a char literal
  // string test = s1 + 'D';

  // We can also conatenate a string with a C-style string
  // string test = s1 + CStyleString;

  // We cannot use + with a string literal and a char... we will get a warning
  // and an incorrect string will result
  // string test = "ABC" + 'D';

  // We cannot use + with two string literals either
  // string = "ABC" + "DEF"

  // Output the result of the above concatenation
  cout << test << endl << endl;



  // We can also use the .append() member function of string objects, for
  // example with these two strings...
  string string1 = "123";
  string string2 = "456";

  // .append() will concatenate string1 and string2 and the result will be
  // stored into string1 (technically this is an append operation but the
  // result is similar to concatenation).
  string1.append(string2);

  // Output string1 after the above .append() call
  cout << string1 << endl << endl;



  // We can store C-style strings into char arrays in C++ (i.e. sequences of
  // chars terminated by a null terminator character \0 which signifies the
  // end of the string).  Here we purposely make the CString1 char array 7
  // chars in length so that it may hold the concatenation of the string in
  // CString1 and the string in CString2.
  char CString1[7] = "HIJ";
  char CString2[] = "KLM";

  // The strcat() function from the cstring library will concatenate CString1
  // and CString2 and store the result into CString1.
  // strcat(CString1, CString2);

  // The strncat() function will do the same, though its 3rd argument allows
  // us to specifiy a maximum number of chars that may be copied from CString2
  // into CString1.
  strncat(CString1, CString2, 2);

  // Output the resulting string in CString1 after the above call to strncat()
  // (or strcat()).
  cout << CString1 << endl << endl;

  return 0;
}