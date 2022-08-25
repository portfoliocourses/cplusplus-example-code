/*******************************************************************************
*
* Program: User Input Validation With A Do-While Loop
* 
* Description: Demonstration of how to perform user input validation with a 
* do-while loop in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zekDB52A4Cw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // Declare an int variable month to store the month the user will enter.
  int month;
  
  // We need to prompt the user to enter in the month at least once, but perhaps
  // multiple times if the user does not enter a valid month from 1-12.  This is
  // a good situation to use a do-while loop, because that's exactly how a 
  // do-while loop works... the body will execute at least once, but perhaps 
  // multiple times if the condition of the loop evaluates to true (i.e. if 
  // it's necessary to execute the loop body again).
  do
  {
    // Prompt the user to enter in a month from 1-12.  We can't use a month like
    // "13" in our program that is outside of this range because it may cause 
    // a bug when working with months as it is an invalid month.
    cout << "Month (1-12): ";
    
    // Store the int that the user enters into the month variable
    cin >> month;
    
    // If the month is outside of the valid range, we output an input validation
    // error message to the user explaining what they've done wrong so that they
    // can avoid this mistake next time.  If the month is less than or equal to 
    // 0 OR it's greater than or equal to 13, we know it's not in the valid 
    // range of months from 1-12.
    if (month <= 0 || month >= 13)
    {
      cout << "Invalid month entered!" << endl;
      cout << "Month must be between 1-12." << endl;
    }
  
  // Continue the loop until a valid month is entered, when the loop body 
  // executes on a 2nd iteration and onward, the user will again be asked 
  // to enter in a valid month, and again they'll be provided with an input 
  // validation error message if they enter in an invalid month.
  }
  while (month <= 0 || month >= 13);
  
  // The loop will stop when a valid month has been entered, and we output 
  // that month here!
  cout << "Month Entered: " << month << endl;
 
  return 0;
}