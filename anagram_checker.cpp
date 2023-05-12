/*******************************************************************************
*
* Program: Check If Two Strings Are Anagrams
* 
* Description: Check if two strings (words, phrases, etc.) are anagrams using 
* C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=asQU7yR7W9o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

bool isAnagram(string string1, string string2);

int main()
{
  // Anagrams are strings that contain the same characters, but not necessarily
  // in the same order.
  //
  // So for example the strings "silent" and "listen" are anagrams because they 
  // both contain 1 s, 1 i, 1 l, 1 e, 1 n and 1 t character.
  //
  // We can check if two strings are anagrams by sorting them alphabetically and
  // comparing them for equality.  If we sort "silent" and "listen" 
  // alphabetically we will get "eilnst" in both cases!
  //
  // silent - eilnst
  // listen - eilnst
  
  // create test strings
  string test1 = "listen";
  string test2 = "silent"; 

  // Check if the two strings are anagrams using the isAnagram() function and 
  // output the result...
  if (isAnagram(test1, test2))
  {
    cout << "Strings are anagrams" << endl;
  }
  else
  {
    cout << "Strings are not anagrams" << endl;
  }
  
  return 0;
}

// Returns true if string1 and string2 are anagrams and false otherwise
bool isAnagram(string string1, string string2)
{
  // It's more efficient and quicker to check if two strings have the same 
  // length than to sort them.  So before sorting the strings, we check to 
  // make sure they even have the same length, because if they don't we can
  // very quickly and efficiently decide that they are no anagrams (they 
  // cannot possibly have the same characters if they don't even have the same
  // *number* of characters).
  if (string1.length() != string2.length())
  {
    return false;
  }
  
  // Sort the strings.  The sort() function from the algorithm library will 
  // sort a string alphabetically when we pass it the iterators returned by 
  // .begin() and .end() as the first and second arguments.  These iterators 
  // define a range that includes every character in the string, and the sort()
  // function will sort the characters alphabetically within that range.  The 
  // .begin() iterator points to the first character in the string and the 
  // .end() iterator points to the character 'one beyond' the last character 
  // in the string, and the "range sorted" will then be from the first character
  // in the string to the last character in the string.
  sort(string1.begin(), string1.end());
  sort(string2.begin(), string2.end());

  // Return true/false based on whether the strings are equal or not.  
  return string1 == string2;
}