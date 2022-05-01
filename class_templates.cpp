/*******************************************************************************
*
* Program: Class Templates Demonstration
* 
* Description: Example of using a class template in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=mQqzP9EWu58 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

using namespace std;

// We wish to have a class to represent Arrays and supporting operations, but 
// we would like to avoid defining separate classes for different types like 
// int, string, etc, and different array sizes.  This would lead to a lot of 
// code duplication.  So instead we use a class template.
//
// We use a template prefix with two parameters to define a 'class template'.  
// T is a template parameter that we will use by providing a template argument 
// in order to create a type-specific version of the class Array.  We'll also 
// provide a length int argument to define the length of the array.  These 
// arguments will be provided whenever we attempt to use the class template 
// to create an object instance.
//
// When we define a class template, and then use it by creating object 
// instances, the compiler, at compile time, will create classes by replacing 
// the template parameters with the template arguments provided.  So a class 
// template defines a family of potential classes, and how we use the class 
// template determines which specific classes the compiler will create for 
// usage at runtime.
// 
template <typename T, int length>
class Array
{
public:
  
  // Internally our Array class uses an array to store the array data.
  // public member variable array's type and length will be determined by 
  // the template arguments provided.
  T array[length];
  
  // fills the array with value of a type determined by T
  void fill(T value)
  {
    for (int i = 0; i < length; i++)
      array[i] = value;
  }
  
  // returns a reference to the array element of type T at the given index
  T& at(int index)
  {
    return array[index];
  }
};


int main()
{
  // Because we use Array<int, 5> the compiler will create a class for us 
  // based on the above class template... replacing T with int and length 
  // with 5!  Then at *runtime* the executing program will create an object 
  // instance using this class created by the compiler.
  //
  Array<int, 5> intArr;
  
  // Fill the array with the value 2
  intArr.fill(2);
  
  // If we output the value of the array element at index 2 we will get 4
  cout << "intArray[4]: " << intArr.at(4) << endl;
  

  // Again we use the class template and at copmile-time the compiler will 
  // create a class by replacing T with string and length with 8 in our class 
  // template Array.  Then at runtime the executing program will create an 
  // object instance using this class.
  Array<string, 8> strArr;
  
  // Fill the array with the string "abc"
  strArr.fill("abc");

  // But set the array element at index 6, the 2nd to last, to "123"
  strArr.at(6) = "123";
  
  // Output the array element values, all but the 2nd last array element 
  // should be "abc" except the 2nd last element should be "123"
  for (int i = 0; i < 8; i++)
    cout << "strArr[" << i << "]: " << strArr.at(i) << endl;
  
  
  // Note that because the compiler uses our class template to create specific 
  // classes at compile-time, we can't use class template with something that 
  // isn't a constant expression for the length parameter.  Here we try to use 
  // a variable x that is set at runtime with our class template... but the 
  // compiler can't know what 'x' is going to be, so it's just can't use the 
  // class template to create a class.  If we uncomment below lines we will 
  // see the resulting error.
  //
  // int x;
  // cin >> x;
  // Array<double, x> xArr;
  
  return 0;
}