/*******************************************************************************
*
* Program: For Loop Examples
*
* Description: Demonstration of how to use for loops in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=8CdKMqW4LC4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // You can comment out the different examples below by adding and removing
  // the /* ...  */ comments, this will let you try out the different
  // examples one at a time.


  // A for loop is an alternative to using a whie loop.  Here we use a while
  // loop to output the integers from 1-5.  We use a counter variable i that
  // is first initialized before the loop runs, the counter variable is
  // checked during the loop condition, and the counter variable is modified
  // at the end of the loop.  This is a very common pattern in programming
  // loops.  But if the while loop body is very large, we would need to scroll
  // around in the source code file to figure out how the loop is working,
  // as the initialization, condition, and updating of the counter variable
  // would not all be visible at once.  This information is important to
  // understand how a loop is going to behave.  A for loop gives us a construct
  // that allows us to put all this important information on a single line.
  /*
  int i = 1;

  while (i <= 5)
  {
    cout << "i: " << i << endl;
    i++;
  }
  */

  // An equivalent for loop looks like this.  The first statement 'int i = 1;'
  // in the for ( ... ) brackers is the initialization statement, the
  // condition is i <= 5, and the update statement is i++.
  for (int i = 1; i <= 5; i++)
  {
    cout << "i: " << i << endl;
  }

  // The control-flow of a for-loop like the above is given below.  The
  // for loop has 4 parts:
  //
  // - initialization statement
  // - condition
  // - update statement
  // - body
  //
  // And those are found in these places:
  //
  // for (init; condition; update)
  // {
  //    body
  // }
  //
  // First the initialization statement will execute, then the condition will
  // be checked.  If the condition is false the loop will stop, if the condition
  // is true the loop will continue.  Next the body will exectute, followed by
  // the update statement.  And then the loop will "loop back" to checking
  // the condition again.
  //
  // init
  //   |
  // condition <--
  //   |          |
  // body         |
  //   |          |
  // update ------
  //


  // Notably just because a for loop is typically used as in the above example,
  // we aren't required use it this way.  We can leave out the initialization
  // and upate statements, we can do things like increment the counter variable
  // in the loop body, and all of this is allowed.
  //
  /*
    int i = 1;
    for ( ; i <= 5; )
    {
      cout << "i: " << i << endl;
      i++;
    }
  }
  */

  // We can also have for loops with more than one counter variable, we could
  // update both variables in the update statement by using a , comma.
  //
  /*
  for (int i = 0, j = 1; i <= 5 && j <= 20 ; i++, j += 5)
  {
    cout << "i: " << i << ", j: " << j << endl;
  }
  */

  return 0;
}