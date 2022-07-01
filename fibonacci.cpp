/*******************************************************************************
*
* Program: Output The Fibonacci Sequence
*
* Description: Output the Fibonacci sequence using C++.  See the Wikipedia 
* article on Fibonacci sequences for more information on the algorithm to 
* produce the sequence: https://en.wikipedia.org/wiki/Fibonacci_number.
*
* YouTube Lesson: https://www.youtube.com/watch?v=WeG6W2Qwsno 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // term1 and term2 will store the previous two terms in the sequence, we 
  // initialize them to 0 and 1 as these are the first two terms in the 
  // sequence
  int term1 = 0;
  int term2 = 1;

  // n will store the number of terms in the sequence to generate
  int n = 0;

  // nextTerm will store the next term in the sequence
  int nextTerm = 0;
  
  // Prompt the user to enter the number of terms in the sequence to generate,
  // store the value entered into n
  cout << "Number Of Terms: ";
  cin >> n;
  
  // The program can't really do anything interesting if the number of terms to
  // generate is less than or equal to 2, so we check for this an exit with 
  // an error message and status if this is the case.
  if (n <= 2)
  {
    cout << "Number of terms must be >= 3!" << endl;
    return 1;
  }
  
  // Output the first two terms in the sequence
  cout << term1 << ", " << term2 << ", ";
  
  // Loop counter variable will have the loop iterate from 3 ... n (the number
  // of terms to generate), we start off at '3' because we've already output 
  // the first two terms in the sequence.
  for (int i = 3; i <= n; i++)
  {
    // find the next term in the sequence and output it
    nextTerm = term1 + term2;
    cout << nextTerm;

    // for all but the last term in the sequence we output a comma after it
    if (i != n) cout << ", ";

    // update the prior two terms in the sequence for the next loop iteration 
    // where we'll find the NEXT term in the sequence
    term1 = term2;
    term2 = nextTerm;
  }

  // Output an end line (i.e. newline) after the sequence
  cout << endl;
  
  return 0;
}

// Fibonacci sequence
// ------------------
//
// - Starting two numbers: 0, 1
//
// - Additional numbers: sum of the two prior numbers
//
// Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
//           |     |                          |
//      term 1     term 3                     term 11
//
//