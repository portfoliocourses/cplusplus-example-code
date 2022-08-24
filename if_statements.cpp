/*******************************************************************************
*
* Program: If Statement Example
*
* Description: Example of how to use an if statement in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zS651dNfa6c
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // Try initializing the variable price to different values to see the effect
  // it has on which "branch" of the if-statement below executes.  Normally
  // price would be set due to some calculation or user input and would vary
  // across different runs of the program, and we would have an if-statement
  // to dynamically alter the program behaviour at runtime by executing
  // different blocks of code in response to different price values.
  int price = 40;

  // If the condition price <= 90 evaluates to true, this block of code will
  // execute, and then control flow will jump to the cout statement below
  // the entire control structure.
  if (price <= 90)
  {
    cout << "price <= 90" << endl;
    cout << "Good deal!" << endl;
  }
  // If the condition above is false, this condition will then be evaluated
  // next, and if it is true, the statement below it will be executed before
  // control flow jumps to the cout stateemnt below the control structure.
  // Notice that because we only have a single statement the { } brackets are
  // not required.  Also notice that this could be a potential bug... if the
  // price is 40, then we would want to output that the price is an "Amazing"
  // deal. But we would never reach this else-if branch because the above
  // condition would be true and we would output "Good deal!" instead!  So
  // we really need to be mindful that the conditions are evaluated in order
  // from top to bottom, and the block of code for the first condition that
  // evaluates to true is what will execute, and only that block of code!
  else if (price <= 50)
    cout << "Amazing deal!" << endl;
  // We can have as many else if branches and conditions as we like...
  else if (price >= 200)
  {
    cout << "Very bad price!" << endl;
  }
  // If none of the above conditions evaluate to true, the block of statements
  // associated with the else branch will execute.  Also note that when our
  // block of code is only a single statement we can put it on the same line as
  // the else keyword (and same with else if and if branches as well).
  else cout << "Not a good deal!" << endl;

  // Note that only one of the above branches will execute, after which
  // execution will 'jump' down here to the first statement after the control
  // structure.
  cout << "If Statement Done!" << endl;

  return 0;
}