/*******************************************************************************
*
* Program: Array of Objects
* 
* Description: Example of declaring and initializing an array of objects in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ENnnAjZcuo0  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// A simple Square class
class Square
{
public:

  // squares will have a length and color
  int side_length;
  string color;
  
  // member function to print square data
  void print()
  {
    cout << "side length: " << side_length;
    cout << ", color: " << color << endl;
  }
  
  // the default constructor to initialize a Square object, with no arguments
  Square()
  {
    side_length = 0;
    color = "black";
  }
  
  // constructor that uses two arguments to initialize a Square object
  Square(int set_length, string set_color)
  {
    side_length = set_length;
    color = set_color;
  }
  
  // constructor that uses a single argument to initialize a Square object
  Square(int set_length)
  {
    side_length = set_length;
    color = "black";
  }

};

int main()
{
  // This will initialize the Square elements of the array using the default 
  // constructor... if we have not defined a default constructor (the 
  // constructor with no arguments), then C++ will use an "implicit" default 
  // constructor that initializes the member variables of the object in the 
  // default way.  If we have defined a constructor that accepts 1 or more 
  // arguments and we have NOT defined a default constructor then this will 
  // actually result in an error!
  //
  // Square squares[3];

  // This will use the constructor with one argument to initialize 3 Square 
  // objects for each array element.  As if we initialized the array like this:
  // Square squares[3] = {Square(2), Square(4), Square(8)};
  //
  // Square squares[3] = {2,4,8};

  // We can initialize the array elements using the constructor with two 
  // arguments like this:
  //
  // Square squares[3] = {Square(2,"orange"), Square(4, "red"), Square(8,"green")};
  
  // If we provide less than the required amount of values or constructor calls
  // when initializing the array, the default constructor will be called to    
  // initialize the remaining array elements.  For example the below code would 
  // use the constructor with one argument to initialize the first array element
  // and the default constructor to initialize the remaining two elements:
  //
  // Square squares[3] = {4};

  // will initialize the first element using the single argument constructor,
  // the second element using the two argument constructor, and the third 
  // element using the default constructor
  Square squares[3] = {2,Square(5,"red")};
  
  // print out each square
  for (int i = 0; i < 3; i++)
    squares[i].print();
  
  return 0;
}
