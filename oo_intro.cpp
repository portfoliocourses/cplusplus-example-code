/*******************************************************************************
*
* Program: Introduction To Classes And Objects
* 
* Description: A basic example intended to introduce classes, objects, and 
* object-oriented programming in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=W1CjYKmTB-c 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

// create a new type of object for representing Bank Accounts
class BankAccount
{

// the public access specifier ensures the below member variables and functions
// are available outside the class
public:
  
  // member variables for the account holder name, account balance
  string name;
  int balance;
  
  // member function for withdrawing an amount from the account
  void withdraw(int amount)
  {
    // we can access and modify member variables from within member functions
    balance = balance - amount;
  }
  
  // member function for printing account information
  void print()
  {
    cout << name << " has " << balance << " dollars " << endl;
  }
};

int main()
{
  // create a BankAccount instance/object, set the member variables
  BankAccount account1;
  account1.name = "Nageeb";
  account1.balance = 3000;
  
  // call the member function
  account1.print();
  
  // create a different BankAccount object... we can create as many  
  // instances of the class as we like!  
  BankAccount account2;
  account2.name = "Kulvinder";
  account2.balance = 1000;
  
  // print the account information before and after a withdrawal 
  account2.print();
  account2.withdraw(100);
  account2.print();

  return 0;
}