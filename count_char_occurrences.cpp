/*******************************************************************************
*
* Program: Count The Occurrences Of A Character In A String
* 
* Description: Program to count the occurrences of a character in a string 
* using C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vdZRW7WkD9Y 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

// returns the number of occurrences of the character 'character' in the string
// 'text'
long count_occurrences(string text, char character)
{
  // use the count() function of the algorithm library to count the occurrences
  // of the character in the range text.begin() to text.end(), i.e. the 
  // beginning to the end of the string
  return count(text.begin(), text.end(), character);
}

int main()
{
  // Declare variables to store the string and the character
  string text;
  char character;
  
  // Prompt the user to enter the string, store it into text
  cout << "String: ";
  getline(cin, text);
  
  // Prompt the user to enter the character, store it into character
  cout << "Character: ";
  cin >> character;
  
  // We could use a for-loop with counter variable i that goes from 0 to the 
  // length of the string, and check the character in the string at each 
  // index in the string text[i] to see if it matches the character, 
  // incrementing a count of occurrences each time it does.
  //
  // int occurrences = 0;
  // for (int i = 0; i < text.length(); i++)
  //  if (text[i] == character) occurrences++;

  // We could also use a range-based for loop to count the characters.
  //
  // int occurrences = 0;
  // for (char c : text)
  //  if (c == character) occurrences++;
   
  // We could also create and call a function to count the occurrences of a 
  // character in a string.  You could comment out this code below and uncomment
  // the above approaches to test them out instead.
  long occurrences;
  occurrences = count_occurrences(text, character);
  
  // Output the number of occurrences of the character in the string
  cout << occurrences << " occurrences" << endl;
  
  return 0;
}