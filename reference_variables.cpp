/*******************************************************************************
*
* Program: Reference Variables Examples
* 
* Description: Examples of using reference variables in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=e3DN1RaYVYQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// When we use a reference variable as a parameter we call it pass-by-reference,
// and we can change the value of the variable in the calling environment that 
// was passed as an argument... this is in contrast to pass-by-value where the 
// value of the variable would normally be provided to the function.
void increment(int &x)
{
  x++;
}

// we can return a reference from a function, in this case we return a reference
// to the largest int in the array with the given length
int &max(int array[], int length)
{
  // assume the largest element in the array as it as the first index to start
  int max_index = 0;

  // loop through the array elements, whenever we find one larger than the 
  // current max, update the current max (kept track of by using max_index to 
  // keep track of the INDEX where the current max is located)
  for (int i = 1; i < length; i++)
    if (array[i] > array[max_index]) max_index = i;
  
  // return a reference to the largest element in the array
  return array[max_index];
}

// a simple function to triple an int and return it
int func(int x)
{
  return 3 * x;
}

// we can create a reference to a function... in this case triple is declared
// as a refernece to a function that accepts an int argument and returns an int,
// and we initialize it to func
int (&triple)(int) = func;

int main()
{
  // create a regular int variable a, initialize it to 5
  int a = 5;

  // Declare a reference variable b using &, initialize it to a, note that 
  // reference variables MUST be initialized, we cannot initialize them to 
  // NULL either (unlike pointers).  The variable b becomes a synonym for a at
  // this point.
  int &b = a;
  
  // when we modify a, we modify b, and when we modify b, we modify a, as they 
  // are now effectively the same variable
  b++;
  a++;
  
  // note that both a and b have been incremented...
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  
  int c = 20;
  
  // we cannot re-assign a reference variable... if we try to do this we'll 
  // actually be assinging the value '20' to reference variable b (and by 
  // virtue of the fact that b is a reference varialbe for a, we'll be 
  // setting a to 20!)
  b = c;
  
  // verify that both b and a are now set to 20
  cout << "b: " << b << endl;
  cout << "a: " << a << endl;
  
  // declare and initialize an array
  int array[] = {1,2,3,4,5};
  
  // we can assign an array element to a reference variable too
  int &ref = array[2];
  
  // when we add 10 to ref, we'll be adding 10 to array[2]
  ref += 10;
  
  // notice how array[2] is now set to 13!
  for (int i = 0; i < 5; i++)
    cout << "array[" << i << "] = " << array[i] << endl;
  
  // declare a variable m and initialize it to 4
  int m = 4;
  
  // when we call increment which is using pass-by-reference for its parameter,
  // we'll actually modify m in the main function, as opposed to pass-by-value
  // where only the value of m would be passed to the function
  increment(m);
  
  // m will now be 5
  cout << "m: " << m << endl;
  
  // max will return a reference to the largest element in the array that we 
  // assign to reference variable max_val
  int &max_val = max(array, 5);
  
  // output max_val (which should be 13)
  cout << "max_val: " << max_val << endl;
  
  // when we increment max_val by 1 this will also effect the array element
  max_val++;
  
  // notice array[2] (the largest element in the array) has now been incremented
  // by 1
  for (int i = 0; i < 5; i++)
    cout << "array[" << i << "] = " << array[i] << endl;
  
  // we can call func regularly
  cout << func(5) << endl;

  // or we can call it using reference triple which is a reference to func
  cout << triple(5) << endl;
  
  return 0;
}
