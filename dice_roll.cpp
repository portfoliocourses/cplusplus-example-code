/*******************************************************************************
*
* Program: Dice Roll Simulator
* 
* Description: Example of simulating a dice roll in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=GBFMCH5Q2_w 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  // Seed the random number generator with the current time to ensure the 
  // possibility of different sequences of random numbers each time the program
  // is executed.
  srand((unsigned int) time(NULL));
  
  // stores each roll of a dice
  int roll = 0;

  // stores the number of sides a dice has
  int sides = 6;

  // stores the total number of dice to be rolled
  int dice = 10;
  
  // Roll 'dice' number of dice by having counter variable i go from 1 up until 
  // dice by 1 with each loop iteration
  for (int i = 1; i <= dice; i++)
  {
    // When performing a roll we want an integer between 1-sides, e.g. 1-6 for
    // a 6 sided dice.
    //
    // rand() will return an integer between 0 and a very large positive 
    // integer, if we take that number and apply % sides we will get a positive
    // integer in the range of 0-(sides-1).  The % operator is called modulus 
    // and returns the remainder of a division operation, and so if we have 
    // rand() % 6 the only possible remainders when the integer rand() returns 
    // by 6 are 0,1,2,3,5, i.e. 0-5.  We then add 1 to this range to shift it 
    // up by 1, so instead of 0-(sides-1) we will have 1-sides.
    //
    roll = (rand() % sides) + 1;
    
    // About the result of the roll (and the 'dice number' i)
    cout << "Dice " << i << ": " << roll << endl;
  }

  return 0;
}