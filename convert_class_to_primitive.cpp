/*******************************************************************************
*
* Program: Convert User-Defined Class Type To Primitive Type
* 
* Description: Demonstration of how to convert a user-defined class type to 
* a primitive type (like double, char, etc.) in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zRZLwzoQ1Fo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// create a simple Grade class
class Grade
{

// Grade objects will have a single member variable grade intended to be set 
// to values like 92.45, 45.35, etc.
private:
  double grade;
  
public:
  
  // constructor for initializing the grade member variable
  Grade(double grade) : grade(grade) {}
  
  // operator type() allows us to create a function that will return a value 
  // of the specified type, defining how object instances will be converted to 
  // the type.
  //
  // In this case we define how to convert a Grade object to a double value by 
  // simply return the grade member variable's value...
  operator double()
  {
    return grade;
  }
  
  // In the chase of converting a Grade object to a char, we return a "letter 
  // grade" A,B,C,D or F depending on the range of the grade value
  operator char()
  {
    if (grade >= 80) return 'A';
    else if (grade >= 70) return 'B';
    else if (grade >= 60) return 'C';
    else if (grade >= 50) return 'D';
    else return 'F';
  }
};

int main()
{
  // instantiate a Grade object
  Grade grade1(93.22);
  
  // assigning the Grade object instance to a double variable will cause the 
  // type converstion to occur as we specified with operator, resulting in the 
  // value 93.22
  double dbl_grade1 = grade1;
  cout << "dbl_grade1: " << dbl_grade1 << endl;
  
  // assigning the Grade object instance to a char variable will cause the 
  // type conversion to occur as we specified with operator, resulting in the 
  // value 'A'
  char chr_grade1 = grade1;
  cout << "chr_grade1: " << chr_grade1 << endl;
  
  return 0;
}