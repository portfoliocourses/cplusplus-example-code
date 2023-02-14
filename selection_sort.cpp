/*******************************************************************************
*
* Program: Selection Sort
* 
* Description: Example of selection sort algorithm implemented in C++.  See the 
* wikipedia article: https://en.wikipedia.org/wiki/Selection_sort
*
* YouTube Lesson: https://www.youtube.com/watch?v=Q-NXg6Tzyks 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

void selection_sort(int a[], int length);

int main()
{
  // A test array and array length
  int a[] = {6, 3, 2, 4, 1, 5};
  int length = 6;
  
  // Call the function to perform the selection sort algorithm
  selection_sort(a, length);
  
  // Print out the array so we can be sure it is sorted correctly
  for (int i = 0; i < length; i++)
  {
    cout << "a[" << i << "] = " << a[i] << endl;
  }
  
  return 0;
}

// Sorts array a with the provided length using the selection sort algorithm.
void selection_sort(int a[], int length)
{
  // Loop through each index of the array, as we do so the elements < i are 
  // considered the sorted portion of the array, and the elements >= i are 
  // considered the unsorted portion of the array.  The algorithm repeatedly 
  // finds the minimum element in the unsorted portion of the array and if 
  // necessary swaps it with the element at index i, increasing the portion 
  // of the sorted array with each iteration.    
  for (int i = 0; i < (length - 1); i++)
  {
    // find the position of the minimum element in the unsorted portion of 
    // the array    
    int min_pos = i;
    for (int j = i + 1; j < length; j++)
    {
      if (a[j] < a[min_pos])
      {
        min_pos = j;
      }
    }
    
    // if that element is NOT the element at index i, then swap that element 
    // with the element at index i    
    if (min_pos != i)
    {
      int temp = a[i];
      a[i] = a[min_pos];
      a[min_pos] = temp;
    }
  }
}