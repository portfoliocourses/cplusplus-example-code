/*******************************************************************************
*
* Program: Lottery Number Generator
* 
* Description: Program to generate random lottery numbers using C++.  
*
* YouTube Lesson: https://www.youtube.com/watch?v=VFqixcyaJEA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

// We generate TOTAL_NUMBERS amount of lottery numbers in the range 1-RANGE_MAX.
// The numbers generated are integers, and each number is unique as lottery 
// numbers are "drawn" from a set of numbers.
#define TOTAL_NUMBERS 6
#define RANGE_MAX 59

using namespace std;

int main()
{
  // Seed the random number generator with the current time to help ensure we 
  // may get a different sequence of random numbers generated each time the 
  // program runs.
  srand((unsigned int) time(NULL));
  
  // Stores each random number generated
  int number = 0;
  
  // Stores the unique lottery numbers generated
  int numbers[TOTAL_NUMBERS];
  
  // Helps to ensure each lottery number is unique
  bool unique = false;
  
  // Outer loop generates TOTAL_NUMBERS amount of lottery numbers
  for (int i = 0; i < TOTAL_NUMBERS; i++)
  {
    // Inner loop ensures a unique lottery number is generated
    do
    {
      // Generates a random integer in the range of 1-RANGE_MAX.  rand() will
      // return a random integer in the range of 0 ... RAND_MAX (a large 
      // positive integer), applying % RANGE_MAX will result in an integer in
      // the range of 0 ... RANGE_MAX-1 because those are the possible 
      // remainders when dividing by RANGE_MAX and the modulus operator % 
      // gives us the remainder of a division operation.  The +1 will shift 
      // this number into a value in the range 1-RANGE_MAX.
      number = (rand() % RANGE_MAX) + 1;
      
      // When unique is set to true it will indicate the random number is 
      // unique.  Start off with the assumption the random number is 
      // unique, loop through all previous 'i' amount of lottery numbers 
      // so far and check for the number... if it's found, set unique to 
      // false as the number is not unique.
      unique = true;
      for (int j = 0; j < i; j++)
        if (numbers[j] == number) unique = false;
      
    // if the number is not unqiue, keep running the loop to try again
    } while (!unique);
    
    // Once we have a unique number, store it into the array and output it
    numbers[i] = number;
    cout << "number " << (i+1) << ": " << number << endl;
  }
  
  return 0;
}
