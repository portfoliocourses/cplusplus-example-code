/*******************************************************************************
*
* Program: Find The Third Angle Of A Triangle
* 
* Description: Program to find the third angle of a triangle when the first two 
* angles have been provided from user input with C++.  The program utilizes the 
* property that the sum of the angles of a triangle must equal 180 degrees.
*
* YouTube Lesson: https://www.youtube.com/watch?v=cX2qv_YG7WU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // Declare variables to store angle1 and angle2
  double angle1, angle2;
  
  // Prompt the user to enter angle1, store the value entered into angle1
  cout << "Enter angle1: ";
  cin >> angle1;
  
  // Prompt the user to enter angle2, store the value entered into angle2
  cout << "Enter angle2: ";
  cin >> angle2;
  
  // Ensure angle1 and angle2 are valid before computing angle3... angle1 and 
  // angle2 must both be between 0-180, and we can't have that angle1 + angle2
  // is greater than or equal to 180 otherwise angle3 will be negative or zero!
  if ((angle1 > 0 && angle1 < 180) && (angle2 > 0 && angle2 < 180) &&
      ((angle1 + angle2) < 180))
  {
    // The sum of the 3 triangle sides must be 180, so if we know angle1 and 
    // angle2 are valid then angle3 must be 180 - angle1 - angle2.
    double angle3 = 180 - angle1 - angle2;

    // Output angle3
    cout << "angle3: " << angle3 << endl;
  }
  // Output an error message in the case angle1 and/or angle2 are invalid
  else cout << "angle1 and/or angle2 are invalid!" << endl;
  
  return 0;
}