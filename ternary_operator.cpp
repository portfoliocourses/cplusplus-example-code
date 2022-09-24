/*******************************************************************************
*
* Program: Ternary Operator Example
*
* Description: Example of using the ternary operator in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=riKEIwr8Vew 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // We'll prompt the user to enter a grade between 0-100 and we'll store the
  // entered grade into this grade double variable.
  double grade = 0;

  // Prompt the user to enter a grade between 0-100 and store it into the
  // grade variable
  cout << "Enter Grade (0-100): ";
  cin >> grade;

  // Create a string variable note and assign a congratulations message
  string note = ", Congratulations!";

  // Use the ternary operator to assign a string to the result string variable.
  // The format of the operator is:
  //
  //  (condition) ? true_expression : false_expression
  //
  // And if the condition is true the true_expression is evaluated and this
  // will be the resulting value of the teneray operator, and if the condition
  // is false the false_expression is evaluated and this will be the resulting
  // value of the ternary operator.
  //
  // Here we evaluate whether the grade entered is >= 50, and if it is the
  // expression '"Pass" + note' will be evaluated, and this will be the result
  // of the ternary operator.  The last two operands are themselves expressions
  // which can include operations like + or function calls that will be
  // evaluated.  If the grade is < 50 the third operand will be evaulated (in
  // this case it is simply the string "False") and this will be the result of
  // the ternary operator.  The result of the ternary operator is assigned
  // to the string variable result.
  //
  string result = (grade >= 50) ? "Pass" + note : "Fail";

  // Output the result string
  cout << "Result: " << result << endl;

  return 0;
}