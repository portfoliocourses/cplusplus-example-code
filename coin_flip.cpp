/*******************************************************************************
*
* Program: Coin Flip Simulator
* 
* Description: Example of simulating a coin flip in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ZSOgJmRQfdA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

// Use preprocessor constants to define HEADS and TAILS
#define HEADS 0
#define TAILS 1

using namespace std;

int flipCoin();
string flipCoin2();

int main()
{
  // Seed the random number generator with the current time to ensure the 
  // possibility of different sequences of random numbers each time the program
  // is executed.
  srand((unsigned int) time(NULL));
  
  // Test out the flipCoin() function.  Output a sequence of 10 simulated coin
  // flips.
  for (int i = 0; i < 10; i++)
  {
    if (flipCoin() == HEADS) cout << "Heads" << endl;
    else cout << "Tails";
  }

  // Counter variables for keeping track of the total number of heads and tails
  // flipped in a sequence of flips.
  int total_heads = 0;
  int total_tails = 0;
  
  // Test out the flipCoin2() function.  Output the sequence of 10 simulated 
  // coin flips, while keeping track of the number of heads and tails flipped 
  // using the above counter variables.
  for (int i = 0; i < 10; i++)
  {
    if (flipCoin2() == "Heads")
    {
      total_heads++;
      cout << "Heads" << endl;
    }
    else
    {
      total_tails++;
      cout << "Tails" << endl;
    }
  }
  
  // Output the total number of heads and tails flipped
  cout << "Total Heads: " << total_heads << endl;
  cout << "Total Tails: " << total_tails << endl;
  
  return 0;
}

// Returns HEADS (0) or TAILS (1) randomly.  The rand() function returns an 
// integer between 0 and a large positive integer.  The modulus operator % 
// returns the remainder of a division operation.  If we take any integer 
// between 0 and a large positive integer and divide it by 2 the only 
// possible remainders are 0 and 1.  In this way, we can randomly generate 
// either 0 for HEADS or 1 for TAILS.
int flipCoin()
{
  if (rand() % 2 == 0) return HEADS;
  else return TAILS;
}

// Returns the string "Heads" or "Tails" instead of an int representation, the
// logic for using rand() to randomly generate one of the two possibilities  
// is the same.
string flipCoin2()
{
  if (rand() % 2 == 0) return "Heads";
  else return "Tails";
}