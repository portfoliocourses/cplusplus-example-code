/*******************************************************************************
*
* Program: Do While Loop Examples
*
* Description: Examples of using do-while loops in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=t-c1C70j9dY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // You can uncomment and comment out the below examples to test them out
  // by removing and adding wrapping /*  */ multiline comments.


  /*

  // i will be our loop counter variable that will help us to manage the
  // number of times the loop executes, we initialize the variable to 0
  int i = 0;

  // A do while loop allows us to execute a block of code multiple times much
  // like other loops, except with a do-while loop the block of code (the
  // loop body) will execute once.
  do
  {
    // Output the current value of i
    cout << "i: " << i << endl;

    // increment i by 1
    i++;

  } while (i < 3);  // loop condition

  // The loop condition is "i < 3".  The loop condition will be evaluated after
  // each time the loop body executes.  If the condition evaluates to true the
  // loop body will execute again, if it is false the loop will stop and
  // execution will jump to the first statement after the loop (see below).

  cout << "Loop done!" << endl;

  */



  /*

  // With a do-while loop, the loop body will execut at least once, even if
  // the condition is false as it would be here with i initialized to 10.

  int i = 10;

  do
  {
    cout << "i: " << i << endl;
    i++;

  } while (i < 3);

  cout << "Loop done!" << endl;

  */


  /*

  // In contrast with a while loop the loop body will never execute in this
  // case as the condition is evaluated FIRST before the loop body executes.

  int i = 10;

  while (i < 3)
  {
    cout << "i: " << i << endl;
    i++;
  }

  cout << "Loop done!" << endl;

  */


  /*

  // The break keyword can be used to stop a loop "early".  Here when i is equal
  // to 1 we stop the loop with "break".  Control-flow will jump below the
  // do-while loop after the break is encountered.

  int i = 10;

  while (i < 3)
  {
    cout << "i: " << i << endl;
    if (i == 1) break;
    i++;
  }

  cout << "Loop done!" << endl;

  */


  /*

  // The continue keyword will skip over the remainder of a loop body.  So in
  // this case when continue is encountered, we will not execute the statement
  // i++, so that after the first iteration of the loop is complete we will
  // have that i is equal to 2.

  int i = 10;

  while (i < 3)
  {
    cout << "i: " << i << endl;
    if (i == 0)
    {
      i += 2;
      continue;
    }
    i++;
  }

  cout << "Loop done!" << endl;


  */

  // Do-while loops are useful relative to other loops in situations where we
  // need to do something at least once.  So for example with user input
  // validation.  For example let's say we need the user to enter a month
  // between 1-12, we must ask them at least once to enter the month, but
  // possibly more times if the month entered is invalid.

  // Declare a month variable to store the month the user enters
  int month = 0;


  do
  {
    // Prompt the user to enter the month, store the entered month into the
    // variable month.  This will happen at least once as we are using a
    // do-while loop.
    cout << "Month (1-12): ";
    cin >> month;

  // Continue the loop so long as the month is out of range, prompting the
  // user continually until they enter in a valid month.
  } while (month < 1 || month > 12);

  return 0;
}
