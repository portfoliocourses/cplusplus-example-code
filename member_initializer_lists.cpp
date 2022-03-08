/*******************************************************************************
*
* Program: Member Initializer List Examples
* 
* Description: Examples of how, why, and when to use member initializer lists 
* in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=X1dGUSVnavQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// A class with a default constructor AND parametrized constructor 
class Major
{
public:
  string name;
  
  // we initialize member variable name to the value "Undeclared"
  Major() : name("Undeclared")
  {
    // we can still put code in the instructor that will run after the members 
    // are initialized, to do other work a constructor may need to do
    cout << "Major Constructor (Undeclared)" << endl;
  } 
  
  // init member variable name to the value of the parameter name
  Major(string name) : name(name)
  {
    cout << "Major Constructor (" << name << ")" << endl;
  }
};

// A class with NO default constructor
class Minor
{
public:
  string name;
  
  // init member variable name to the value of the parameter name
  Minor(string name) : name(name) {}
};

class Student
{
public:
  string name;
  int start_year;
  int grad_year;

  // We can initialize a const member variable like this, but it will take 
  // on the same vaue for every object instance
  // const string id = "abc";
  
  // If we wish to provide potentially different values for the const member 
  // variables of objects, we need to use member initializer lists as below!
  const string id;

  // If a class has a default constructor AND a parameterized constructor, then
  // BOTH the default constructor AND the parameterized constructor will be 
  // called to create objects *if* in addition to the below declaration of 
  // the member variable major we also initialized it in the constructor
  // body with something like:
  //
  // Major major("something");
  //
  // ONLY if we initialize the object in a member initializer list can we 
  // prevent this from happening and only create the object once.  This is 
  // important for performance reasons, as otherwise we are calling two 
  // constructors when only one is needed!
  Major major;

  // We must use member initializer lists to initialize reference member 
  // variables like &minor1
  Minor &minor1;

  // If an object member variable only has a parametrized constructor, then 
  // we must also initialize the member variable using a member initializer 
  // list.
  Minor minor2;
  
  Student(string name, long int start_year, string major,
          Minor &minor) :
    // We can use { } in addition to ( ) in member initializer lists, the 
    // difference is that { } will detect type narrowing errors... e.g. if we 
    // uncomment the { } version of start_year's initialization and comment out
    // the ( ) version of start_year's initialization we will get an error as 
    // int (start_year member variable's type) is a narrower type able to 
    // represent fewer numbers than long int (start_year parameter's type).
    name{name},
//    start_year{start_year},
    start_year(start_year),
    grad_year(start_year + 4),
    id(name.append(to_string(start_year))),
    major(Major(major)),
    minor1(minor),
    minor2(Minor("Physics"))
  {
    cout << "Student Object Constructed!" << endl;
  }
};

// When a derived class has a base class with no default constructor, we need 
// to use a member initializer list to use the base class constructor
class MatureStudent : Student
{
public:
  int age;
  
  // We use the member initializer list to use Student's constructor...
  MatureStudent(int age, string name,
                long int start_year, string major,
                Minor &minor) :
   Student(name, start_year, major, minor),
   age(age) {}
};

int main()
{
  // Test out making a student object, as the code is written now this long int
  // value should not cause a compiler error (though the int value for the start
  // and grad year's will be incorrect due to a type narrowing issue).  
  //
  // Everything else should work as expected!
  //
  long int year = 999999999999;
  Minor minor("Economics");
  Student s1("John", year, "Computer Science", minor);
  
  cout << "Name: " << s1.name << endl
       << "Start Year: " << s1.start_year << endl
       << "Grad Year: " << s1.grad_year << endl
       << "ID: " << s1.id << endl
       << "Major: " << s1.major.name << endl
       << "Minor1: " << s1.minor1.name << endl
       << "Minor2: " << s1.minor2.name << endl;

  return 0;
}