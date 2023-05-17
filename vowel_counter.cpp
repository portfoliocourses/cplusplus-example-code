/*******************************************************************************
*
* Program: Count The Vowels In A String
* 
* Description: Solutions to count the number of vowels in a string.
*
* YouTube Lesson: https://www.youtube.com/watch?v=inqRLHxOC1M 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

int is_vowel(char c);
int count_vowels(string text);

int main()
{
  // A test string with 9 vowels
  string text = "Educational video";
  
  // Call the count_vowels() function to count the number of vowels
  int vowel_count = count_vowels(text);
  
  // Output the total number of vowels as returned by the function
  cout << "Vowel Count: " << vowel_count << endl;
  
  return 0;
}

// There are many different ways that we could count the total number of vowels
// in a string.  
// 
// In the below approach, we create a loop with a counter variable
// i that will go from 0 by 1 up until the last index in the string.  Where 
// text.length() returns the number of characters in the string, and so 
// text.length() - 1 is the index of the last character in the string and so 
// when i == text.length() we will have exceeded the last index of the string.
//
// In the loop body, we use the tolower() function of the cctype library, whcih
// will convert the character text[i] to a lowercase letter and return it if it 
// is an uppercase letter (otherwise the function just returns the character it
// is passed).  By converting uppercase letters of the string to lowercase 
// letters it saves us from having to check for both uppercase and lowercase 
// vowels... i.e. we can check for 'a', 'e', 'i', 'o' or 'u' instead of 
// 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o' or 'u'.
//
// If the character is equal to one of the vowel characters we increment a 
// vowel_count variable that was initially set to 0, and we return the vowel 
// count after the loop is done and we have checked all characters in the 
// string.
// 
/*
int count_vowels(string text)
{
  int vowel_count = 0;
  
  for (int i = 0; i < text.length(); i++)
  {
    char c = tolower(text[i]);
    
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
        c == 'u')
    {
      vowel_count++;
    }
  }
  
  return vowel_count;
}
*/


// Returns true if the character it is passed as an argument is a vowel and 
// falose otherwise.  To handle both uppercase and lowercase vowel characters,
// the character is converted to a lowercase letter (if it is uppercase) using
// the tolower() function of the cctype library.  The function then checks 
// to see if the character is one of 'a', 'e', 'i', 'o' or 'u', returning 
// the result.
int is_vowel(char character)
{
  char c = tolower(character);
  
  return (c == 'a' || c == 'e' || c == 'i' ||
          c == 'o' || c == 'u');
}

// Returns the number of vowels in the string text.  The count_if() function
// returns the number of characters in the string text for which the 
// is_vowel() function returns true when they are passed to the function as 
// an argument.  The text.begin() and text.end() methods return iterators 
// which togther define the range of characters to be passed to the function...
// the iterator returned by text.begin() points to the first character in the
// string and the iterator returned by text.end() points to the 'hypothetical'
// character one beyond the last character in the string, and the is_vowel() 
// function will be called for each character in this range up until but not
// including that hypothetical character text.end() points to (i.e. the 
// is_vowel() function will be called for all characters in the string text).
int count_vowels(string text)
{
  return count_if(text.begin(), text.end(), is_vowel);
}