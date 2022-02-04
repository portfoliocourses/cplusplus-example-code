/*******************************************************************************
*
* Program: Class Variable Basics
* 
* Description: Demonstration of how to use class variables (also known as 
* static member variables) in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=2a_8fX0a_NU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

class Animal
{
public:

  // a "regular" member variable, also known as an instance variable
  string species;

  // a *class* member variable, also known as a static member variable, this 
  // variable is "attached" to the class and there is one common total variable
  // for the *class*
  static int total;

  // we can initialize a const class variable in the class definition
  const string planet = "Earth";
  
  // we an increment the class variable as if it were a member variable like 
  // this in the constructor, to recognize another Animal object has been
  // created 
  Animal(string animal_species)
  {
    species = animal_species;
    total++;
  }
  
  // we decrement total when an Animal object is deleted with the destructor
  ~Animal()
  {
    total--;
  }
  
};

// we initialize a non-const class variable outside the class definition using
// the ClassName::variable syntax below
int Animal::total = 0;

int main()
{
  // when we create Animal objects, the constructor will run, incrementing the 
  // class variable total
  Animal *lion = new Animal("lion");
  Animal *tiger = new Animal("tiger");
  
  // the instance member variables are tied to each object instance and may be 
  // difference for each object
  cout << "Lion: " << lion->species << endl;
  cout << "Tiger: " << tiger->species << endl;

  // the class member variable is tied to the class... we can access it with 
  // ClassName::variable syntax
  cout << "Total: " << Animal::total << endl;
  
  // each time we make a new Animal object the total will increase
  Animal *bear = new Animal("bear");
  
  // note that we CAN access the class variable by using an object instance 
  // as below, but the "best practice" is to access it using the class name 
  // as we do above
  cout << "Total: " << tiger->total << endl;
  
  // when we delete an object, the destructor is called, decreasing the total!
  delete lion;
  
  // now the total is only 2
  cout << "Total: " << Animal::total << endl;
  
  // delete the remaining objects
  delete tiger;
  delete bear;

  // now the total is zero (and notice we can access the class variable even 
  // when no objects of the type exist)  
  cout << "Total: " << Animal::total << endl;

  return 0;
}
