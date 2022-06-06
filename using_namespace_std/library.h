// A simple libary defining a Simple class

#include <iostream>

// It shouldn't be a problem to use 'using namespace std;' in small projects 
// done by one person, but where it REALLY becomes a bad practice is when 
// we use it in header files!  ANYTHING that includes 'library.h' will have
// the entire standard namespace brought into the global namespace, 
// heavily 'polluting it' and restricting the ability to create things with 
// the many names that have already been used in the std namespace!  So 
// we especially don't put 'using namespace std' into header files.

using namespace std;

// Simple class a member function
class Simple
{
public:
  void func();
};