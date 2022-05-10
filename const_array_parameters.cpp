/*******************************************************************************
*
* Program: Constant Array Parameters
* 
* Description: Demonstration of constant array parameters using the const 
* keyword in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=WXnWoRJ7WyU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// Unless we use pointers or references, "by default" in C++ variables will be 
// passed by value.  So when the variable x in the main function is passed to
// this function, all that is really passed is the value of the variable... 10.
// The parameter 'a' will be set to 10, and though we increment it in this 
// function, it will have no effect on the value of x in the main function.
void func(int a)
{
  a = a + 1;
}

// When we pass arrays to functions in C++ what is *really* passed is a pointer,
// i.e. a memory address, to the first element in the array.  So it's not as if 
// a copy of the array is created for the function parameter... the function 
// parameter might have a different name than the array provided as an argument 
// when the function is called, but that parameter will be set to the same 
// memory address as the array used as an argument when calling the function.  
// So "by default" in C++ when we pass an array to a function, we don't have 
// "pass by value" as we do when passing variables, we could call this 
// situation a form of "pass by pointer".  The problem is it may be a serious 
// bug to modify the array in the function.  Perhaps the array should only be 
// analyzed by the function to find a minimum value, or perhaps the array 
// should only be printed by the function.  To prevent this bug from occurring,
// perhaps by future programmers modifying the function, we can use the 'const' 
// keyword with the array parameter.  When we use the const keyword like this 
// the compiler will produce an error if we attempt to modify the array in 
// the function.  Because we've used the const keyword in the below array 
// parameter, we will not be able to modify the array element at index 2.  
// We CAN still access the array elements when using the const keyword 
// however, as we are able to output the array element at index 2.
//
void do_work(const int array[])
{
  // comment out this line and the program will compile without error
  array[2] = 99;
  
  // even when using const, we can still ACCESS array elements, we just can't 
  // MODIFY array elements as we try to with the above statement
  cout << "array[2] = " << array[2] << endl;
}

int main()
{
  // declare and initialize an int variable x
  int x = 10;

  // when we pass x to the function func what is REALLY passed is the value of 
  // the variable x... 10
  func(x);

  // the function func will not actually modify x, x will still be 10 after 
  // calling the function
  cout << "x: " << x << endl;
  
  // declare and initialize an array of ints
  int data[] = {1,2,3,4,5};
  
  // When we pass the data array to the function do_work what is REALLY passed 
  // is the memory address of the first element in the array, allowing the 
  // function to modify the array.  If we take out the const keyword from the 
  // do_work parameter above, the function will be able to set the array 
  // element at index 2 to 99 successfully.
  do_work(data);
  
  // If we output the data array after calling the function, assuming we have 
  // removed the const keyword from the array parameter, we will see that the 
  // array element at index 2 has been set to 99.
  for (int i = 0; i < 5; i++)
    cout << "data[" << i << "] = " << data[i] << endl;
    
  return 0;
}