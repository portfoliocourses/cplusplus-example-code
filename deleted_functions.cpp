/*******************************************************************************
*
* Program: Deleted Functions Demonstration
*
* Description: Examples of using deleted functions in C++.  Deleted functions
* are declared using the delete specifier '= delete;' at the end of a function
* declaration, and the compiler will disable a deleted function.
*
* YouTube Lesson: https://www.youtube.com/watch?v=-PQRjsX_1i8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// Create a simple class where each object should have a unique id
class Unique
{

// the private member variable id will store each object's unique id
private:
  int id;

public:

  // Use a class variable next_id to keep track of the 'next id' to give
  // to an object when it is created, we initialize it to 1 below the class.
  static int next_id;

  // When a Unique object is instantiated we set its id to the current value
  // of next_id and then increment next_id so that the next object created
  // will use the next id.
  Unique()
  {
    id = next_id;
    next_id++;
  }

  // returns the id of the object
  int getID()
  {
    return id;
  }

  // Normally the C++ compiler will automatically provide implicitly-declared
  // default copy constructor and copy assignment member functions. So that
  // we can initialize an object like this using  the copy constructor:
  //
  // Unique u1 = u2;
  //
  // and u1 would be assigned u2's id!  We could also use the copy assignment
  // operator like this:
  //
  // u1 = u2;
  //
  // and again u1 would be assigned u2's id.  The problem is that we want our
  // objects to each have a unique id, so supporting either of these operations
  // doesn't make sense given they would cause a bug for our program's logic
  // (though not a compiler error).
  //
  // Here we disable both member functions for the copy constructor and
  // the copy assignment operator using the "= delete;" specifier.  We call
  // the deleted functions now... attempting to use them will cause a compiler
  // error to occur signalling to the developer/writer that they're doing
  // something they shouldnt' be!

  // Make the copy constructor a deleted function.
  Unique(const Unique&) = delete;

  // Make the copy assignmenet operator a deleted function.
  Unique& operator=(const Unique&) = delete;

};

// Initialize the next_id class variable to 1
int Unique::next_id = 1;

int main()
{
  // Create 3 unique objects, each will have a unique id
  Unique unique1;
  Unique unique2;

  // Attempt to use the copy constructor, this will cause a compiler error
  // because it is a deleted function!
  Unique unique3 = unique1;

  // How we should create unique3...
  // Unique unique3;

  // Attempt to use the copy assignment operator, this will also cause a
  // compiler error because it is a deleted function too!
  unique3 = unique1;

  // Output the ids of the Unique objects which we want to be all unique.
  // If we remove the deleted function declarations in our Unique class
  // then our program will compile, but unique3 will not have a unique id,
  // it will have the same id as unique1!  If we also remove the assignment
  // statement above and the initialization of unique3 to unique1, then we'll
  // find all the objects have unique ids as desired.
  cout << "unique1 id: " << unique1.getID() << endl;
  cout << "unique2 id: " << unique2.getID() << endl;
  cout << "unique3 id: " << unique3.getID() << endl;

  return 0;
}
