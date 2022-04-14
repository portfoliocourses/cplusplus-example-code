/*******************************************************************************
*
* Program: Dynamic Polymorphism example
* 
* Description: Demonstration of how to use the virtual keyword in C++ to 
* implement dynamic polymorphism (i.e. dynamic binding).
*
* YouTube Lesson: https://www.youtube.com/watch?v=-FUhG98hdLI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A basic class for representing students
class Student
{
public:

  // student objects will have a name member variable
  string name;
  
  // a simple constructor to set the name member variable
  Student(string name) : name(name) {}
  
  // we use the virtual keyword when creating the member function, this will 
  // enable dynamic binding of the print member function when it is called, 
  // we can call the print member function a virtual member function
  virtual void print() { cout << name << endl; }
};

// A derived class of the Student class for medical students
class MedicalStudent : public Student
{
public:
  
  // medical students will also have a speciality member variable
  string speciality;
  
  // a constructor to set the name and speciality of the medical student
  MedicalStudent(string name, string speciality) :
    speciality(speciality), Student(name) {};
  
  // we overide the print member function for medical students to also output 
  // the student's speciality, because we've used the virtual keyword in the 
  // Student class when creating the print member function of the base class, 
  // we can expect dynamic binding (see below)
  void print() { cout << name << ": " << speciality << endl; }
};

int main()
{
  // An array of pointers to Student objects dynamically allocated on the heap, 
  // notably the array elements also point to MedicalStudent object instances
  Student *students[] =
  {
    new Student("Kevin"),
    new Student("Mary"),
    new Student("Kulvinder"),
    new MedicalStudent("Ali", "Family Medicine"),
    new MedicalStudent("Harry", "Pediatrics"),
    new MedicalStudent("Lisa", "Radiology")
  };
  
  // We can loop through the array and call the print member function and 
  // exactly *which* print member function (the base class, or derived class) 
  // will actually be resolved at *runtime* depending on the type of object 
  // that students[i] is pointing to.  This is enabled by the virtual keyword
  // used when defining the print member function in the Student class, without 
  // using this keyword we would get *static* binding determined at *compile
  // time* instead, and the print member function of the base class would be 
  // called for all objects regardless of whether the object is a Student 
  // object (base class) or MedicalStudent (derived class).  This ability to 
  // call a different member function depending on the object type at runtime 
  // is called dynamic polymorphism or dynamic binding, and it comes with a 
  // small performance cost as our program must do some work at runtime to 
  // determine which function to call.  It comes with the benefit of code with 
  // more dynamic behaviour, while reducing code duplication as we can store and
  // work with objects of different types in one data structure (e.g. an array).
  for (int i = 0; i < 6; i++)
    students[i]->print();

  // free the dynamically allocated objects
  for (int i = 0; i < 6; i++)
    delete students[i];
  
  return 0;
}