/*******************************************************************************
*
* Program: Return Multiple Values From A Function
* 
* Description: Examples of techniques to return multiple values from a function
* in C++, including returning a tuple, returning a vector, and using pass by 
* reference.
*
* YouTube Lesson: https://www.youtube.com/watch?v=2ffDUIotwoI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

// Returns multiple values by returning a tuple object that stores multiple
// values.  Tuples can store a fixed number of values of different types.
// Tuples are available in C++11 onwards.
tuple<int,int,string> tupleReturn1(int a, int b)
{
  // Creates and returns a tuple object
  return make_tuple(a + b, a - b, "returned string");
}

// The same as the above function except we use { } syntax to create the tuple,
// available in C++17 onwards.
tuple<int,int,string> tupleReturn2(int a, int b)
{
  return {a + b, a - b, "returned string"};
}

// If we want to return an unknown number of values of the same type we could 
// return a vector, here we return a vector with 3 ints but we could have put
// any number of int values into the vector.
vector<int> vectorReturn()
{
  vector<int> numbers;
  
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  
  return numbers;
}

// Effectively "returns" two values by using reference variable parameters.
// The reference variables sum and diff will be aliases for whatever variables
// we pass to the function in the calling function, and so if we modify the 
// value these variables store we will modify the values of the variables in
// the calling function.  In this way we can return multiple values.  Note 
// that the void function type means the function does not officially return
// a value in the conventional way.
void passByReference(int a, int b, int &sum, int &diff)
{
  sum = a + b;
  diff = a - b;
}

int main()
{
  // test variables for function arguments
  int x = 10;
  int y = 4;
  
  // Test tupleReturn1()

  // Store "return values" in the tuple that tupleReturn1() returns
  int total1;
  int difference1;
  string retstr1;

  // tie() is used to "unpack" the tuple and we'll store the 3 values returned 
  // into total1, difference1, and retstr1.  This technique to unpack the tuple 
  // will work in C++11 onwards.
  tie(total1, difference1, retstr1) = tupleReturn1(x, y);
  
  // Output the returned values
  cout << "Total: " << total1 << endl;
  cout << "Difference: " << difference1 << endl;
  cout << "Returned String: " << retstr1 << endl;


  // Test tupleReturn2()

  // In C++17 onwards we can use structured bindings to unpack the tuple, this
  // time storing the values returned in the tuple into total2, difference2
  // and retstr2.  When using 'auto' the C++ compiler will determine the right
  // type to use for these variables.
  auto [total2, difference2, retstr2] = tupleReturn2(x, y);
  
  // Output the returned values
  cout << "Total: " << total2 << endl;
  cout << "Difference: " << difference2 << endl;
  cout << "Returned String: " << retstr2 << endl;
  
  
  // Test vectorReturn()

  // Store the vector of ints returned by the function into returnedVector()
  vector<int> returnedVector = vectorReturn();
  
  // Output each into value returned as part of the vector
  for (int value : returnedVector)
  {
    cout << value << endl;
  }


  // Test passByReference()

  // Store the "return values" of passByReference() 
  int total3;
  int difference3;

  // When we call passByReference() the last two parameters are reference 
  // variables, so because we pass in total3 and difference3 the function
  // is given "direct access" to total3 and difference3 in main() and can 
  // set them to whatever it wants... allowing it to essentially "return"
  // multiple values.
  passByReference(x,y,total3,difference3);
  
  // Output the resulting total and difference
  cout << "Total: " << total3 << endl;
  cout << "Difference: " << difference3 << endl;

  return 0;
}