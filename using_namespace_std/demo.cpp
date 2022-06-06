/*******************************************************************************
*
* Program: Bad Practice Example: using namespace std
* 
* Description: Demonstration of why 'using namespace std;' is often a bad 
* practice in C++.  Using 'using namespace std' isn't bad in small projects 
* created by one person, but it can be really bad if we start using it in 
* header files of large multi-file projects as it pollutes the global namespace
* and leads to name conflicts.
*
* YouTube Lesson: https://www.youtube.com/watch?v=8gZNFt0YEZI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// iostream includes cout, endl, which are in the std (standard) namespace
#include <iostream>

// algorithm includes a function template in which is also in the std namespace
#include <algorithm>

// library.h includes a 'using namespace std;' statement, and by including 
// library.h we actually pollute the global namespace of this file as well!
#include "library.h"

// A simple namespace ns1 with a function func1 that outputs the namespace it 
// is from
namespace ns1
{
  void func1()
  {
    std::cout << "func1() ns1" << std::endl;
  }
}

// Another namespace ns2 with a function with the same name (and return type, 
// and parameters), which would cause an issue if it were not in its own 
// namespace
namespace ns2
{
  void func1()
  {
    std::cout << "func1() ns2" << std::endl;
  }
}

// This will cause func1 to be brought into the global namespace so it can be 
// used without using ns1:: 
using namespace ns1;

// We define ANOTHER function called func1 (again with the same return type and
// parameters) this time in the global namespace.  If we try to call func1() 
// (without ns1::func1() or ns2::func2()) it will now be ambiguous which func1()
// we are calling.  This will cause a compiler error.
void func1()
{
  std::cout << "func1() global" << std::endl;
}

// Define a function template min with the same return type and parameter as 
// the function template defined inside algorithm.h.  BECAUSE library.h contains
// the statement 'using namespace std' and because we include library.h in this 
// file, the min function template from the standard namespace will be brought 
// into the global namespace, causing a conflict with this function template 
// and leading to compiler errors due to ambiguity! 
template <class T>
const T& min(const T& a, const T& b)
{
  // what the function does doesn't really matter for this example!
  return a;
}

int main()
{
  // We can call the func1() functions in ns1 and ns2 namespaces unambiguously 
  // by using the namespace name and the scope resolution operator
  ns1::func1();
  ns2::func1();
  
  // BUT if we try to call func1() in the global namespace there are TWO func1()
  // functions (with the same return type and parameters) because we defined a 
  // func1() in the global namespace AND we have 'using namespace ns1' which 
  // brings the func1() from the ns1 namespace into the global namespace as 
  // well, causing an ambiguity which will result in a compiler error.  Note 
  // that functions having the same name might not be an issue if the return 
  // type and/or parameters are different due to a different concept called 
  // function overloading.
  func1();
  
  // A similar situation occurs here... this time because we included library.h
  // which itself has the statement 'using namespace std' the min function 
  // template is brought into the global namespace, when we also have a min 
  // function template defined above the in the global namespace, again causing
  // an ambiguity and a compiler error!
  std::cout << "min: " << min(4,5) << std::endl;
  
  // Use the simple class defined in the library
  Simple simple;
  simple.func();
  
  return 0;
}
