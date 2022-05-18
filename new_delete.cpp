/*******************************************************************************
*
* Program: new & delete Operator Examples
* 
* Description: Examples of using the new and delete operators in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wopESdEVJs4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A simple class for representing a student
class Student
{
public:

  // Student objects have a public member variable name
  string name;
  
  // Student objects have a public member function print that prints the 
  // student's name
  void print()
  {
    cout << name << endl;
  }
  
  // Define a constructor that sets the student name member variable based on a 
  // string argument that is provided
  Student(string name) : name(name) {}
};


int main()
{
  // Regular variables in C++ are given space 'on the stack', a place in memory
  // that contains fixed size blocks of data and is 'automatically' managed for 
  // the programmer.  The stack works when we know 'how much data' our program
  // will work with at compile-time when we are writing the program, and we 
  // can simply create the required variables and/or create arrays that are 
  // 'large enough'.
  int x = 4;
  
  // The new operator will allocate space for data in a different portion of 
  // memory called the heap.  Programmers need to manage data on the heap, 
  // free-ing the memory when they are done working with it, making it more 
  // challenging to work with.  But with the heap we can allocate memory for 
  // however much data we need at run-time, as our program is executing.  Here
  // we allocate space for an int on the heap and set the int to 5, the new 
  // operator will return a memory address to this int on the heap which 
  // we store in the ptr_to_int variable.  The ptr_to_int variable is made a 
  // pointer by * and the int preceeding it means that it is a pointer to 
  // an int.
  //
  int *ptr_to_int = new int(5);
  
  // We can use the * operator to 'dereference the pointer', and access the 
  // memory address that the pointer stores... in this case we assign the 
  // value 5 to this space in memory.  We comment it out because we initialized
  // the value to 5 already.
  //
  // *ptr_to_int = 5;
  
  // If we output ptr_to_int we will see it is a memory address, if we 
  // dereference the pointer ptr_to_int we will have the value 5.
  cout << "ptr_to_int: " << ptr_to_int << endl;
  cout << "*ptr_to_int: " << *ptr_to_int << endl;
  
  // If we were to use the new operator again to allocate new space for an 
  // int, and store the memory address into ptr_to_int, we would have a memory
  // leak.  This is because it would no longer be possible to free the memory 
  // on the heap that ptr_to_int was originally pointing to... the memory 
  // address would be "lost" and we would have no copy of it anywhere.  This 
  // means we could no longer make the memory available again to be used 
  // with the delete operator... we call this a "memory leak" because the 
  // memory is "gone" in that we can no longer use it.
  //
  // ptr_to_int = new int(10);
  
  // The delete operator will free the memory on the heap that was allocated
  // by the new operator and make it available to be used by our program again.
  // We use the delete operator when we no longer need the allocated memory.
  delete ptr_to_int;
  

  // We can also allocate space for a block of memory using [], in this case 
  // a block of memory able to store 4 double values.  The block of memory 
  // allocated will be contiguous.  
  double *array = new double[4];
  
  // We can access this block of memory like an array of data... in this case 
  // setting 4 double values...
  array[0] = 5;
  array[1] = 6;
  array[2] = 7;
  array[3] = 8;
  
  // We can print out the dynamically allocated array of data as well...
  for (int i = 0; i < 4; i++)
    cout << "array[" << i << "] = " << array[i] << endl;
  
  // When deleting the block of memory we will need to use [] again as below
  delete[] array;
  

  // We can dynamically allocate space for objects as well, in this case we 
  // store a Student object on the heap.  Notably C++ originated from the C 
  // language that makes available the malloc() and calloc() functions to 
  // dynamically allocate memory, and these functions are available in C++ 
  // as well.  The big difference between using malloc() and calloc() vs 
  // using the new operator is that the new operator will call the constructor 
  // for an object when it allocates space for the object on the heap! 
  Student *student = new Student("Mary");
  
  // We can use the . dot operator to access the member variables and functions
  // of the object on the heap so long as we dereference the pointer to the 
  // object with the * operator.  Notably we need to wrap the *student in 
  // brackets to ensure the dereference operator is applied FIRST before the 
  // . dot operator (due to operator precedence).
  (*student).name = "John";
  (*student).print();
  
  // We can also use the -> arrow operator to access the member variables and 
  // functions of an object on the heap.
  student->name = "Mary";
  student->print();
  
  // We can free the dynamically allocated memory for the student object on 
  // the heap using the delete keyword.  The function free() from the C 
  // language is available in C++ as well, but similarly to how the new operator
  // will call an object's constructor, the delete operator will call the 
  // object's destructor.  
  delete student;
  

  // Dynamic memory allocation can fail, for example if not enough memory is 
  // available or a contiguous block of sufficient size is not available.  We 
  // can detect and handle this situation using a try-catch block.
  try
  {
    // Try allocating far more space than is available, the new operator will 
    // throw a bad_alloc exception in this case...
    double *big_array = new double[99999999999999];
  }
  catch (bad_alloc& exp)
  {
    // catch the exception and output an error message...
    cout << "bad_alloc caught: " << exp.what() << endl;
  }
  
  // If we don't want to use exceptions, we can use "nothrow" as below with the 
  // new operator and instead of throwing an exception new will return NULL if 
  // the dynamic memory allocation fails.
  double *big_again = new(nothrow) double[99999999999999];
  
  // If the memory was not successfully allocated NULL will be assigned to 
  // big_again, so if big_again is NULL we can handle the error (in this case 
  // just outputting an error message).
  if (big_again == NULL)
    cout << "Failed to allocate again!" << endl;
  
  // There is something commonly called the placeholder new operator that allows
  // use to re-use previously allocated memory, and its usage looks like the 
  // below.  This is provided to make the reader aware of this concept, it will 
  // be covered more fully in a future example.  In the below example, the 
  // 2nd double value is created in the same space in memory that was allocated
  // in the 1st statement (the memory address that mydouble stores).
  //
  // double *mydouble = new double(12.2);
  // double *specific = new(mydouble) double(20.5);
  
  return 0;
}

// A visualization of memory...
//
// STACK
// -----
//
//               Memory
// Variable      Address      Value
//
// x             0x0001       4
// ptr_to_int    0x0002       0x9902
//               ...
//               ...
//               ...
// HEAP          ...
// ----          ...
//               0x9901       5
//               0x9902       10
//               0x9903
//