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

#define TOTAL_NUMBERS 6
#define RANGE_MAX 59

using namespace std;

int main()
{
  // 6   1-49
  //
  // 5 11 21 21 45 48
  
  srand((unsigned int) time(NULL));
  
  int number = 0;
  int numbers[TOTAL_NUMBERS];
  bool unique = false;
  
  for (int i = 0; i < TOTAL_NUMBERS; i++)
  {
    do
    {
      number = (rand() % RANGE_MAX) + 1;
      
      unique = true;
      for (int j = 0; j < i; j++)
        if (numbers[j] == number) unique = false;
      
    } while (!unique);
    
    numbers[i] = number;
    cout << "number " << (i+1) << ": " << number << endl;
  }
  
  return 0;
}
