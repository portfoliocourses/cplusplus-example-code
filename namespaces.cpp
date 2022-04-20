/*******************************************************************************
*
* Program: Namespace Examples
* 
* Description: Examples of using namespaces in C++.  For more on namespaces see:
* https://en.cppreference.com/w/cpp/language/namespace
*
* YouTube Lesson: https://www.youtube.com/watch?v=0EtnWcRild4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

// Includes the round function to round a double value
#include <cmath>

// We use namespace std to avoid having to put std:: in front of cout... this 
// is generally OK in smaller applications, but in larger and commercial 
// applications we would generally avoid this as it includes many names which
// may lead to name conflicts.  This will have the scope of everything defined
// below it in this file.
using namespace std;

// Define a namespace named "raw"... namespaces are named scopes that allow 
// us to avoid name conflicts (e.g. two functions with the same name) in the 
// same project by defining functions, classes and other things within a 
// namespace scope (other namespace scopes are free to have functions, classes,
// etc with the same name). 
namespace raw
{
  // Define a print function within the raw namespace that prints a double 
  // value it is provided as an argument without any rounding (i.e. 'raw')
  void print(double number)
  {
    cout << "print raw: " << number << endl;
  }
}

// Define a namespace named rounded
namespace rounded
{
  // We have a print function with the same return value and parameters as in 
  // the raw namespace, which would cause a name conflict if both functions were
  // defined outside of namespaces.  But as they are defined within separate 
  // namespaces, there is no conflict.  This print function uses the round() 
  // function to print a rounded version of the double value it is provided as 
  // an argument.
  void print(double number)
  {
    cout << "print rounded: " << round(number) << endl;
  }
}

// Define a namespace called inception *within* the rounded namespace.  We could
// also define this namespace by putting:
//    namespace inception { .... }
// inside of the namespace rounded { ... } definition above, but this way is 
// nice from the standpoint of code readability.
namespace rounded::inception
{
  // Another version of the print function within this inception namespace 
  // within the rounded namespace, this version prints out "print inception"
  void print(double number)
  {
    cout << "print inception: " << round(number) << endl;
  }
}

int main()
{
  // To access a function from within a namespace we can use the scope 
  // resolution operator :: as below.  In this case we access the print 
  // function defined inside the raw namespace.
  raw::print(25.6789);

  // The using keyword allows us to use a namespace such that we don't need 
  // to use the scope resolution operator to access functions.  The statement 
  // below has a scope in that we can't just call print() as we do below in 
  // another function besides main(). 
  using namespace rounded::inception;
  
  // Because of the above statement, we can call the print function inside 
  // the inception namespace (which is itself inside rounded) by simply using
  // the function name.
  print(25.6789);
  
  // We can give namespaces an alias, and then use that alias to access things
  // defined inside the namespace
  namespace rnd = rounded;
  
  // Use the alias rnd with the scope resolution operator to access the print 
  // function inside the rounded namespace.
  rnd::print(25.678);
  
  return 0;
}