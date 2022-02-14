/*******************************************************************************
*
* Program: Pass By Reference
* 
* Description: Demonstration of how to use pass by reference in C++.  Pass by
* reference allows a function to modify arguments it is provided in the calling
* function, in contrast to pass by value.
*
* YouTube Lesson: https://www.youtube.com/watch?v=cxysUPZH65Y 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A simple object to keep a running count
class Counter
{

// a single private member variable count to keep track of the running count
private:
  int count;

public:

  // initialize the count to 0
  Counter()
  {
    count = 0;
  }
  
  // output the count
  void print()
  {
    cout << "count: " << count << endl;
  }
  
  // increment the count by 1
  void increment()
  {
    count++;
  }
  
};

// Uses pass by reference to modify the counter object in the calling function
// by incrementing it 3 times.  If we did not use & for pass by reference, the 
// object in the calling function would not be modified.  Instead a "shallow 
// copy" of the object would be provided to a function (like a duplicate of the
// object, with member variable values copied).  A shallow copy of the object 
// could potentially be dangerous (or at least, error prone) if the object is 
// using data on the heap (i.e. dynamically allocated variables).
void increment_3x(Counter &counter) 
{
  counter.increment();
  counter.increment();
  counter.increment();
}

// Uses pass by reference to increment x by 1, i.e. whatever variable is passed 
// to increment in the calling function.
void increment(int& x)
{
  x++;
  cout << "x after increment: " << x << endl;
}

// Pass by reference importantly allows us to modify two variables at once 
// in the calling environment, unlike pass by value where we are typically 
// returning a single value that is assigned to a single variable in the calling
// function.
void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

int main()
{
  int a = 4;
  
  // because increment uses pass by reference, 'a' wil be incremented by 1!
  cout << "a before: " << a << endl;
  increment(a);
  cout << "a after: " << a << endl;
  
  int b = 4;
  int c = 8;

  // we can swap b and c, effectively altering TWO variables at once in the 
  // calling function!
  cout << "BEFORE b: " << b << ", c: " << c << endl;
  swap(b,c);
  cout << "AFTER b: " << b << ", c: " << c << endl;
  
  
  Counter counter;
  
  // pass by reference will also work with objects, such as the counter object
  counter.print();
  increment_3x(counter);
  counter.print();
  
  return 0;
}