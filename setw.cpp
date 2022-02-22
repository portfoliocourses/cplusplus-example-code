/*******************************************************************************
*
* Program: set Stream Manipulator
* 
* Description: Demonstration of how to use the setw stream manipulator in C++ 
* to output data into fields with a specified character width.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ytFT-1s7EWo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // A basic example of using setw.  setw(5) will cause the next value in the 
  // stream to output into a field of width 5 characters.  We can use left/right
  // to modify the alignment of that field, and setfill to set a different 
  // fill character than the default space character.
  //
  // Uncomment the below code to try it out (though setting the fill character 
  // to * will make the table below output with stars instead of spaces). 
  //
  /*
  int area = 123;

  cout << left << setw(5) << setfill('*');
  cout << area << endl;
  cout << endl << 12345 << endl;
  */
  
  // One practical use case for setw is to output a table of data such that 
  // each column has a set, consistent width.  Let's go over an example!

  // Output a table heading
  cout << endl;
  cout << "Rectangle Area Table";
  cout << endl << endl;
  
  // Create a table with 3 columns: length, width and area.  The table will 
  // present the rectangle areas for rectangles with the associated lengths 
  // and widths.  We'll make the length and width columns 10 characters in 
  // width and left-aligned, and the area column 4 characters in width and 
  // right-aligned.  We'll create this format using setw and left/right as 
  // below, and then we'll use these stream manipulators in exactly the same
  // way to output the DATA for the fields of the table.
  //
  cout << left;
  cout << setw(10) << "Length";
  cout << setw(10) << "Width";
  cout << right;
  cout << setw(4) << "Area";
  cout << endl;
  
  // As our table is 24 characters in width (10+10+4), output 24 * characters
  // to separate the column headings from the data
  for (int i = 0; i < 24; i++) cout << "*";
  cout << endl;
  
  // go over a range of lengths from 5 to 25 by 5
  for (int length = 5; length <= 25; length += 5)
  {
    // go over a range of widths from 2 to 10 by 2
    for (int width = 2; width <= 10; width += 2)
    {
      // output length and width into left-aligned 10 character width fields 
      cout << left;
      cout << setw(10) << length;
      cout << setw(10) << width;

      // output the area into a right-aligned 4 character width field
      cout << right;
      cout << setw(4) << length * width;

      // output end line so the next row of output starts on the next line
      cout << endl;
    }
  }
  
  // end the program with some new/blank lines
  cout << endl << endl;
  
  return 0;
}