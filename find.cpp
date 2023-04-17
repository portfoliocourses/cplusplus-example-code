/*******************************************************************************
*
* Program: find Function()
* 
* Description: Examples of using the find() function in C++ to find the first 
* occurrence of a value in a range (or the first equal object/value according
* to the equality == operator).
*
* YouTube Lesson: https://www.youtube.com/watch?v=9uy1tBnAAhU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Number
{
public:
  int n;
  
  Number(int n) : n(n) {}
  
  bool operator==(const Number &num)
  {
    return (this->n == num.n);
  }
};

int main()
{  
  vector<int> data = {9,8,7,5,4,3,2};
    
  auto itfound = find(data.begin(), data.end(), 6);
  
  if (itfound == data.end())
  {
    cout << "6 not found in range" << endl;
  }
  else
  {
    cout << *itfound << endl;
    cout << "Index: " << itfound - data.begin() << endl;
  }

  vector<Number> datan = {Number(1), Number(2), Number(3)};
    
  auto itfoundn = find(datan.begin(), datan.end(), Number(2));
  
  cout << (*itfoundn).n << endl;
  
  return 0;
}