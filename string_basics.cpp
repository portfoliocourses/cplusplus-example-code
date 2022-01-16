/*******************************************************************************
*
* Program: String type Basics
* 
* Description: The basics of using the string type in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=-5xVrsBguHg  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

// even though some C++ implementations will automatically include the string 
// library for us, we should still include it to make our program more portable
#include <string>

using namespace std;

int main()
{
  // create a string variable called test1, assign a string literal to it
  string test1 = "abcdefghi";
  
  // we can output strings using cout and <<
  cout << test1 << endl;
  
  // output the size of the string (i.e. number of characters)
  cout << "size: " << test1.size() << endl;
  
  // we can access individual characters at each index in the string with [] 
  // and .at()
  cout << "test1[1]: " << test1[1] << endl;
  cout << "test1.at(3): " << test1.at(3) << endl;
  
  // we can modify individual characters in the string with the [] syntax too
  test1[2] = 'C';
  cout << test1 << endl;
  
  // there are several ways to concatenate and append strings
  test1 = test1 + "jklmnop";
  test1 += "qrstu";
  test1.append("vwxyz");
  cout << test1 << endl;
  
  // the length() function is a synonym for size(), it returns the same value
  cout << "length: " << test1.length() << endl;
  
  // we can create more string type variables
  string test2 = "123";
  string test3;
  
  // we can concatenate string variables, not just string literals
  test3 = test1 + test2;
  cout << "test3: " << test3 << endl;
  
  // empty() will check if a string is empty (test3 should not be)
  if (test3.empty()) cout << "test3 is empty" << endl;
  else cout << "test3 is not empty" << endl;
  
  // clear() will make a string empty
  test3.clear();
  cout << "test3: " << test3 << endl;
  
  // test3 should now be empty!
  if (test3.empty()) cout << "test3 is empty" << endl;
  else cout << "test3 is not empty" << endl;
  
  // we can convert values like ints and doubles to strings using to_string()
  string test4 = to_string(-10.5);
  cout << test4 << endl;
  
  // we can convert double values to strings using stod(), other functions 
  // exist to convert other types as well
  double number = stod(test4);
  cout << "number: " << number << endl;
  
  // many functions exist for working with strings, for example we can 
  // extract a substring from a string using substr, which in this case 
  // extracts 4 characters starting from the character at index 2 (i.e. "test")
  string test5 = "A test string";
  string sub = test5.substr(2,4);
  cout << "sub: " << sub << endl;
  
  // we can store use input into a string type variable, for example a name
  string name;
  cout << "Enter name: ";

  // will only store the string up until the first space character, so a 
  // name like 'kevin browne' will only be stored as 'kevin' into name  
  //cin >> name;

  // will store the string up until the first newline character into name, 
  // so a name like 'kevin browne' will be stored entirely
  getline(cin, name);

  // output the name
  cout << "Name: " << name << endl;

  return 0;
}