/*******************************************************************************
*
* Program: While Loops
*
* Description: Examples of using while loops in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=DVEo4jZsKe4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // 'i' is what we call a 'counter variable' that helps us track and manage the
  // number of times that a loop executes
  int i = 1;
  
  // The loop body (the statements contained betwee then { ... } brackets) will 
  // continue to execute so long as the condition i <= 5 is true.  The condition
  // will be checked before the loop body is executed each time, including the 
  // first time it is executed.  So if i were initialized to '10' above then the
  // loop body would NEVER execute because i > 5 and the condition is false.
  while (i <= 5)
  {
    // Output the value of i with each loop iteration
    cout << i << endl;

    // We can use the 'break' keyword to stop the execution of a loop 'early'
    // and in the middle of a loop body... if we uncomment the below line the 
    // loop will stop on its second iteration.
    //
    // if (i == 2) break;
    
    // We can use the 'continue' keyword to skip over executing the remainder of
    // the loop body.  If we uncomment the below if-statement then when i == 2
    // i will be incremented by 2, and the continue keyword will skip over 
    // the final statement in the loop body i = i + 1, and so i will only be 
    // incremented by 2 instead of 1.
    /*
    if (i == 2)
    {
      i += 2;
      continue;
    }
    */
    
    // Increment i by 1 with each loop iteration, this will ensure the loop 
    // condition is eventually false when i eventually reaches the value '6'.
    // If we forgot to modify the counter variable like this, we could have an 
    // infinite loop that NEVER stops because the condition is NEVER false.  You
    // could try removing the below statement to turn this loop into an infinite
    // loop!   
    i = i + 1;
  }

  // Let's make a loop that repeatedly asks the user to enter a positive integer
  // and calculates the sum of all positive integers entered.  The number 
  // variable below will store each number as it is entered, and sum will store 
  // the resulting sum of the numbers entered.
  int sum = 0;
  int number = 0;
  
  // The user is told that they can enter in -1 to quit if they don't wish to 
  // enter in another positive integer.  So we continue the loop so long as 
  // number != -1.  This loop is an indefinite loop, because it is unknown how 
  // many times the loop body will execute at the time the loop is entered.  
  while (number != -1)
  {
    // Prompt the user to a number
    cout << "Enter Positive Integer (Or -1 To Quit): ";
    
    // Store the number entered into the 'number' variable
    cin >> number;
    
    // Use the break keyword to help do some error handling.  If the user enters
    // in a number that is less than or equal to 0, and that number is not -1, 
    // then the input is invalid.  We output an error message in this case and 
    // stop the loop entirely using the break keyword.
    if (number <= 0 && number != -1)
    {
      cout << "Number must be a positive integer" << endl;
      break;
    } 
    
    // if the number is not -1, then the user does not want to quit yet and has
    // entered a positive integer, so we add it to the sum
    if (number != -1) sum = sum + number;
  }
   
  // Output the sum
  cout << "sum: " << sum << endl;
  
  return 0;
}