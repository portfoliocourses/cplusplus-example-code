/*******************************************************************************
*
* Program: Number Guessing Game
* 
* Description: Example of a number guessing game in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=HTv-TgYaXI8 
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
  // Seed the random number generator with the current time as returned by 
  // time() when it is passed NULL, in order to ensure a different random 
  // number seed each time the program is executed.
  srand((unsigned int) time(NULL));
  
  // Generate a random number between 1-100, store it into the number variable.
  // rand() will return a random int value between 0 and a large number, mod 100
  // will turn that number into a 0-99 range, and +1 shifts that range to 1-100!
  int number = (rand() % 100) + 1; 
  
  // Stores the guess the user enters
  int guess = 0;
  
  do
  {
    // Prompt the user to enter the guess, store it into guess
    cout << "Enter Guess (1-100): ";
    cin >> guess;
    
    // Tell the user to guess higher or lower or that they won based on 
    // comparing the guess to the number.
    if (guess > number)
      cout << "Guess lower!" << endl;
    else if (guess < number)
      cout << "Guess higher!" << endl;
    else
      cout << "You won!" << endl;
      
    // Keep the game going by having the user guess again so long as they did 
    // not guess correctly.
  } while (guess != number);
   
  return 0;
}