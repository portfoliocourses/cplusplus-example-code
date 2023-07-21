/*******************************************************************************
*
* Program: Stack Data Structure In C++ STL
*
* Description: Demonstration of using the stack data structure built-in to the 
* C++ Standard Template Library.  The stack class template in the C++ STL is a 
* container class (specifically a container adapter) which allows us to store 
* collections of data in a Last In First Out (LIFO) order.
*
* Stacks: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
*
* YouTube Lesson: https://www.youtube.com/watch?v=WEwD-ZuTc1w 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

// A very basic class with a constructor, copy constructor, and destructor that
// will ouput to let us know when they have been called.
class Employee
{
public:
  int days;
  
  // Constructor to create an Employee object
  Employee(int days)
  {
    cout << "Constructed called " << days << endl;
    this->days = days;
  }
  
  // Copy constructor to create an Employee object as a copy of another
  Employee(const Employee &employee)
  {
    cout << "Copy constructed called " << employee.days;
    cout << endl;
    this->days = employee.days;
  }
  
  // Destructor called when object is destroyed
  ~Employee()
  {
    cout << "Destructor called " << days << endl;
  }
};

int main()
{
  // Declare a stack called numbers to store int values
  stack<int> numbers;
  
  // Initially the stack will have 0 elements and so the size() method will 
  // return zero
  cout << "size: " << numbers.size() << endl;
  
  // The empty() method returns true if the stack is empty, i.e. if the size
  // is zero, so the below method call will return true
  if (numbers.empty())
  {
    cout << "Stack is empty." << endl;
  }
  
  // Push the value 8 onto the stack
  numbers.push(8);
  
  // Stack size will now be 1...
  cout << "size: " << numbers.size() << endl;

  // The stack will now NOT be empty (i.e. empty() will return false) 
  if (!numbers.empty())
  {
    cout << "Stack is not empty." << endl;
  }

  // The top() method does a "peek" operation, allowing us to retrieve the 
  // element at the top of the stack without removing it from the stack.
  // So the below call to top() will return 8.
  cout << "top: " << numbers.top() << endl;
  
  // Push two more values onto the stack, due to the LIFO behaviour of a 
  // stack, 5 will now be on the top of the stack.
  numbers.push(9);
  numbers.push(5);
  
  // Output the new top (5) and size (3)
  cout << endl;
  cout << "top: " << numbers.top() << endl;
  cout << "size: " << numbers.size() << endl;
  
  // If we're going to pop an element from the stack, we may want to store it 
  // so that we don't lose it.
  int popped_value = numbers.top();
  
  // We can call the pop() method to pop the element at the top of the stack, 
  // note that the method does not return the element, it only removes it from
  // the stack.
  numbers.pop();
  
  // The new stack top will be 9, the new stack size will be 2, and we've stored
  // the old top of the stack (5) into the variable popped_value.
  cout << endl;
  cout << "top: " << numbers.top() << endl;
  cout << "size: " << numbers.size() << endl;
  cout << "popped_value: " << popped_value << endl;
  

  // Declare another stack to store int values
  stack<int> other_stack;
  
  // Push the value 4 onto this other stack
  other_stack.push(4);
  
  // Output the size of the other stack, it will be 1
  cout << "other_stack size: " << other_stack.size();
  cout << endl;
  
  // The swap() method will swap the contents of two stacks
  other_stack.swap(numbers);
  
  // So now other_stack will have a size of 2 and numbers will have a size of
  // 1 because the contents of the stacks were swapped.
  cout << endl;
  cout << "other_stack size: " << other_stack.size();
  cout << endl;
  cout << "numbers size: " << numbers.size() << endl;
  
  // int is a primitive type, but stacks can store objects too like our Employee
  // object, here we declare a stack to store Employee objects
  stack<Employee> employee_stack;
  
  // Create an employee object, notice how the constructor is called
  Employee joe(10);
  
  // When we push the object onto the stack, a copy of the object will be 
  // created, notice how the copy constructor is called.
  employee_stack.push(joe); 

  // When we call the emplace() method, the arguments it is supplied will be 
  // forwarded to a constructor for the object stored by the stack... i.e. 
  // in the below example an Employee object will be constructed using 
  // Employee(20), and then this new object will be pushed onto the stack.
  // In this way, compared to the above example with push(), the copy 
  // constructor is not called, only one object was created and it exists 
  // on the stack.
  employee_stack.emplace(20);
  
  // This will cause a copy constructor call, and a new object will be 
  // created that is a copy of the top element on the stack (the Employee 
  // with days set to 20).
  Employee top_employee = employee_stack.top();

  // When we pop an object from the stack, it's destructor will be called, 
  // notice how the destructor is called in this case. 
  employee_stack.pop();
   
  return 0;
}