/*******************************************************************************
*
* Program: Constructor Basics
* 
* Description: Demonstrates the basics of using constructor functions in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=bnyveJ17lao 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// object type for representing cats
class Cat
{

// cats will have a name, color and favorite toy
private:
  string name;
  string color;
  string favorite_toy;
  
public:
  
  // member function for printing out a cat's information
  void print_cat()
  {
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Favourite Toy: " << favorite_toy << endl;
  }
  
  // constructor with no parameters, we initialize member variables to defaults
  Cat()
  {
    name = "Unknown";
    color = "Unknown";
    favorite_toy = "Unknown";
  }
  
  // constructor with a single parameter, we use it to intitialize the cat name
  Cat(string n)
  {
    name = n;
    color = "Unknown";
    favorite_toy = "Uknown";
  }
  
  // constructor parameters can have default values such as the default favorite 
  // toy value "Laser Pointer", we can also define constructors outside the 
  // Class such as this example, as long as we leave function declaration 
  // (i.e. prototype) in the class
  Cat(string n, string c, string ft = "Laser Pointer");
  
};

// we use the syntax ClassName::ClassName( ... ) to define the constructor 
// outside the class...
Cat::Cat(string n, string c, string ft)
{
  name = n;
  color = c;
  favorite_toy = ft;
}


int main()
{
  // the constructor with no parameters will be called
  Cat cat1;
  
  cout << "Cat 1..." << endl;
  cat1.print_cat();
  cout << endl;
  
  
  // the constructor that accepts a single argument will be called
  Cat cat2("Spot");
  
  cout << "Cat 2..." << endl;
  cat2.print_cat();
  cout << endl;
  

  // the constructor that accepts 3 arguments will be called, but the default 
  // value will be used for the 3rd argument
  Cat cat3("Garfield", "Orange");
  
  cout << "Cat 3..." << endl;
  cat3.print_cat();
  cout << endl;
  
  return 0;
}