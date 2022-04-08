/*******************************************************************************
*
* Program: Ternary Operator As An Lvalue
* 
* Description: A little known feature in C++ is that we can use a ternary 
* operator as an lvalue, in this program we use a ternary operator on the left 
* side of an assignment statement as an example.
*
* YouTube Lesson: https://www.youtube.com/watch?v=kobkzbLPUgI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // program will accept grade inputs, keep track of the number of passing 
  // and failing grades
  int grade = 0;
  int pass_total = 0;
  int fail_total = 0;
  
  // keep accepting grade inputs "forever"
  while (true)
  {
    // prompt the user for the grade, store the user input into grade variable
    cout << "Enter Grade (-1 To Quit): ";
    cin >> grade;
    
    // if user enters -1 quit 
    if (grade == -1) break;
    
    // Here we use the ternary operator as an lvalue, and if the grade is 
    // greater than or equal to 50 we increment pass_total by 1, otherwise 
    // we increment fail_total by 1... this is a "hidden feature" of C++, 
    // perhaps it is little known because we cannot do the same with the 
    // ternary operator in C!
    (grade >= 50 ? pass_total : fail_total) += 1;
    
    // output the total passing and failing grades
    cout << "pass_total: " << pass_total << endl;
    cout << "fail_total: " << fail_total << endl;
  }
  
  
  return 0;
}