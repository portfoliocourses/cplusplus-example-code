/*******************************************************************************
*
* Program: swap() Standard Library Function
* 
* Description: Example of using the swap() function in the C++ standard library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=TMVSRaKT3VU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <iostream>

// we can access the swap() function by including utility
#include <utility>

using namespace std;

// A simple class 
class Data
{
public:
  int value;
};

int main()
{
  int a = 2;
  int b = 7;
  
  // output a and b before the swap
  cout << "a: " << a << " b: " << b << endl;
  
  // we can use swap to swap primitive types like int values
  swap(a,b);
  
  // output a and by after the swap
  cout << "a: " << a << " b: " << b << endl;

  
  int x[] = {1,2,3};
  int y[] = {4,5,6};
  
  // output x[] and y[] array values before the swap
  cout << "x[]: " << x[0] << "," << x[1] << "," << x[2] << endl;
  cout << "y[]: " << y[0] << "," << y[1] << "," << y[2] << endl;
  
  // we can also use swap to swap array values
  swap(x,y);
  
  // output x[] and y[] array values after the swap
  cout << "x[]: " << x[0] << "," << x[1] << "," << x[2] << endl;
  cout << "y[]: " << y[0] << "," << y[1] << "," << y[2] << endl;

  
  // create two Data object instances and set the value member variable
  Data dataX, dataY;
  dataX.value = 2;
  dataY.value = 7;
  
  // output the value member variable values of dataX and dataY before the swap
  cout << "X: " << dataX.value << " Y: " << dataY.value << endl;
  
  // swap can also swap object instances
  swap(dataX, dataY);
  
  // output the value member variable values of dataX and dataY after the swap
  cout << "X: " << dataX.value << " Y: " << dataY.value << endl;

  return 0;
}