/*******************************************************************************
*
* Program: Default Arguments Example
* 
* Description: Example of using default arguments with functions in C++, also 
* known as default parameters.  
*
* YouTube Lesson: https://www.youtube.com/watch?v=SvMu12tga-g
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

using namespace std;

// add function to add together 3 ints... we supply default arguments of 0 
// for each parameter, notice how we can call the function with 0,1,2 or 3 
// parameters below!  
int add(int a = 0, int b = 0, int c = 0)
{
  return a + b + c;
}

// all default arguments must appear at the end of the parameters, for example
// the below would cause a compilation error...
/*
int add(int a, int b = 0, int c)
{
  return a + b + c;
}
*/

// Overloaded print function with a double 2nd parameter that uses a default 
// argument
void print(int a, double b = 2)
{
  cout << a << endl;
  cout << b << endl;
}

// Overloaded print function, this time with a char 2nd parameter that 
// uses a default argument... so long as we call the functions with 2 arguments
// it will be clear which function we are calling, BUT if we call the function
// print() with one int argument, it will be unclear to C++ which function we 
// are calling as both start with a single int argument!  This is a potential 
// problem we need to be aware of when using default arguments.
void print(int a, char b = 'd')
{
  cout << a << endl;
  cout << b << endl; 
}

int main()
{
  // We can call the function with 0,1,2 or 3 arguments!  If we call it with 
  // 3 arguments then the 3 parameters will be set from left to right with 
  // these 3 arguments.  But if we call it with 2 arguments, then only the 
  // first two parameters a and b will be set to the arguments provided, and 
  // the 3rd argument will be set to the default argument value.  And so on 
  // when 1 or 0 arguments are provided.
  cout << add(1,2,3) << endl;
  cout << add(2,3) << endl;
  cout << add(8) << endl;
  cout << add() << endl;
  
  // as long as we provide both arguments there is no ambiguity as to which 
  // print function is being called
  print(1, 2.0);
  print(1, 'c');
  
  // But if we only supply a single int argument, it's unclear which function 
  // we are calling as both print functions have a default 2nd argument! This 
  // ambiguity will result in an error.
  //
  // print(2);
  
  return 0;
}