/*******************************************************************************
*
* Program: Convert A Number To A String
* 
* Description: Examples of two techniques for converting a numeric value (int,
* float, double, etc.) to a string in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=gCxZIhhf4V8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  // Technique #1: Use to_string() function
  
  // Declare a double variable and assign it the value 5.25
  double number1 = 5.25;
  
  // We can provide the to_string() function with a double value (or any other
  // numeric value type such as int, float, long) and it will return a string
  // representation of that value.  Here we store that string into string1.
  // Note that we need to include the string library above to be able to use
  // the to_string() function.
  string string1 = to_string(number1);
  
  // Output string1 to verify the conversion was successful
  cout << string1 << endl;
  
  // The format of the number in the string will be the same as if we had called
  // sprintf() like this to perform a 'conversion', with the buffer large 
  // enough to store the resulting string.
  // sprintf(buffer, "%f", number1);

  // to_string() is only available in versions C++11 and onwards of the language
  // so it will not work in earlier versions of C++.  We could use the technique
  // below instead as an alternative.


  // Technique #2: Use stringstream object

  // Declare an int variable and assign 20 to the variable
  int number2 = 20;
  
  // Declare a stringstream object.  This will give us a stream we can use the
  // stream extraction and stream insertion operators with similar to how we 
  // use cin and cout.
  stringstream convert;
  
  // Use the stream insertion operator to insert the value stored in number2 
  // on to the stream
  convert << number2;
  
  // Declare a string variable string2 to store the converted value
  string string2;
  
  // Use the stream extraction operator to extract the number from the stream
  // and store it as a string into string2
  convert >> string2;
  
  // Output string2 to confirm the conversion was successful
  cout << string2 << endl;

  // This technique will work with the other numeric types (float, double, 
  // long, etc.), and will work with older versions of C++.

  return 0;
}