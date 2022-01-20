/*******************************************************************************
*
* Program: Public and Private Access Specifiers Demonstration
* 
* Description: Demonstration of the difference between public and private access
* specifiers in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=pnhGOznp0UM  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// define a class Employee
class Employee
{

// public access specifier will make the member variables and functions defined
// below available for access OUTSIDE the class (for example, in the main 
// function below)
public:

  // a public member variable for the employee name
  string name;
  
  // it's typical to define public "getter and setter" functions to manage 
  // access to private member variables such as salary (see below)
  void set_salary(double potential_salary)
  {
    // setter and getter functions may "guard" and "manage" access to the 
    // members, for example in this case applying some error handling 
    // logic before setting the salary.... where if the provided salary 
    // is negative, we default to setting salary to 0
    if (potential_salary < 0) salary = 0;
    else salary = potential_salary;
  }
  
  // a "getter" member function to return the salary
  double get_salary()
  {
    return salary;
  }
  
  // print the employee name and their bonus
  void print_bonus()
  {
    // we can access private member functions such as calculate_bonus within 
    // the class
    cout << name << " bonus: " << calculate_bonus() << endl;
  }
  
// the private access specifiers restricts these member variables and functions
// such that they can only be accessed inside the class, and not by the "outside 
// world" (such as the main function)
private:

  // a private member variable for the employee's salary
  double salary;
  
  // a private member function to calculate the employee's bonus
  double calculate_bonus()
  {
    return salary * 0.10;
  }
  
};

int main()
{
  // create an employee object
  Employee employee1;

  // we can access public member variable name
  employee1.name = "Kevin";
  cout << employee1.name << endl;
  
  // we can access public member functions as well
  employee1.set_salary(50000);
  cout << "salary: " << employee1.get_salary() << endl;
  employee1.print_bonus();

  // if we try to access private members outside the class, we will get a 
  // compiler error as a result
  // employee1.salary = 20000;
  // employee1.calculate_bonus();
  
  return 0;
}