/*******************************************************************************
*
* Program: Switch Statements
*
* Description: Examples of using switch statements in C++.  See more detailed
* documentation on switches in C++ here
*  https://en.cppreference.com/w/cpp/language/switch
*
* YouTube Lesson: https://www.youtube.com/watch?v=loS5VEc0LJg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // A typical switch example

  // declare and initialize a value variable to 2
  int value = 2;

  // The switch accepts a 'condition' expression which must evaluate to an
  // integral or enumeration type, which means we can use types like int
  // or char, but not floats or doubles.  It's a bit more complicated than
  // this, see the link above for more details.  We could put something like
  // "value + 1" here as well, and that would also work as it evaluates to
  // an int value.
  switch (value)
  {
    // We have cases with specific matching values.  When the condition matches
    // the value, execution of satements below the case will occur.  Execution
    // of statements will continue until the first 'break' is encountered OR
    // until the end of the switch body is reached.  It is very typical to see
    // a break statement as the final statement after each group of statements
    // after a case as the statements are intended to execute for each case.
    case 1:
    cout << "Case 1 Matches!" << endl;
    break;

    // We can put control structures like if-statements in the switch.  In the
    // below case we do not have a break statement at the end of the group of
    // statements associated with the case.  Execution will thus "fall through"
    // to the statements of the default case, in the situation that case 2
    // matches, executing those statements as well!  We call this fallthrough
    // logic and it is a key feature of switches.  We can *intentionally* use
    // fallthrough logic, so that if one case matches, another case's (or
    // multiple case's) statements are ALSO executed.  Fallthrough logic can
    // however make switch statements prone to logic bugs, as if a programmer
    // forgets the break at the end of a group of statements for a case,
    // unintended behaviour will result, and yet the compiler will not provide
    // an error message as the language allows for this.  This makes the bug
    // more likely to occur by accident, and more difficult to find.
    case 2:
    cout << "Case 2 Matches!" << endl;
    if (value >= 1)
      cout << "Value >= 1" << endl;

    // The statements underneath the default case will execute when no other
    // cases have matched.
    default:
    cout << "Default Case!" << endl;
    cout << "Value: " << value << endl;
  }

  // After the switch is done, control flow will drop below the switch
  cout << "Value after: " << value << endl;



  // Examples of other switch features

  /*

  // As of C++17 we can use an initialization statement in our switch like this,
  // typically used to declare and initialize a variable used in the switch.
  // After the semicolon comes the expression/condition for which the switch
  // will try to find a matching case.
  switch (int value = 1; value)
  {
    case 1:
    cout << "Case 1 Matches!" << endl;
    break;

    // Some compilers will allow us to output a warning message when fallthrough
    // logic is detected (i.e. when a break is missing).  This might be helpful
    // for preventing logic bugs, as the compiler could warn us when we forget
    // to use a break.  But if we intentionally wanted to use fallthrough logic,
    // we would not want this warning.  The [[fallthrough]] attribute allows us
    // to supress this warning from the compiler.
    case 2:
    cout << "Case 2 Matches!" << endl;
    if (value >= 1)
      cout << "Value >= 1" << endl;
    [[fallthrough]];

    default:
    cout << "Default Case!" << endl;
    cout << "Value: " << value << endl;
  }

  // In the above example 'value' would have the scope of the switch statement,
  // and so while we could access it IN the switch statement we could not
  // access it outside the switch statement such as here...
  cout << "Value after: " << value << endl;

  */

  return 0;
}